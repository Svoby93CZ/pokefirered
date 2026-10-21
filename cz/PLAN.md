# Čeština pro Pokémon FireRed — plán

Každá část = jeden commit na větvi `cestina`. Hotové části odškrtávej.

- [x] **0. Font a nástroje**: česká písmena v prázdných slotech 0x37–0x4A
  (`cz/ceske_znaky.py`), náhled (`cz/nahled_fontu.py`), překládací nástroj (`cz/preloz.py`).
- [x] **1. Menu a rozhraní**: `src/strings.c` a drobnosti v `src/*.c`
  - [x] 1a začátek `strings.c`: hlavní a start menu, Pokédex, batoh, obchod, tým, PC, herna
  - [x] 1b zbytek `strings.c`: boxy v PC, přehled pokémona, trenérská karta, nastavení, mapa regionu,
    zadávání jmen, líhnutí, rybaření, školka, učení útoků
- [x] **2. Souboje**: `src/battle_message.c`, třídy trenérů (`src/data/text/trainer_class_names.h`).
  Texty Trainer Tower (TIME BOARD…) jsou v části 7.
- [x] **3. Společné hlášky**
  - [x] 3a `data/text/*.inc` (úvod hry, ukládání, PC, obchod, školka, Safari, POKé DUDE, hodnocení Pokédexu…),
    `data/event_scripts.s`, `data/scripts/field_moves.inc`, `repel.inc`
  - [x] 3b `data/text/trainers.inc` (VS Seeker + odvety trenérů), `src/data/text/quest_log.h`, `teachy_tv.h`
- [ ] **4. Příběh**: `data/maps/*/text.inc`, po oblastech:
  - [x] 4a Pallet, Viridian (vč. stadionu), Pewter, Route 1–3, Route 22, Viridian Forest
  - [x] 4b Mt. Moon, Cerulean, Vermilion, S.S. Anne, Route 4–11
    - [x] Route 4, Mt. Moon, Cerulean City
    - [x] Route 24–25 (Bill), Route 5–6, školka, podchody, Diglett's Cave
    - [x] Vermilion City, S.S. Anne
    - [x] Route 7–11
  - [x] 4c Rock Tunnel, Lavender, Celadon, Rocket Hideout, Pokémon Tower
    - [x] Rock Tunnel, Lavender Town
    - [x] Celadon City (obchodní dům, Game Corner, stadion)
    - [x] Rocket Hideout, Pokémon Tower
  - [ ] 4d Saffron, Silph Co., Fuchsia, Safari Zone, Cinnabar
    - [x] Saffron City (dojo, stadion, fan club, Copycat)
  - [ ] 4e Victory Road, Indigo Plateau, zbylé cesty
  - [ ] 4f Sevii Islands
- [ ] **5. Popisy**: útoky, předměty, Pokédex, bobule.
- [ ] **6. Nápověda a Fame Checker**: `help_system.inc`, `fame_checker.inc`, `gFameCheckerText_*` v `strings.c`.
- [ ] **7. Ostatní**: klávesnice pro jména s češtinou (`naming_screen.c`; tlačítka lower/BACK/OK/START/SELECT
  jsou obrázky v `graphics/naming_screen/`, ověřeno v mGBA), Trainer Tower, Union Room, Wireless,
  minihry (Berry Crush, Pokémon Jump, Dodrio), Mystery Gift, Easy Chat, titulky — vše v `strings.c` ještě anglicky.

## Pravidla

- **Anglicky zůstávají jména**: pokémoni, útoky, předměty, schopnosti, typy, místa, postavy, odznaky.
- Herní pojmy velkými písmeny jako v originále: POKéMON (skloňuje se: POKéMONA, POKéMONY, POKéMONŮ).
- **Hráč** (`{PLAYER}`) může být kluk i holka, proto žádné minulé časy s rodem.
  Místo „{PLAYER} použil“ piš „{PLAYER} používá“ nebo „Použito: …“.
- **Pokémon** jako podmět je v mužském rodě („{STR_VAR_1} se naučil…“).
- Nástroj značí `R` možný rodový tvar vůči hráči (jsi chytil, bys musel, jsi dobrý…) — vždy přeformuluj,
  pokud věta míří na hráče (u NPC k NPC je rod v pořádku).
- Pozor na minulý čas ve 2. osobě („Všiml sis…“, „Už jsi chytil…“) — je rodový, přeformuluj („Vidíš…“, „Už máš…“).
- NPC mluví v 1. osobě podle svého rodu (podle jména a třídy: „Nasbírala jsem…“); věty o hráči
  zůstávají bezrodé („Taky nos kraťasy!“ místo „Taky bys měl…“). Quest log vypráví v přítomném čase.
- Proměnná jména (`{STR_VAR_1}`, `{DYNAMIC}`) se neskloňují, věty se stavějí kolem nich
  („Získáno: {STR_VAR_1}.“). Pevná jména se skloňovat smí, když to zní přirozeně (PC PROF. OAKA, BILLOVO PC).
- Zkratky stavů PSN, PAR, SLP, BRN, FRZ zůstávají, protože ikony stavů ve hře jsou obrázky.
- Jednotky v Pokédexu (HT, WT, lbs.) zatím zůstávají, přechod na metry/kg by vyžadoval změnu kódu.
- Kontrola šířky: `python3 cz/preloz.py`. Dialogový řádek má nejvýš 196 px,
  popisky v menu ideálně nejsou širší než originál (jinak ověřit okno).
  Změřená okna: nabídka akcí v batohu ~48 px, akce v týmu ~72 px, název kapsy 72 px,
  start menu ~48 px, popis útoku v poli 141 px, výzvy v týmu 120–168 px, hlášky v boxu PC 144 px,
  název stránky v přehledu 100 px, ovládání v přehledu 84 px (malé), lišta mapy 40 px (malé),
  nastavení: popisek < 122 px, hodnota ≤ 70 px, okno přezdívky 128 px (jméno druhu + titulek).
  Výběrová menu ze skriptů (`script_menu.c`) si šířku počítají sama.
- Japonské a nepoužité texty se nepřekládají (taky třídy trenérů z Ruby/Sapphire `RS_*`, AQUA, MAGMA).
- **Souboje** (`python3 cz/preloz.py src/battle_message.c boj`): děj v přítomném čase („používá“, „vysílá“),
  jméno s předponou („Divoký “/„Soupeřův “, spojenec „Tvůj“) vždy v 1. pádě — jinak dvojtečka
  („{B_SCR_ACTIVE_NAME_WITH_PREFIX}: {B_SCR_ACTIVE_ABILITY}!“) nebo věta bez jména.
  Okno zpráv 224 px, limit 216 px. Bojové menu: 2. sloupec max 40 px (x=56 v okně 96 px).
- Pozor na buffery: kousky kopírované do `gBattleTextBuff1–3` mají max 15 znaků (pole 16 B),
  třídy trenérů max 12 znaků (`gTrainerClassNames[][13]`, `{PKMN}` = 2 znaky).

## Slovníček

| EN | CZ |
|---|---|
| BAG | BATOH |
| TRAINER | TRENÉR |
| BADGE | ODZNAK |
| EGG | VEJCE |
| MAIL | DOPIS |
| BOX | BOX |
| KEY ITEMS | DŮLEŽITÉ (předměty) |
| COINS | ŽETONY |
| HALL OF FAME | SÍŇ SLÁVY |
| SUMMARY | PŘEHLED |
| MAILBOX | SCHRÁNKA |
| fainted | omdlel |
| FIGHT / RUN | BOJ / ÚTĚK |
| BAIT / ROCK (Safari) | KRMENÍ / KÁMEN |
| GYM LEADER | VŮDCE (stadionu) |
| CHAMPION | ŠAMPION |
| ELITE FOUR, TEAM ROCKET | zůstávají (jména skupin) |
| GHOST (neznámý duch) | DUCH |
| DAY-CARE | ŠKOLKA (pán/paní ze ŠKOLKY) |
| TRAINER TIPS | RADY PRO TRENÉRY |
| MOM / PA (hlasatel) | MÁMA / HLASATEL |
| STICKER | SAMOLEPKA |
| AIDE | ASISTENT |
| item | předmět |
| move | útok |
| HP, PP, Lv. | HP, PP, Lv. |
| ATTACK / DEFENSE / SPEED | ÚTOK / OBRANA / RYCHLOST |
| SP. ATK / SP. DEF | SP. ÚTOK / SP. OBR. |
| YES / NO | ANO / NE |
| CANCEL | ZPĚT |
| EXIT / QUIT | KONEC |
| Gramps (rival o Oakovi) | dědo |
| SIS | ségra |
| GYM | STADION |
| (ženská) LEADER | VŮDKYNĚ |
| BERRIES (běžně v textu) | BOBULE; názvy předmětů (BERRY POWDER, ORAN BERRY…) zůstávají |
| Champ in the making! | Ty budoucí hvězdo! |
| BOSS (Rocketi o Giovannim) | ŠÉF |
| DRUGSTORE | LÉKÁRNA; CELADON DEPT. STORE, GAME CORNER, PRIZE EXCHANGE zůstávají (názvy) |
| COINS (Game Corner) | ŽETONY; COIN CASE zůstává |

Oslovení: sestra v POKéMON CENTER a prodavači vykají, ostatní tykají.
STARTÉRY a jiná jména pokémonů ve větách neskloňuj („Tvoje volba je SQUIRTLE“).

## Jak pokračovat (pro další sezení)

1. Přečti tenhle soubor, hlavně Pravidla a Slovníček.
2. Překlad textů `_("…")` v C souborech:
   ```
   python3 cz/preloz.py src/soubor.c <<'EOF'
   gText_Nazev = Český text\ns novým řádkem
   EOF
   ```
   Přidej `maly`, když se text vypisuje malým fontem (FONT_SMALL). Zápis je „všechno, nebo nic“:
   při chybě se nic nezmění. U řádků s `!` dohledej v kódu šířku okna, `!!` je přes dialogový limit 196 px.
3. Texty v `data/**/*.inc` a `*.s` (`Label::` + řádky `.string "…"`) jdou stejně: `Label = text`.
   Odstavec bez `\n`/`\l` nástroj zalomí sám (do 196 px, `\n` pak `\l`, jednopísmenná slova
   nenechá na konci řádku), takže u dialogů stačí psát odstavce oddělené `\p`.
   Znaky mimo `charmap.txt` (třeba pomlčka „–“) nástroj odmítne — použij čárku nebo „-“.
4. `make -j4` musí projít bez chyb, test: `mgba-qt pokefirered.gba`.
5. Odškrtni část výše, commit `CZ část N: …` a `git push`.

Rozsah (slova): strings.c 4,9k · battle_message.c 2,3k · popisy útoků 4,6k · data/text 18k
(z toho nápověda 7k, Fame Checker 3,5k) · mapy 44,6k · Pokédex a předměty zatím nezměřeno.
