#!/usr/bin/env python3
"""Náhled glyfů z latinkových fontů pokefirered pro český překlad.

Spouštěj z kořene repozitáře:  python3 cz/nahled_fontu.py
Výstup: cz/nahled_fontu.png + výpis kódů a šířek v terminálu.
Nic v repozitáři nemění, jen čte.
"""
import re
import sys
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont

BUNKA = 16       # výška glyfu; šířka 16 px (latin_small 8 px), 256 px na řádek
ZVETSENI = 4
MEZERA = 10

FONTY = {
    "latin_normal": "sFontNormalLatinGlyphWidths",
    "latin_male": "sFontMaleLatinGlyphWidths",
    "latin_female": "sFontFemaleLatinGlyphWidths",
    "latin_small": "sFontSmallLatinGlyphWidths",
}

# Řádky náhledu: základní písmena, vzory diakritiky a nová česká písmena
RADKY = [
    ("základ", "CENUYRSTZD"),
    ("základ", "cenuyrstzd"),
    ("vzory", "ÁÉÍÓÚáéíóú'º"),
    ("čeština", "ČĚŇŮÝŘŠŤŽĎ"),
    ("čeština", "čěňůýřšťžď"),
]
VETA = "PŘÍLIŠ ŽLUŤOUČKÝ KŮŇ ÚPĚL ĎÁBELSKÉ ÓDY. Příliš žluťoučký kůň úpěl ďábelské ódy."


def nacti_charmap(cesta):
    kody = {}
    vzor = re.compile(r"^'(.+?)'\s*=\s*([0-9A-Fa-f]{2})\b")
    for radek in cesta.read_text(encoding="utf-8").splitlines():
        m = vzor.match(radek)
        if m and m.group(1) not in kody:
            znak = m.group(1).replace("\\'", "'")
            kody.setdefault(znak, int(m.group(2), 16))
    return kody


def nacti_sirky(text_c, nazev):
    """Vytáhne pole šířek z src/text.c, při neúspěchu vrátí None."""
    m = re.search(re.escape(nazev) + r"\[\]\s*=\s*\{(.*?)\};", text_c, re.S)
    if not m:
        return None
    telo = re.sub(r"/\*.*?\*/", "", m.group(1), flags=re.S)
    telo = re.sub(r"//[^\n]*", "", telo)
    return [int(x, 0) for x in re.findall(r"0x[0-9A-Fa-f]+|\d+", telo)]


def pismo(velikost):
    for cesta in ("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
                  "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf"):
        if Path(cesta).exists():
            return ImageFont.truetype(cesta, velikost)
    return ImageFont.load_default()


def main():
    koren = Path.cwd()
    charmap = koren / "charmap.txt"
    if not charmap.exists():
        sys.exit("Spusť skript z kořene repozitáře pokefirered (chybí charmap.txt).")

    kody = nacti_charmap(charmap)
    text_c = (koren / "src" / "text.c").read_text(encoding="utf-8", errors="replace")

    pis_maly, pis_velky = pismo(13), pismo(18)
    sl = BUNKA * ZVETSENI
    nejdelsi = max(len(z) for _, z in RADKY)
    sirka = 90 + nejdelsi * (sl + MEZERA)
    vyska_radku = sl + 22
    vyska_vety = BUNKA * 2 + 8
    vyska_fontu = 34 + len(RADKY) * vyska_radku + vyska_vety + 16
    nahled = Image.new("RGB", (sirka, vyska_fontu * len(FONTY)), "white")
    kresli = ImageDraw.Draw(nahled)

    y0 = 0
    for font, pole in FONTY.items():
        png = koren / "graphics" / "fonts" / f"{font}.png"
        obr = Image.open(png).convert("RGB")
        bw = 8 if font == "latin_small" else BUNKA
        na_radek = obr.width // bw
        sirky = nacti_sirky(text_c, pole)
        kresli.text((8, y0 + 6), f"{font}  ({obr.width}x{obr.height})",
                    fill="black", font=pis_velky)
        print(f"\n== {font} ({obr.width}x{obr.height}), šířky: "
              f"{'OK' if sirky else 'nenalezeny'}")

        for i, (popis, znaky) in enumerate(RADKY):
            y = y0 + 34 + i * vyska_radku
            kresli.text((8, y + 26), popis, fill="gray", font=pis_maly)
            vypis = []
            for j, znak in enumerate(znaky):
                x = 90 + j * (sl + MEZERA)
                kod = kody.get(znak)
                if kod is None:
                    kresli.text((x, y), f"{znak} ??", fill="red", font=pis_maly)
                    vypis.append(f"{znak}=??")
                    continue
                gx, gy = (kod % na_radek) * bw, (kod // na_radek) * BUNKA
                if gy + BUNKA > obr.height:
                    kresli.text((x, y), f"{znak} mimo", fill="red", font=pis_maly)
                    vypis.append(f"{znak}=mimo")
                    continue
                w = sirky[kod] if sirky and kod < len(sirky) else None
                stitek = f"{znak} {kod:02X}" + (f" w{w}" if w is not None else "")
                kresli.text((x, y), stitek, fill="black", font=pis_maly)
                bunka = obr.crop((gx, gy, gx + bw, gy + BUNKA))
                nahled.paste(bunka.resize((bw * ZVETSENI, sl), Image.NEAREST), (x, y + 18))
                kresli.rectangle((x - 1, y + 17, x + sl, y + 18 + sl), outline="#c33")
                vypis.append(f"{znak}={kod:02X}" + (f"/w{w}" if w is not None else ""))
            print(f"  {popis:7} " + "  ".join(vypis))

        # ukázková věta sázená po glyfech podle šířek ze hry (2× zvětšeno)
        veta = Image.new("RGB", (sum(sirky[kody.get(z, 0)] for z in VETA), BUNKA), "white")
        x = 0
        for z in VETA:
            kod = kody.get(z, 0)
            gx, gy = (kod % na_radek) * bw, (kod // na_radek) * BUNKA
            veta.paste(obr.crop((gx, gy, gx + sirky[kod], gy + BUNKA)), (x, 0))
            x += sirky[kod]
        veta = veta.resize((veta.width * 2, veta.height * 2), Image.NEAREST)
        nahled.paste(veta.crop((0, 0, min(veta.width, sirka - 16), veta.height)),
                     (8, y0 + 34 + len(RADKY) * vyska_radku))
        y0 += vyska_fontu

    vystup = koren / "cz" / "nahled_fontu.png"
    vystup.parent.mkdir(exist_ok=True)
    nahled.save(vystup)
    print(f"\nNáhled uložen: {vystup}")


if __name__ == "__main__":
    main()
