#ifndef GAME_ENUMS_H
#define GAME_ENUMS_H

typedef enum
{
    eB4MenuChoiceOnePlayer_Race = 0,
    eB4MenuChoiceOnePlayer_TimeAttack = 1,
    eB4MenuChoiceOnePlayer_RoadRage = 2,
    eB4MenuChoiceOnePlayer_Revenge = 3,
    eB4MenuChoiceOnePlayer_BurningLap = 4,
    eB4MenuChoiceOnePlayer_Eliminator = 5,
    eB4MenuChoiceOnePlayer_Crash = 6,
    eB4MenuChoiceOnePlayer_CarViewer = 7,
    eB4MenuChoiceOnePlayer_GrandPrix = 8,
    eB4MenuChoiceOnePlayer_Count = 9
} EB4MenuChoicesOnePlayer;

typedef enum
{
    eMultiplayerButton_Race = 0,
    eMultiplayerButton_RoadRage = 1,
    eMultiplayerButton_TrafficAttack = 2,
    eMultiplayerButton_CrashTour = 3,
    eMultiplayerButton_CrashParty = 4,
    eMultiplayerButton_CrashBattle = 5,
    eMultiplayerButton_Back = 6,
    eMultiplayerButton_Continue = 7,
    eMultiplayerButton_Retry = 8,
    eMultiplayerButton_Max = 9
} EMultiplayerButton;

typedef enum
{
    eB4MenuChoiceMultiPlayer_Race = 0,
    eB4MenuChoiceMultiPlayer_RoadRage = 1,
    eB4MenuChoiceMultiPlayer_CrashTour = 2,
    eB4MenuChoiceMultiPlayer_CrashBattle = 3,
    eB4MenuChoiceMultiPlayer_CrashParty = 4,
    eB4MenuChoiceMultiPlayer_Revenge = 5,
    eB4MenuChoiceMultiPlayer_Count = 6
} EB4MenuChoicesMultiPlayer;

typedef enum
{
    eGtStateActionConstruct = 0,
    eGtStateActionDestruct = 1,
    eGtStateActionLeave = 2,
    eGtStateActionEnter = 3,
    eGtStateActionUpdate = 4,
    eGtStateActionEvent = 5
} EGtStateAction;

typedef enum
{
    eAptVarType_StringHash = 0,
    eAptVarType_Integer = 1,
    eAptVarType_Boolean = 2,
    eAptVarType_Array = 3,
    eAptVarType_String = 4,
    eAptVarType_Max = 5
} EAptVarType;

typedef enum
{
    eAptTextType_Label = 0,
    eAptTextType_SubLabel = 1,
    eAptTextType_Boolean = 2,
    eAptTextType_Array = 3,
    eAptTextType_String = 4,
    eAptTextType_Max = 5
} EAptTextType;

typedef enum
{
    AptVFT_xxx = 0,
    AptVFT_StringValue = 1,
    AptVFT_Property = 2,
    AptVFT_None = 3,
    AptVFT_Register = 4,
    AptVFT_Boolean = 5,
    AptVFT_Float = 6,
    AptVFT_Integer = 7,
    AptVFT_Lookup = 8,
    AptVFT_NativeFunction = 9,
    AptVFT_UNUSED = 10,
    AptVFT_Extern = 11,
    AptVFT_CharacterShapeInst = 12,
    AptVFT_CharacterSpriteInst = 13,
    AptVFT_CharacterButtonInst = 14,
    AptVFT_CharacterTextInst = 15,
    AptVFT_CharacterStaticTextInst = 16,
    AptVFT_CharacterMorphInst = 17,
    AptVFT_CharacterAnimationInst = 18,
    AptVFT_CharacterLevelInst = 19,
    AptVFT_FrameStack = 20,
    AptVFT_Sound = 21,
    AptVFT_Array = 22,
    AptVFT_Math = 23,
    AptVFT_Key = 24,
    AptVFT_Global = 25,
    AptVFT_ScriptColour = 26,
    AptVFT_Object = 27,
    AptVFT_Prototype = 28,
    AptVFT_Date = 29,
    AptVFT_MovieClip = 30,
    AptVFT_Mouse = 31,
    AptVFT_XmlNode = 32,
    AptVFT_Xml = 33,
    AptVFT_XmlAttributes = 34,
    AptVFT_LoadVars = 35,
    AptVFT_TextFormat = 36,
    AptVFT_Extension = 37,
    AptVFT_GlobalExtension = 38,
    AptVFT_Stage = 39,
    AptVFT_RESERVED = 40,
    AptVFT_Error = 41,
    AptVFT_StringObject = 42,
    AptVFT_ScriptFunction1 = 43,
    AptVFT_ScriptFunction2 = 44,
    AptVFT_ScriptFunctionByteCodeBlock = 45,
    AptVFT_DisplayListHead = 46,
    AptVFT_NumVFTs = 47
} AptVirtualFunctionTable_Indices;

typedef enum
{
    eB4PopupButton_OK = 0,
    eB4PopupButton_Cancel = 1,
    eB4PopupButton_Yes = 2,
    eB4PopupButton_No = 3,
    eB4PopupButton_Retry = 4,
    eB4PopupButton_Continue = 5,
    eB4PopupButton_TroubleShooter = 6,
    eB4PopupButton_Disconnect = 7,
    eB4PopupButton_Buy = 8,
    eB4PopupButton_Back = 9,
    eB4PopupButton_Max = 10
} EB4PopupButton;

typedef enum EB4PopupType
{
    eB4PopupType_Message = 0,
    eB4PopupType_OK = 1,
    eB4PopupType_Cancel = 2,
    eB4PopupType_OKCancel = 3,
    eB4PopupType_YesNo = 4,
    eB4PopupType_RetryCancel = 5,
    eB4PopupType_RetryContinue = 6,
    eB4PopupType_TroubleShooterCancel = 7,
    eB4PopupType_RetryDisconnect = 8,
    eB4PopupType_BuyBack = 9,
    eB4PopupType_Max = 10
} EB4PopupType;

typedef enum
{
    eMenuFlowEventMenuPageForward = 0,
    eMenuFlowEventMenuPageBack = 1,
    eMenuFlowEventMenuPageSelectedOption = 2,
    eMenuFlowEventMenuPageFlashEvent = 3,
    eMenuFlowEventMenuPageInputEvent = 4,
    eMenuFlowEventMenuPageDebugButtonEvent = 5,
    eMenuFlowEventBootedOutOfGame = 6,
    eMenuFlowEventBootedOutOfUserSet = 7,
    eMenuFlowEventPlayerListChanged = 8,
    eMenuFlowEventMessageBox = 9,
    eMenuFlowEventCustomStringsCleared = 10,
    eMenuFlowEventDownloadRecordDetails = 11,
    eMenuFlowEventDownloadRecordComplete = 12,
    eMenuFlowEventMax = 13
} EB4MenuFlowEvents;

typedef enum
{
    eStageLogicInvalid = 0,
    eOfflineRace = 1,
    eOfflineTwoPlayerRace = 2,
    eOnlineRace = 3,
    eOfflineLapEliminator = 4,
    eOfflineBurningLap = 5,
    eOfflineRoadRage = 6,
    eOfflineTwoPlayerRoadRage = 7,
    eOnlineRoadRage = 8,
    eOfflineRevenge = 9,
    eOnlineCompRevenge = 10,
    eOfflineSingleCrash = 11,
    eOfflineTwoPlayerCrashCoop = 12,
    eOfflineTwoPlayerCrashComp = 13,
    eOfflinePartyCrash = 14,
    eOfflineTourCrash = 15,
    eOfflineTeamPartyCrash = 16,
    eOnlinePartyCrash = 17,
    eOfflineCoopCrash = 18,
    eOnlineGolfCrash = 19,
    eOfflineCompCrash = 20,
    eOnlineCompCrash = 21,
    eCarViewer = 22,
    eOfflineTwoPlayerRevenge = 23
} EStageLogicType;

typedef enum
{
    eSingleEventMenuType_None = 0,
    eSingleEventMenuType_Main = 1,
    eSingleEventMenuType_MP = 2,
    eSingleEventMenuType_MPRaceOptions = 3,
    eSingleEventMenuType_MPTrafficAttackOptions = 4,
    eSingleEventMenuType_MPCrashOptions = 5,
    eSingleEventMenuType_MPPartyOptions = 6,
    eSingleEventMenuType_InGamePause = 7,
    eSingleEventMenuType_CarSelect = 8,
    eSingleEventMenuType_Max = 9
} ESingleEventMenuType;

typedef enum
{
    eSingleEventState_None = 0,
    eSingleEventState_ModeSelect = 1,
    eSingleEventState_ModeSetup = 2,
    eSingleEventState_InGame = 3,
    eSingleEventState_ProfileSave = 4,
    eSingleEventState_Max = 5
} ESingleEventState;

typedef enum
{
    eRacePositionTypeNone = 0,
    eRacePositionTypeNormal = 1,
    eRacePositionTypeRace = 2,
    eRacePositionTypeBattle = 3,
    eRacePositionTypeOnlineRace = 4,
    eRacePositionTypeOnlineRoadRage = 5,
    eRacePositionTypeOnlineRevenge = 6,
    eRacePositionTypeTargetVehicle = 7,
    eRacePositionTypeCount = 8
} ERacePositionType;

typedef enum
{
    eCRB_NONE = 0,
    eCRB_PLAYERCAR = 1,
    eCRB_AICAR = 2,
    eCRB_NETWORKCAR = 3,
    eCRB_TRAFFICCAR = 4,
    eCRB_TRAFFICARTICULATED = 5,
    eCRB_CHECKEDTRAFFIC = 6,
    eCRB_PROP = 7,
    eCRB_BODYPART = 8
} ECollidingBodyType;

typedef enum
{
    eHUDAlignTop = 0,
    eHUDAlignTopLeft = 1,
    eHUDAlignLeft = 2,
    eHUDAlignBottomLeft = 3,
    eHUDAlignBottom = 4,
    eHUDAlignBottomRight = 5,
    eHUDAlignRight = 6,
    eHUDAlignTopRight = 7,
    eHUDAlignNone = 8,
    eHUDAlignCount = 9
} EHUDAlign;

typedef enum
{
    ePlayerCarInvalid = -1,
    ePlayerCar0 = 0,
    ePlayerCar1 = 1,
    ePlayerCarCount = 2
} EPlayerCarIndex;

typedef enum
{
    eABT_AICar = 0,
    eABT_NetworkCar = 1,
    eABT_PlayerCar = 2,
    eABT_Traffic = 3,
    eABT_CrashingTraffic = 4,
    eABT_CheckedTraffic = 5,
    eABT_StaticProp = 6,
    eABT_DynamicProp = 7,
    eABT_BodyPart = 8,
    eABT_Camera = 9,
    eABT_NumActiveBodyTypes = 10
} EB4ActiveBodyType;

typedef enum
{
    eVehicleCategoryNull = 0,
    eVehicleCategoryCar = 1,
    eVehicleCategoryVan = 2,
    eVehicleCategoryLorry = 3,
    eVehicleCategoryArticulatedCab = 4,
    eVehicleCategoryBus = 5,
    eVehicleCategorySpecialHelicopter = 6,
    eVehicleCategorySpecialLTrain = 7,
    eVehicleCategorySpecialTram = 8,
    eVehicleCategorySpecialMonoRail = 9,
    eVehicleCategorySpecialPlane = 10,
    eVehicleCategoryArticulatedTrailer = 11,
    eVehicleCategoriesNumber = 12
} ETrafficVehicleCategories;

typedef enum
{
    eTrafficCheckType_Default = 0,
    eTrafficCheckType_Disabled = 1,
    eTrafficCheckType_Full = 2,
    eTrafficCheckType_Max = 3
} ETrafficCheckType;

typedef enum
{
    eDriverTakedownDifficultyEasy = 0,
    eDriverTakedownDifficultyNormal = 1,
    eDriverTakedownDifficultyHard = 2,
    eDriverTakedownDifficultyCount = 3
} EDriverTakedownDifficulty;

typedef enum
{
    eSlamShuntComboStateNeutral = 0,     // Hard
    eSlamShuntComboStateLevelOne = 1,    // Normal
    eSlamShuntComboStateLevelTwo = 2,    // Easy
    eSlamShuntCombeStateCount = 3
} ESlamShuntComboState;

typedef enum
{
    eRaceCarTypePlayer = 0,
    eRaceCarTypeAI = 1,
    eRaceCarTypeNetwork = 2,
    eRaceCarTypeGhost = 3,
    eRaceCarTypeCount = 4
} EB4RaceCarType;

typedef enum
{
    eScoreRaceCarStateRollingStart = 0,
    eScoreRaceCarStatePreStartLine = 1,
    eScoreRaceCarStateRacing = 2,
    eScoreRaceCarStateFinished = 3
} EB4ScoreRaceCarState;

typedef enum
{
    eB4MenuFlowNormal = 0,
    eB4MenuFlowCount = 1
} EB4MenuFlowType;

typedef enum
{
    eGTF_STATUS_CLOSED = 0,
    eGTF_STATUS_READY = 1,
    eGTF_STATUS_BUSY = 2,
    eGTF_STATUS_ERROR = 3
} EFileStatus;

typedef enum
{
    eGTF_ERROR_NOERROR = 0,
    eGTF_ERROR_FILESYSTEM = 1,
    eGTF_ERROR_FILE = 2,
    eGTF_ERROR_DISKFULL = 3
} EFileError;

typedef enum
{
    eGTF_BEGIN = 0,
    eGTF_CURRENT = 1,
    eGTF_END = 2
} EFileMoveMethod;

#endif
