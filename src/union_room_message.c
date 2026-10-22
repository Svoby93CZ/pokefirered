#include "global.h"
#include "link_rfu.h"
#include "mystery_gift_server.h"
#include "mystery_gift_client.h"
#include "constants/union_room.h"

ALIGNED(4) const u8 gText_UR_EmptyString[] = _("");
ALIGNED(4) const u8 gText_UR_Colon[] = _(":");
ALIGNED(4) const u8 gText_UR_ID[] = _("{ID}");
ALIGNED(4) const u8 gText_UR_PleaseStartOver[] = _("Začni prosím znovu od začátku.");
ALIGNED(4) const u8 gText_UR_WirelessSearchCanceled[] = _("Hledání BEZDRÁTOVÉHO\nSPOJENÍ bylo zrušeno.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("ともだちからの れんらくを\nまっています");
ALIGNED(4) const u8 gText_UR_AwaitingCommunication[] = _("{STR_VAR_1}! Čekám na\nspojení s dalším hráčem.");
ALIGNED(4) const u8 gText_UR_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Čekám na spojení!\nVšichni připraveni? Stiskni START.");

ALIGNED(4) static const u8 sText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする");
ALIGNED(4) static const u8 sText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sLinkGroupActionTexts[] = {
    sText_SingleBattle,
    sText_DoubleBattle,
    sText_MultiBattle,
    sText_TradePokemon,
    sText_Chat,
    sText_DistWonderCard,
    sText_DistWonderNews,
    sText_DistWonderCard,
    sText_HoldPokemonJump,
    sText_HoldBerryCrush,
    sText_HoldBerryPicking,
    sText_HoldBerryPicking,
    sText_HoldSpinTrade,
    sText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("Chybí\n1 hráč.");
static const u8 sText_2PlayersNeeded[] = _("Chybí\n2 hráči.");
static const u8 sText_3PlayersNeeded[] = _("Chybí\n3 hráči.");
static const u8 sText_4PlayersNeeded[] = _("あと4にん\nひつよう");
static const u8 sText_2PlayerMode[] = _("REŽIM PRO\n2 HRÁČE");
static const u8 sText_3PlayerMode[] = _("REŽIM PRO\n3 HRÁČE");
static const u8 sText_4PlayerMode[] = _("REŽIM PRO\n4 HRÁČE");
static const u8 sText_5PlayerMode[] = _("REŽIM PRO\n5 HRÁČŮ");

const u8 *const gTexts_UR_PlayersNeededOrMode[][5] = {
    { // 2 players required
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    { // 4 players required
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    { // 2-5 players required
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    { // 3-5 players required
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    }
};

ALIGNED(4) const u8 gText_UR_BButtonCancel[] = _("{B_BUTTON}ZPĚT");
ALIGNED(4) static const u8 sText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} tě oslovuje:\n{STR_VAR_1}. Přijmout?");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouShareX[] = _("{STR_VAR_2} tě oslovuje.\nPodělíš se o {STR_VAR_1}?");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} tě oslovuje.\nPřidat mezi členy?");
ALIGNED(4) const u8 gText_UR_AreTheseMembersOK[] = _("{STR_VAR_1}!\nSouhlasí tito členové?");
ALIGNED(4) const u8 gText_UR_CancelModeWithTheseMembers[] = _("Zrušit režim {STR_VAR_1}\ns těmito členy?");
ALIGNED(4) const u8 gText_UR_AnOKWasSentToPlayer[] = _("Odesláno “OK”\npro: {STR_VAR_1}.");

ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("Druhý TRENÉR teď zřejmě\nnení k dispozici…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("S TRENÉREM, který je moc daleko,\nse spojit nejde.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("Ostatní TRENÉŘI ještě nejsou\npřipraveni.\p");

const u8 *const gTexts_UR_CantTransmitToTrainer[] = {
    sText_CantTransmitTrainerTooFar,
    sText_TrainersNotReadyYet
};

ALIGNED(4) const u8 gText_UR_ModeWithTheseMembersWillBeCanceled[] = _("Režim {STR_VAR_1} s těmito\nčleny bude zrušen.{PAUSE 90}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Jeden člen už nemůže\npokračovat.\p");

const u8 *const gTexts_UR_PlayerUnavailable[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("Druhý TRENÉR zřejmě\nnení k dispozici…\p");
ALIGNED(4) const u8 gText_UR_PlayerSentBackOK[] = _("{STR_VAR_1} posílá zpět “OK”!");
ALIGNED(4) const u8 gText_UR_PlayerOKdRegistration[] = _("{STR_VAR_1} schvaluje tvé přihlášení\nza člena.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} odpovídá: “Ne…”\p");
ALIGNED(4) const u8 gText_UR_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nČekám na další členy!");
ALIGNED(4) const u8 gText_UR_QuitBeingMember[] = _("Přestat být členem?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Už nejsi členem.\p");

const u8 *const gTexts_UR_PlayerDisconnected[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) const u8 gText_UR_WirelessLinkEstablished[] = _("BEZDRÁTOVÉ SPOJENÍ\nbylo navázáno.");
ALIGNED(4) const u8 gText_UR_WirelessLinkDropped[] = _("BEZDRÁTOVÉ SPOJENÍ\nbylo přerušeno…");
ALIGNED(4) const u8 gText_UR_LinkWithFriendDropped[] = _("Spojení s kamarádem bylo\npřerušeno…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} odpovídá: “Ne…”");

const u8 *const gTexts_UR_LinkDropped[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = gText_UR_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = gText_UR_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Chceš režim\n{STR_VAR_2}?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Chceš režim\n{STR_VAR_2}?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("はなしかけています…\nしょうしょう おまちください"); // Unused
ALIGNED(4) const u8 gText_UR_AwaitingPlayersResponseAboutTrade[] = _("Čekám na odpověď hráče {STR_VAR_1}\nna výměnu…");

ALIGNED(4) static const u8 sText_Communicating[] = _("Spojuji se{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("Spojuji se: {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("Chvíli počkej{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

const u8 *const gTexts_UR_CommunicatingWait[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Čau! Chceš něco\npodniknout?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Ahoj!\nChceš něco podniknout?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Čau, zase spolu!\nCo podnikneme tentokrát?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Á! {PLAYER}, ahoj!\nChceš něco podniknout?");

const u8 *const gTexts_UR_HiDoSomething[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Chceš něco podniknout?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Chceš něco podniknout?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Co chceš dělat\nteď?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}‘また なにかする？");

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Někdo tě oslovuje.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} tě oslovuje.{PAUSE 60}");

const u8 *const gTexts_UR_PlayerContactedYou[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("Čekám na odpověď\ndruhého TRENÉRA…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("Čekám na odpověď:\n{STR_VAR_1}…");

const u8 *const gTexts_UR_AwaitingResponse[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_AwaitingResponseCancelBButton[] = _("あいての ていあんを まっています\nビーボタンで キャンセル");

ALIGNED(4) const u8 gText_UR_ShowTrainerCard[] = _("Druhý TRENÉR ti ukazuje\nsvou TRENÉRSKOU KARTU.\pChceš ukázat svou\nTRENÉRSKOU KARTU?");
ALIGNED(4) const u8 gText_UR_BattleChallenge[] = _("Druhý TRENÉR tě vyzývá\nna souboj.\pPřijmeš výzvu\nk souboji?");
ALIGNED(4) const u8 gText_UR_ChatInvitation[] = _("Druhý TRENÉR tě zve\nna chat.\pPřijmeš pozvání\nna chat?");
ALIGNED(4) const u8 gText_UR_OfferToTradeMon[] = _("Někdo chce tvého registrovaného\nLv. {DYNAMIC 0} {DYNAMIC 1}\pvyměnit za svého\nLv. {DYNAMIC 2} {DYNAMIC 3}.\pPřijmeš tuto nabídku\nvýměny?");
ALIGNED(4) const u8 gText_UR_OfferToTradeEgg[] = _("Nabídka výměny za tvé\nregistrované VEJCE.\lPřijmeš tuto nabídku výměny?");
ALIGNED(4) const u8 gText_UR_ChatDropped[] = _("Chat byl přerušen.\p");
ALIGNED(4) const u8 gText_UR_OfferDeclined1[] = _("Nabídka odmítnuta.\p");
ALIGNED(4) const u8 gText_UR_OfferDeclined2[] = _("Nabídka odmítnuta.\p");
ALIGNED(4) const u8 gText_UR_ChatEnded[] = _("Chat skončil.\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    gText_UR_ShowTrainerCard,
    gText_UR_BattleChallenge,
    gText_UR_ChatInvitation,
    gText_UR_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Á, čau! Zrovna chatujeme.\nPřidáš se?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Čau, {PLAYER}!\nZrovna chatujeme.\lPřidáš se?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Á, ahoj! Zrovna chatujeme.\nNechceš se přidat?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Á, ahoj, {PLAYER}!\nZrovna chatujeme.\lNechceš se přidat?");

const u8 *const gTexts_UR_JoinChat[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) const u8 gText_UR_TrainerAppearsBusy[] = _("……\nTRENÉR je zřejmě zaneprázdněný…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Souboj, jo?\nDobře, dej mi chvilku.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Chceš chatovat, jo?\nJasně, chvilku počkej.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Jasně! Na “pozdrav” ti\nukážu svou TRENÉRSKOU KARTU.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Souboj? Jistě, ale musím se\nnejdřív připravit.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Chceš chatovat?\nDobře, ale chvilku počkej.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("Na úvod ti ukážu svou\nTRENÉRSKOU KARTU.");

const u8 *const gTexts_UR_WaitOrShowCard[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("チャットだね！\nわかった ちょっと まってて！");
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Díky za počkání!\nPusťme se do souboje!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("Tak jo!\nPojďme chatovat!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Promiň, že čekáš!\nMůžeme začít!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Promiň, že čekáš!\nPojďme chatovat.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("Výměna začne.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Souboj začne.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Vstupuji do chatu…{PAUSE 60}");

const u8 *const gTexts_UR_StartActivity[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Promiň! Moji POKéMONI teď nejsou\nzrovna ve formě.\lZabojujeme si jindy.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Strašně se omlouvám, ale moji\nPOKéMONI se necítí dobře…\pZabojujeme si jindy.\p");

const u8 *const gTexts_UR_BattleDeclined[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Cože? Moje TRENÉRSKÁ KARTA…\nKam se poděla?\lPromiň! Ukážu ti ji jindy!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Á? Kam jsem dala svou\nTRENÉRSKOU KARTU?…\lPromiň! Ukážu ti ji později!\p");

const u8 *const gTexts_UR_ShowTrainerCardDeclined[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Jestli se mnou chceš něco\npodniknout, stačí zavolat!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Jestli se mnou chceš něco\npodniknout, neostýchej se.\p");

const u8 *const gTexts_UR_IfYouWantToDoSomething[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) const u8 gText_UR_TrainerBattleBusy[] = _("Jejda! Promiň, ale musím\ndělat něco jiného.\lTak jindy, jo?\p");
ALIGNED(4) const u8 gText_UR_NeedTwoMonsOfLevel30OrLower1[] = _("Na souboj potřebuješ dva\nPOKéMONY pod\lLv. 30.\p");
ALIGNED(4) const u8 gText_UR_NeedTwoMonsOfLevel30OrLower2[] = _("Na souboj potřebuješ dva\nPOKéMONY pod Lv. 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Á, dobře.\nStav se kdykoli, jo?\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Á…\nStav se kdykoli.\p");

// Response from partner when player declines chat
const u8 *const gTexts_UR_DeclineChat[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Á, promiň!\nTeď zrovna nemůžu.\lPokecáme jindy.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Á, promiň.\nTeď mám moc práce.\lPokecáme jindy.\p");

// Response from partner when they decline chat
const u8 *const gTexts_UR_ChatDeclined[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Páni!\nTobě to teda jde!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("Tenhle útok?\nTo je dobrá strategie!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Paráda!\nTo mi otevřelo oči!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Á! Jak můžeš v téhle situaci\npoužít tohohle POKéMONA?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("Ten POKéMON…\nJe opravdu dobře vychovaný!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("Přesně tak!\nTeď je to ten správný útok!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("To je úžasné!\nTakhle se dá bojovat?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Na střídání POKéMONŮ máš\nskvělé načasování!\p");

const u8 *const gTexts_UR_BattleReaction[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    }, {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Á, chápu!\nTo je poučné!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Už neříkej nic vtipného!\nBolí mě břicho od smíchu!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Ó?\nTo se stalo?\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Hmhm… Cože?\nTakže tohle chceš říct?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Opravdu?\nTo jsem nevěděla.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Chacha!\nCo to má znamenat?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Ano, přesně tak!\nTo jsem myslela.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("Jinými slovy…\nAno! Přesně tak!\p");

const u8 *const gTexts_UR_ChatReaction[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    }, {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Na pozdrav jen ukazuju svou\nTRENÉRSKOU KARTU.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("Doufám, že se líp poznáme!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("Ukazujeme si TRENÉRSKÉ KARTY,\nabychom se seznámili.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Ráda tě poznávám.\nTak se neztrácej!\p");

const u8 *const gTexts_UR_TrainerCardReaction[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    }, {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Jůů!\nTohohle POKéMONA jsem fakt chtěl!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Konečně jsem výměnou získal\nPOKéMONA, kterého jsem dlouho chtěl.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("Zrovna si vyměňuju POKéMONY.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("Konečně jsem výměnou získala\nPOKéMONA, kterého jsem chtěla!\p");

const u8 *const gTexts_UR_TradeReaction[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    }, {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

const u8 gText_UR_XCheckedTradingBoard[] = _("{STR_VAR_1} prohlíží\nNÁSTĚNKU VÝMĚN.\p");
ALIGNED(4) const u8 gText_UR_RegisterMonAtTradingBoard[] = _("Vítej u NÁSTĚNKY VÝMĚN.\pMůžeš tu registrovat POKéMONA\na nabídnout ho k výměně.\pChceš registrovat některého\nsvého POKéMONA?");
ALIGNED(4) const u8 gText_UR_TradingBoardInfo[] = _(
                                                    "NÁSTĚNKA VÝMĚN slouží k nabízení\n"
                                                    "POKéMONŮ k výměně.\p"
                                                    "Stačí registrovat POKéMONA\n"
                                                    "k výměně.\p"
                                                    "Druhý TRENÉR pak může nabídnout\n"
                                                    "POKéMONA ze svého týmu.\p"
                                                    "Doufáme, že POKéMONY zaregistruješ\n"
                                                    "a vyměníš je se spoustou\l"
                                                    "dalších TRENÉRŮ.\p"
                                                    "Chceš registrovat některého\n"
                                                    "svého POKéMONA?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("こうかんけいじばん の とうろくが\nかんりょう しました\pごりよう ありがとう\nございました！\p");
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("けいじばんに だれも ポケモンを\nとうろく していません\p\n");
ALIGNED(4) const u8 gText_UR_ChooseRequestedMonType[] = _("Vyber typ POKéMONA, kterého\nchceš výměnou získat.\n");
ALIGNED(4) const u8 gText_UR_WhichMonWillYouOffer[] = _("Kterého POKéMONA z týmu\nnabídneš k výměně?\p");
ALIGNED(4) const u8 gText_UR_RegistrationCanceled[] = _("Registrace byla zrušena.\p");
ALIGNED(4) const u8 gText_UR_RegistraionCompleted[] = _("Registrace je hotová.\p");
ALIGNED(4) const u8 gText_UR_TradeCanceled[] = _("Výměna byla zrušena.\p");
ALIGNED(4) const u8 gText_UR_CancelRegistrationOfMon[] = _("Zrušit registraci tvého\nLv. {STR_VAR_2} {STR_VAR_1}?");
ALIGNED(4) const u8 gText_UR_CancelRegistrationOfEgg[] = _("Zrušit registraci tvého\nVEJCE?");
ALIGNED(4) const u8 gText_UR_RegistrationCanceled2[] = _("Registrace byla zrušena.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("こうかんを きぼうしているひとを\nひょうじします");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("こうかん したい トレーナーを\nえらんで ください");
ALIGNED(4) const u8 gText_UR_AskTrainerToMakeTrade[] = _("Požádat hráče {STR_VAR_1}\no výměnu?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("……\nあいての へんじを まっています");
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("あなたが こうかんにだす\nポケモンが とうろくされていません\p");
ALIGNED(4) const u8 gText_UR_DontHaveTypeTrainerWants[] = _("Nemáš POKéMONA typu {STR_VAR_2},\nkterého chce {STR_VAR_1}.\p");
ALIGNED(4) const u8 gText_UR_DontHaveEggTrainerWants[] = _("Nemáš VEJCE, které chce\n{STR_VAR_1}.\p");

ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} teď nemůže tvého\nPOKéMONA vyměnit.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("Teď nemůžeš vyměnit POKéMONA\nhráče {STR_VAR_1}.\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) const u8 gText_UR_TradeOfferRejected[] = _("Tvoje nabídka výměny byla odmítnuta.\p");
ALIGNED(4) const u8 gText_UR_EggTrade[] = _("VÝMĚNA VEJCE");
ALIGNED(4) const u8 gText_UR_ChooseJoinCancel[] = _("{DPAD_UPDOWN}VÝBĚR  {A_BUTTON}PŘIDAT  {B_BUTTON}ZPĚT");
ALIGNED(4) const u8 gText_UR_ChooseTrainer[] = _("Vyber TRENÉRA.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Vyber TRENÉRA pro\nSOUBOJ 1 NA 1.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Vyber TRENÉRA pro\nSOUBOJ 2 NA 2.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Vyber ZAKLADATELE\nTÝMOVÉHO SOUBOJE.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Vyber TRENÉRA,\nse kterým si vyměníš.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Vyber TRENÉRA, který sdílí\nWONDER CARDS.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Vyber TRENÉRA, který sdílí\nWONDER NEWS.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Skákej s mini POKéMONY!\nVyber ZAKLADATELE.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("BERRY CRUSH!\nVyber ZAKLADATELE.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("DODRIO BERRY-PICKING!\nVyber ZAKLADATELE.");

const u8 *const gTexts_UR_ChooseTrainer[] = {
    [LINK_GROUP_SINGLE_BATTLE] = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE] = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]  = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]         = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]  = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]   = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING] = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]   = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]   = sText_ChooseTrainerToShareWonderNews
};

ALIGNED(4) const u8 gText_UR_SearchingForWirelessSystemWait[] = _("Hledám BEZDRÁTOVÉ\nSPOJENÍ. Čekej...");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("ダブルバトルでは 2ひき いじょうの\nポケモンが ひつようです\p");
ALIGNED(4) const u8 gText_UR_AwaitingPlayersResponse[] = _("Čekám na odpověď: {STR_VAR_1}…");
ALIGNED(4) const u8 gText_UR_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} dostal(a) žádost o tvé\npřijetí za člena. Čekej prosím.");
ALIGNED(4) const u8 gText_UR_AwaitingResponseFromWirelessSystem[] = _("Čekám na odpověď\nBEZDRÁTOVÉHO SPOJENÍ.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("ほかの さんかしゃが そろうまで\nしょうしょう おまちください");

ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Teď se zřejmě nesdílí\nžádné CARDS.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Teď se zřejmě nesdílí\nžádné NEWS.");

const u8 *const gTexts_UR_NoWonderShared[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) const u8 gText_UR_Battle[] = _("SOUBOJ");
ALIGNED(4) const u8 gText_UR_Chat2[] = _("CHAT");
ALIGNED(4) const u8 gText_UR_Greetings[] = _("POZDRAV");
ALIGNED(4) const u8 gText_UR_Exit[] = _("KONEC");

ALIGNED(4) const u8 gText_UR_Exit2[] = _("KONEC");
ALIGNED(4) const u8 gText_UR_Info[] = _("INFO");
ALIGNED(4) const u8 gText_UR_NameWantedOfferLv[] = _("JMÉNO{CLEAR_TO 0x3C}CHCE{CLEAR_TO 0x6E}NABÍZÍ{CLEAR_TO 0xC6}LV.");

ALIGNED(4) const u8 gText_UR_SingleBattle[] = _("SOUBOJ 1 NA 1");
ALIGNED(4) const u8 gText_UR_DoubleBattle[] = _("SOUBOJ 2 NA 2");
ALIGNED(4) const u8 gText_UR_MultiBattle[] = _("TÝMOVÝ SOUBOJ");
ALIGNED(4) const u8 gText_UR_PokemonTrades[] = _("VÝMĚNY POKéMONŮ");
ALIGNED(4) const u8 gText_UR_Chat[] = _("CHAT");
ALIGNED(4) const u8 gText_UR_Cards[] = _("KARTY");
ALIGNED(4) const u8 gText_UR_WonderCards[] = _("WONDER CARDS");
ALIGNED(4) const u8 gText_UR_WonderNews[] = _("WONDER NEWS");
ALIGNED(4) const u8 gText_UR_PokemonJump[] = _("POKéMON JUMP");
ALIGNED(4) const u8 gText_UR_BerryCrush[] = _("BERRY CRUSH");
ALIGNED(4) const u8 gText_UR_BerryPicking[] = _("BERRY-PICKING");
ALIGNED(4) const u8 gText_UR_Search[] = _("HLEDAT");
ALIGNED(4) const u8 gText_UR_SpinTrade[] = _("ぐるぐるこうかん");
ALIGNED(4) const u8 gText_UR_ItemTrade[] = _("アイテムトレード");

ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("Je to OBYČEJNÁ KARTA.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("Je to BRONZOVÁ KARTA!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("Je to MĚDĚNÁ KARTA!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("Je to STŘÍBRNÁ KARTA!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("Je to ZLATÁ KARTA!");

const u8 *const gTexts_UR_CardColor[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) const u8 gText_UR_TrainerCardInfoPage1[] = _("TRENÉRSKÁ KARTA:\n{DYNAMIC 0} {DYNAMIC 1}…\l{DYNAMIC 2}\pPOKéDEX: {DYNAMIC 3}\nČAS:     {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) const u8 gText_UR_TrainerCardInfoPage2[] = _("VÝHRY: {DYNAMIC 0}  PROHRY: {DYNAMIC 2}\nVÝMĚNY: {DYNAMIC 3}×\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Rád jsem tě poznal!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Ráda tě poznávám!{PAUSE 60}");

const u8 *const gTexts_UR_GladToMeetYou[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) const u8 gText_UR_FinishedCheckingPlayersTrainerCard[] = _("Prohlídka TRENÉRSKÉ KARTY\nhráče {DYNAMIC 1} skončila.{PAUSE 60}");
ALIGNED(4) static const u8 sText_CanceledReadingCard[] = _("Čtení karty zrušeno.");

static const struct MysteryGiftClientCmd sClientScript_DynamicError[] = {
    {CLI_RECV, MG_LINKID_DYNAMIC_MSG},
    {CLI_COPY_MSG},
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_BUFFER_FAILURE}
};

const struct MysteryGiftServerCmd gServerScript_ClientCanceledCard[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_DynamicError)},
    {SVR_SEND},
    {SVR_LOAD_MSG, PTR_ARG(sText_CanceledReadingCard)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_CLIENT_CANCELED}
};
