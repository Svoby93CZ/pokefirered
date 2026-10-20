# Čeština pro Pokémon FireRed — plán

Každá část = jeden commit na větvi `cestina`. Hotové části odškrtávej.

- [x] **0. Font a nástroje**: česká písmena v prázdných slotech 0x37–0x4A
  (`cz/ceske_znaky.py`), náhled (`cz/nahled_fontu.py`), překládací nástroj (`cz/preloz.py`).
- [ ] **1. Menu a rozhraní**: `src/strings.c` a drobnosti v `src/*.c`
  (hlavní a start menu, batoh, PC, obchod, tým, učení útoků, Pokédex).
- [ ] **2. Souboje**: `src/battle_message.c` a další texty bojů.
- [ ] **3. Společné hlášky**: `data/text/*.inc` (úvod hry, ukládání, PC, obchod, školka, Safari…),
  kromě nápovědy a Fame Checkeru.
- [ ] **4. Příběh**: `data/maps/*/text.inc`, po oblastech:
  - [ ] 4a Pallet, Viridian, Pewter, Route 1–3, Viridian Forest
  - [ ] 4b Mt. Moon, Cerulean, Vermilion, S.S. Anne, Route 4–11
  - [ ] 4c Rock Tunnel, Lavender, Celadon, Rocket Hideout, Pokémon Tower
  - [ ] 4d Saffron, Silph Co., Fuchsia, Safari Zone, Cinnabar
  - [ ] 4e Victory Road, Indigo Plateau, zbylé cesty
  - [ ] 4f Sevii Islands
- [ ] **5. Popisy**: útoky, předměty, Pokédex, bobule.
- [ ] **6. Nápověda a Fame Checker**: `help_system.inc`, `fame_checker.inc`.
- [ ] **7. Ostatní**: klávesnice pro jména s češtinou, Trainer Tower, Union Room, Wireless.

## Pravidla

- **Anglicky zůstávají jména**: pokémoni, útoky, předměty, schopnosti, typy, místa, postavy, odznaky.
- Herní pojmy velkými písmeny jako v originále: POKéMON (skloňuje se: POKéMONA, POKéMONY, POKéMONŮ).
- **Hráč** (`{PLAYER}`) může být kluk i holka, proto žádné minulé časy s rodem.
  Místo „{PLAYER} použil“ piš „{PLAYER} používá“ nebo „Použito: …“.
- **Pokémon** jako podmět je v mužském rodě („{STR_VAR_1} se naučil…“).
- Anglická jména se neskloňují, věty se stavějí kolem nich („Získáno: {STR_VAR_1}.“).
- Kontrola šířky: `python3 cz/preloz.py`. Dialogový řádek má nejvýš 196 px,
  popisky v menu ideálně nejsou širší než originál (jinak ověřit okno).
- Japonské a nepoužité texty se nepřekládají.

## Slovníček

| EN | CZ |
|---|---|
| BAG | BATOH |
| TRAINER | TRENÉR |
| BADGE | ODZNAK |
| EGG | VEJCE |
| MAIL | DOPIS |
| BOX | BOX |
| item | předmět |
| move | útok |
| HP, PP, Lv. | HP, PP, Lv. |
| ATTACK / DEFENSE / SPEED | ÚTOK / OBRANA / RYCHLOST |
| SP. ATK / SP. DEF | SP. ÚTOK / SP. OBR. |
| YES / NO | ANO / NE |
| CANCEL | ZPĚT |
| EXIT / QUIT | KONEC |
