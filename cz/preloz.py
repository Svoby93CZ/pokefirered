#!/usr/bin/env python3
"""Vymění texty _("...") v C souboru podle názvu proměnné a změří jejich šířku.

Spouštěj z kořene repozitáře:
    python3 cz/preloz.py src/strings.c <<'EOF'
    gText_MenuBag = BATOH
    gText_MenuSave = ULOŽIT
    EOF
Bez vstupu (python3 cz/preloz.py src/strings.c < /dev/null) jen nic nezmění.
Výpis: šířka nejdelšího řádku v px (normální font) původní -> nová;
'!' = nový text je širší než původní, ověř okno; '!!' = širší než dialogové okno.
"""
import re
import sys
from pathlib import Path

DIALOG_PX = 196  # nejširší anglický řádek v dialozích (okno 208 px, vpravo šipka)
ZASTUPCI = {"PLAYER": 42, "RIVAL": 42}  # ostatní {STR_VAR_x} apod. počítá jako 60 px


def nacti_charmap():
    znaky, kody = {}, {}
    for radek in Path("charmap.txt").read_text(encoding="utf-8").splitlines():
        radek = radek.split("@")[0].strip()
        m = re.match(r"^'(.+)'\s*=\s*([0-9A-F]{2})$", radek)
        if m:
            znaky.setdefault(m.group(1).replace("\\'", "'"), int(m.group(2), 16))
        m = re.match(r"^(\w+)\s*=\s*([0-9A-F ]+)$", radek)
        if m:
            kody.setdefault(m.group(1), [int(b, 16) for b in m.group(2).split()])
    return znaky, kody


def nacti_sirky():
    text_c = Path("src/text.c").read_text(encoding="utf-8")
    m = re.search(r"sFontNormalLatinGlyphWidths\[\]\s*=\s*\{(.*?)\};", text_c, re.S)
    return [int(x) for x in re.findall(r"\d+", m.group(1))]


ZNAKY, KODY = nacti_charmap()
SIRKY = nacti_sirky()


def sirka_kodu(nazev):
    nazev = nazev.split()[0]
    if nazev in ZASTUPCI:
        return ZASTUPCI[nazev]
    bajty = KODY.get(nazev, [])
    if not bajty or bajty[0] in (0xFC, 0xFE):  # barvy, pauzy, zvuky, písmo
        return 0
    if bajty[0] in (0xF7, 0xFD):  # STR_VAR_1, DYNAMIC, ...
        return 60
    if bajty[0] in (0xF8, 0xF9):  # ikony tlačítek, Lv, PP, No
        return 10
    return sum(SIRKY[b] for b in bajty)


def radky(text):
    """Šířky řádků v px; neznámý znak skončí chybou."""
    vysledek = []
    for radek in re.split(r"\\[nlp]", text):
        px = 0
        for kus in re.findall(r"\{[^}]*\}|.", radek):
            if kus.startswith("{"):
                px += sirka_kodu(kus[1:-1])
            elif kus in ZNAKY:
                px += SIRKY[ZNAKY[kus]]
            else:
                raise SystemExit(f"Znak {kus!r} není v charmap.txt ({text})")
        vysledek.append(px)
    return vysledek


def main():
    soubor = Path(sys.argv[1])
    zdroj = soubor.read_text(encoding="utf-8")
    for radek in sys.stdin.read().splitlines():
        if not radek.strip() or radek.startswith("#"):
            continue
        nazev, novy = radek.split(" = ", 1)  # mezeru na konci textu nechat
        nazev = nazev.strip()
        vzor = re.compile(r"(\b" + re.escape(nazev) + r'\[\]\s*=\s*_\(")(.*?)("\);)')
        nalezy = vzor.findall(zdroj)
        if len(nalezy) != 1:
            raise SystemExit(f"{nazev}: nalezeno {len(nalezy)}×, nic nezapsáno")
        stary = nalezy[0][1]
        s, n = max(radky(stary)), max(radky(novy))
        znacka = "!!" if n > DIALOG_PX else "!" if n > s else ""
        print(f"{znacka:2} {s:3} -> {n:3}  {nazev}: {novy}")
        zdroj = vzor.sub(lambda m: m.group(1) + novy + m.group(3), zdroj)
    soubor.write_text(zdroj, encoding="utf-8")


if __name__ == "__main__":
    main()
