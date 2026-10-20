#!/usr/bin/env python3
"""Dokreslí česká písmena do latinkových fontů a nastaví jejich šířky v src/text.c.

Spouštěj z kořene repozitáře:  python3 cz/ceske_znaky.py
Kreslí do prázdných slotů (kódy bere z charmap.txt), původní znaky nemění.
Jde pouštět opakovaně – vždy skládá znovu ze základních písmen.
Vzhled diakritiky se ladí ve vzorech níže: '#' tmavá, 'o' stín, '+' bílá, '.' nechat.
"""
import re
from pathlib import Path

from PIL import Image

BARVY = {"#": 1, "o": 2, "+": 3}

ZNACKY = {
    "normal": {
        "hacek": [".#o#o", ".o#o."],
        "hacek4": ["#o#o", "o#o."],   # pro úzká písmena (n, r, s)
        "carka": ["..##o", ".#oo."],  # stejná jako u Á
        "krouzek": ["..#o", ".#+#o", "..#o"],
        "apostrof": ["#o", "#o"],
    },
    "small": {
        "hacek": ["#o#o", "o#o."],
        "hacek4": ["#o#o", "o#o."],
        "carka": ["..#o", ".#o."],
        "krouzek": [".#o", "#+#o", ".#o"],
        "apostrof": ["#o", "#o"],
    },
}

# znak: (základ, značka, (x, y) v normálním fontu, (x, y) v malém fontu, šířka navíc)
PISMENA = {
    "Č": ("C", "hacek", (0, 0), (0, 1), 0),
    "Ď": ("D", "hacek", (0, 0), (0, 1), 0),
    "Ě": ("E", "hacek", (0, 0), (0, 1), 0),
    "Ň": ("N", "hacek", (0, 0), (0, 1), 0),
    "Ř": ("R", "hacek", (0, 0), (0, 1), 0),
    "Š": ("S", "hacek", (0, 0), (0, 1), 0),
    "Ť": ("T", "hacek", (0, 0), (0, 1), 0),
    "Ů": ("U", "krouzek", (0, 0), (0, 1), 0),
    "Ý": ("Y", "carka", (0, 0), (0, 1), 0),
    "Ž": ("Z", "hacek", (0, 0), (0, 1), 0),
    "č": ("c", "hacek", (0, 3), (0, 3), 0),
    "ď": ("d", "apostrof", (6, 3), (5, 3), 2),
    "ě": ("e", "hacek", (0, 3), (0, 3), 0),
    "ň": ("n", "hacek4", (0, 3), (0, 3), 0),
    "ř": ("r", "hacek4", (0, 3), (0, 3), 0),
    "š": ("s", "hacek4", (0, 3), (0, 3), 0),
    "ť": ("t", "apostrof", (3, 3), (3, 3), 0),
    "ů": ("u", "krouzek", (0, 2), (0, 2), 0),
    "ý": ("y", "carka", (0, 3), (0, 3), 0),
    "ž": ("z", "hacek", (0, 3), (0, 3), 0),
}

FONTY = {  # png: (druh, šířka buňky, tabulky šířek v src/text.c)
    "latin_normal": ("normal", 16, ["sFontNormalLatinGlyphWidths", "sFontNormalCopy1LatinGlyphWidths"]),
    "latin_male": ("normal", 16, ["sFontMaleLatinGlyphWidths"]),
    "latin_female": ("normal", 16, ["sFontFemaleLatinGlyphWidths"]),
    "latin_small": ("small", 8, ["sFontSmallLatinGlyphWidths"]),
}


def nacti_charmap(cesta):
    kody = {}
    for m in re.finditer(r"^'(.)'\s*=\s*([0-9A-F]{2})\b", cesta.read_text(encoding="utf-8"), re.M):
        kody.setdefault(m.group(1), int(m.group(2), 16))
    return kody


def bunka(kod, sirka):
    na_radek = 256 // sirka
    return (kod % na_radek) * sirka, (kod // na_radek) * 16


def main():
    koren = Path.cwd()
    kody = nacti_charmap(koren / "charmap.txt")
    chybi = [z for z in PISMENA if z not in kody]
    if chybi:
        raise SystemExit(f"V charmap.txt chybí: {' '.join(chybi)}")

    text_c = koren / "src" / "text.c"
    zdroj = text_c.read_text(encoding="utf-8")

    for font, (druh, sirka, tabulky) in FONTY.items():
        png = koren / "graphics" / "fonts" / f"{font}.png"
        obr = Image.open(png)
        sirky = tabulky_sirek(zdroj, tabulky[0])

        for znak, (zaklad, znacka, poz_n, poz_s, navic) in PISMENA.items():
            zx, zy = bunka(kody[zaklad], sirka)
            cx, cy = bunka(kody[znak], sirka)
            obr.paste(obr.crop((zx, zy, zx + sirka, zy + 16)), (cx, cy))

            w = sirky[kody[zaklad]]
            for y in range(16):  # rozšířit bílý podklad o sloupce navíc
                if obr.getpixel((cx + w - 1, cy + y)) != 0:
                    for x in range(w, w + navic):
                        obr.putpixel((cx + x, cy + y), BARVY["+"])

            x0, y0 = poz_n if druh == "normal" else poz_s
            for dy, radek in enumerate(ZNACKY[druh][znacka]):
                for dx, c in enumerate(radek):
                    if c != ".":
                        obr.putpixel((cx + x0 + dx, cy + y0 + dy), BARVY[c])

            for tab in tabulky:
                zdroj = nastav_sirku(zdroj, tab, kody[znak], tabulky_sirek(zdroj, tab)[kody[zaklad]] + navic)

        obr.save(png)
        print(f"{font}: {len(PISMENA)} znaků")

    text_c.write_text(zdroj, encoding="utf-8")
    print("Šířky zapsány do src/text.c")


def telo_tabulky(zdroj, nazev):
    m = re.search(re.escape(nazev) + r"\[\]\s*=\s*\{(.*?)\};", zdroj, re.S)
    if not m:
        raise SystemExit(f"Tabulka {nazev} nenalezena v src/text.c")
    return m.start(1), list(re.finditer(r"\d+", m.group(1)))


def tabulky_sirek(zdroj, nazev):
    return [int(c.group()) for c in telo_tabulky(zdroj, nazev)[1]]


def nastav_sirku(zdroj, nazev, kod, hodnota):
    zacatek, cisla = telo_tabulky(zdroj, nazev)
    c = cisla[kod]
    return zdroj[:zacatek + c.start()] + str(hodnota) + zdroj[zacatek + c.end():]


if __name__ == "__main__":
    main()
