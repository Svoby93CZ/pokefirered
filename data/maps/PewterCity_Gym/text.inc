PewterCity_Gym_Text_BrockIntro::
    .string "Tak jsi tady. Jsem BROCK.\n"
    .string "Jsem VŮDCE STADIONU PEWTER.\p"
    .string "Moje skalní vůle je vidět i na\n"
    .string "mých POKéMONECH.\p"
    .string "Moji POKéMONI jsou tvrdí jako\n"
    .string "skála a mají pořádnou dávku\l"
    .string "odhodlání.\p"
    .string "Přesně tak - všichni moji POKéMONI\n"
    .string "jsou typu ROCK!\p"
    .string "Fuchacha! Vyzýváš mě, i když víš,\n"
    .string "že prohraješ?\p"
    .string "To tě k tomu žene čest TRENÉRA.\p"
    .string "Tak dobře!\n"
    .string "Ukaž mi, co umíš!{PLAY_BGM}{MUS_ENCOUNTER_GYM_LEADER}$"

@ NOTE: This defeat text actually causes a buffer overflow. It's too long for the gDisplayedStringBattle
@ buffer that it's put into, and it stomps all over the gBattleTextBuffs after, as well as the otherwise
@ unused array after that, sFlickerArray. Perhaps that's the reason why said array exists.
PewterCity_Gym_Text_BrockDefeat::
    .string "Podcenil jsem tě, a proto jsem\n"
    .string "prohrál.\p"
    .string "Jako důkaz tvého vítězství ti\n"
    .string "uděluji… oficiální BOULDERBADGE\l"
    .string "POKéMON LEAGUE.\p"
    .string "{FONT_NORMAL}{PLAYER} dostává od BROCKA\n"
    .string "BOULDERBADGE!{PAUSE_MUSIC}{PLAY_BGM}{MUS_OBTAIN_BADGE}{PAUSE 0xFE}{PAUSE 0x56}{RESUME_MUSIC}\p"
    .string "{FONT_MALE}Už jen BOULDERBADGE dělá tvé\n"
    .string "POKéMONY silnějšími.\p"
    .string "Také umožňuje používat útok FLASH\n"
    .string "mimo souboj.\p"
    .string "POKéMON ale samozřejmě musí útok\n"
    .string "FLASH umět.$"

PewterCity_Gym_Text_TakeThisWithYou::
    .string "Počkej!\n"
    .string "Vezmi si tohle.$"

PewterCity_Gym_Text_ReceivedTM39FromBrock::
    .string "{PLAYER} dostává od BROCKA\n"
    .string "TM39.$"

PewterCity_Gym_Text_ExplainTM39::
    .string "TM, tedy Technický stroj, obsahuje\n"
    .string "techniku pro POKéMONY.\p"
    .string "Použitím TM naučíš POKéMONA útok,\n"
    .string "který obsahuje.\p"
    .string "TM se dá použít jen jednou.\p"
    .string "Takže když ho používáš, vyber\n"
    .string "POKéMONA pečlivě.\p"
    .string "Takže…\n"
    .string "TM39 obsahuje ROCK TOMB.\p"
    .string "Zasype soupeře balvany a sníží mu\n"
    .string "RYCHLOST.$"

PewterCity_Gym_Text_BrockPostBattle::
    .string "V tomhle našem obrovském světě\n"
    .string "jsou nejrůznější TRENÉŘI.\p"
    .string "Zdá se, že máš na POKéMONY velký\n"
    .string "talent.\p"
    .string "Tak ti něco navrhnu.\p"
    .string "Jdi do STADIONU v CERULEANU\n"
    .string "a vyzkoušej své schopnosti.$"

PewterCity_Gym_Text_DontHaveRoomForThis::
    .string "Na tohle nemáš místo.$"

PewterCity_Gym_Text_LiamIntro::
    .string "Stůj, děcko!\p"
    .string "K BROCKOVI máš ještě deset tisíc\n"
    .string "světelných let!$"

PewterCity_Gym_Text_LiamDefeat::
    .string "Sakra!\p"
    .string "Světelné roky nejsou čas…\n"
    .string "Měří se jimi vzdálenost!$"

PewterCity_Gym_Text_LiamPostBattle::
    .string "To bylo dobré.\n"
    .string "…Ale na BROCKA to nestačí!$"

PewterCity_Gym_Text_LetMeTakeYouToTheTop::
    .string "Ahoj!\n"
    .string "Chceš snít ve velkém?\p"
    .string "Troufáš si snít o titulu POKéMON\n"
    .string "ŠAMPIONA?\p"
    .string "Nejsem TRENÉR, ale můžu ti\n"
    .string "poradit, jak vyhrávat.\p"
    .string "Dovedu tě až na vrchol!$"

PewterCity_Gym_Text_LetsGetHappening::
    .string "Tak jo!\n"
    .string "Jdeme na to!$"

PewterCity_Gym_Text_TryDifferentPartyOrders::
    .string "První POKéMON v zápase je ten\n"
    .string "úplně vlevo v SEZNAMU POKéMONŮ.\p"
    .string "Když změníš pořadí POKéMONŮ,\n"
    .string "můžeš získat výhodu.\p"
    .string "Zkoušej různá pořadí podle\n"
    .string "soupeřova týmu.$"

PewterCity_Gym_Text_ItsFreeLetsGetHappening::
    .string "Je to služba zdarma!\n"
    .string "Jdeme na to!$"

PewterCity_Gym_Text_YoureChampMaterial::
    .string "Přesně jak jsem myslel!\n"
    .string "Máš na titul POKéMON ŠAMPIONA!$"

PewterCity_Gym_Text_GymStatue::
    .string "POKéMON STADION PEWTER\n"
    .string "VŮDCE: BROCK\p"
    .string "VÍTĚZNÍ TRENÉŘI:\n"
    .string "{RIVAL}$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "POKéMON STADION PEWTER\n"
    .string "VŮDCE: BROCK\p"
    .string "VÍTĚZNÍ TRENÉŘI:\n"
    .string "{RIVAL}, {PLAYER}$"

