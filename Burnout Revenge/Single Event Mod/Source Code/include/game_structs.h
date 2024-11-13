#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

#pragma pack(1)

#include "types.h"
#include "game_enums.h"

typedef struct CGtV3d CGtV3d;
typedef struct CGtV2d CGtV2d;
typedef struct CGtAxisAlignedBox CGtAxisAlignedBox;
typedef struct CGtMatrix3x4 CGtMatrix3x4;

typedef struct CGtState CGtState;
typedef struct CGtTimer CGtTimer;
typedef struct CGtFSM CGtFSM;
typedef struct CB4MenuFlowManager CB4MenuFlowManager;
typedef struct CB4MenuChoices CB4MenuChoices;
typedef struct CB4MainMenuState CB4MainMenuState;
typedef struct CB4MultiplayerState CB4MultiplayerState;
typedef struct CB4MultiplayerService CB4MultiplayerService;
typedef struct CB4MPRaceOptionsState CB4MPRaceOptionsState;
typedef struct CB4MPCrashOptionsState CB4MPCrashOptionsState;
typedef struct CB4MPPartyOptionsState CB4MPPartyOptionsState;

typedef struct AptNativeString AptNativeString;
typedef struct StringDataC StringDataC;
typedef struct CGtHashIDStringArray CGtHashIDStringArray;
typedef struct CGtArrayEntry CGtArrayEntry;
typedef struct CB4LanguageManager CB4LanguageManager;
typedef struct CB4FlashMovieManager CB4FlashMovieManager;
typedef struct CB4GameMode CB4GameMode;
typedef struct CB4OnePlayerStage CB4OnePlayerStage;
typedef struct CB4Challenge CB4Challenge;
typedef struct CB4RaceSetupConfig CB4RaceSetupConfig;
typedef struct CB4RaceCarResults CB4RaceCarResults;
typedef struct CB4TwoPlayerSplitScreenStage CB4TwoPlayerSplitScreenStage;
typedef struct CB4GameState CB4GameState;
typedef struct CB4Settings CB4Settings;
typedef struct CB4NetworkManager CB4NetworkManager;
typedef struct CB4RaceCarPhysics CB4RaceCarPhysics;
typedef struct AptActionInterpreter AptActionInterpreter;
typedef struct AptBasePtrStack AptBasePtrStack;
typedef struct CB4MultiplayerRoadRageLogic CB4MultiplayerRoadRageLogic;
typedef struct CB4StageLogicGameParams CB4StageLogicGameParams;
typedef struct CB4StageLogic CB4StageLogic;
typedef struct CB4TrafficVehicle CB4TrafficVehicle;
typedef struct CB4VehiclePhysicsAttribs CB4VehiclePhysicsAttribs;
typedef struct CB4CollidingPair CB4CollidingPair;
typedef struct CB4ActiveBody CB4ActiveBody;
typedef struct CB4CollidingBody CB4CollidingBody;
typedef struct CB4VehiclePhysics CB4VehiclePhysics;
typedef struct CB4TrafficPhysics CB4TrafficPhysics;
typedef struct CB4RaceCar CB4RaceCar;
typedef struct CB4PlayerCarPhysics CB4PlayerCarPhysics;
typedef struct CB4PlayerCar CB4PlayerCar;
typedef struct CB4AICar CB4AICar;
typedef struct CB4AIDriver CB4AIDriver;
typedef struct CB4CrashActionDirector CB4CrashActionDirector;
typedef struct CB4ProfileStatistics CB4ProfileStatistics;
typedef struct CB4HUDBurningLapTimer CB4HUDBurningLapTimer;
typedef struct CB4LapManager CB4LapManager;
typedef struct CB4HUDBurningLap CB4HUDBurningLap;
typedef struct CB4OffensiveDrivingManager CB4OffensiveDrivingManager;
typedef struct CB4ConvexHull CB4ConvexHull;
typedef struct CB4ConvexHullVehicle CB4ConvexHullVehicle;
typedef struct CB4HullCollideParams CB4HullCollideParams;
typedef struct CB4HullCollideHullParams CB4HullCollideHullParams;
typedef struct CB4HUDHitCount CB4HUDHitCount;
typedef struct CB4SingleRevengeLogic CB4SingleRevengeLogic;
typedef struct CB4AptManager CB4AptManager;
typedef struct CB4TrackList CB4TrackList;
typedef struct CB4HUDManager CB4HUDManager;
typedef struct CB4HUDTrafficAttackScore CB4HUDTrafficAttackScore;
typedef struct CB4TakedownManager CB4TakedownManager;
typedef struct CB4TakedownManagerSEM CB4TakedownManagerSEM;
typedef struct CGTFile__vtable CGTFile__vtable;
typedef struct CGTFile CGTFile;

struct CGtV2d // size: 0x8
{
/* 0x00 */  float marValues[2];
};

struct CGtV3d // size: 0x10
{
/* 0x00 */  float mrX;
/* 0x04 */  float mrY;
/* 0x08 */  float mrZ;
/* 0x0C */  float mrPlus;
};

struct CGtMatrix3x4 // size: 0x40
{
/* 0x00 */  CGtV3d mRight;
/* 0x10 */  CGtV3d mUp;
/* 0x20 */  CGtV3d mAt;
/* 0x30 */  CGtV3d mPos;
};

struct CGtAxisAlignedBox // size: 0x20
{
/* 0x00 */  CGtV3d mSup;
/* 0x10 */  CGtV3d mInf;
};

struct CGtState // 0x10
{
    u64 mID;                     // GtID
    float mrTimeStateEntered;    // RwReal
    void* __vtable;              // __vtbl_ptr_type*
};

struct CGtTimer // 0x2c
{
    s32 mnCurrentFrames;              // RwInt32
    s32 mnCurrentFrameCount;          // RwInt32
    s32 mnFramesStopped;              // RwInt32
    s32 mnFramesRunningFullSpeed;     // RwInt32
    s32 mnFramesRunningSlowMo;        // RwInt32
    s32 mnInitFrameCount;             // RwInt32
    s32 mnSlowMoMultiplier;           // RwInt32
    float mrTimeStep;                 // RwReal
    float mrTime;                     // RwReal
    s32 mnRequestSlowMoMultiplier;    // RwInt32
    bool mbIsRunning;
    u8 __pad0[3];
};

struct CGtFSM // 0x18
{
    CGtState* mpState;
    void* mpOwner;
    void* mpOffsetTable;         // CGtStateOffset*
    CGtTimer* mpStateTimer;
    float mrTimeStateEntered;    // RwReal
    void* __vtable;              // __vtbl_ptr_type*
};

struct CB4MainMenuState // 0x10
{
    CGtState mState;
};

struct CB4MPCrashOptionsState // 0x18
{
    CGtState mState;
    EB4MenuChoicesMultiPlayer meMultiplayerMenuChoice;
    u8 __pad0[4];
};

struct StringDataC
{
/* 0x0 */  short unsigned int m_uRefCount;
/* 0x2 */  short unsigned int m_uSize;
/* 0x4 */  short unsigned int m_uMaxSize;
/* 0x6 */  short unsigned int m_uHash;
/* 0x8 */  char m_strText[256];
};

struct AptNativeString
{
    StringDataC *m_pData;
};

struct CGtArrayEntry
{
    char *mpData;
};

struct CGtHashIDStringArray
{
    u64 mArrayID;                  // GtID - Inherited from CGtArrayBase
    s32 mnNumEntries;              // Inherited from CGtArrayBase
    CGtArrayEntry *mpaIndex;       // Inherited from CGtArrayBase
};

struct CB4LanguageManager // 0x2C
{
/* 0x00 */  s32 mePrepareState;                     // enum EGtPrepareState
/* 0x04 */  s32 meFontsPrepareState;                // enum EGtPrepareState
/* 0x08 */  CGtHashIDStringArray *mpMainStrings;
/* 0x0C */  void *mpBigFont;                        // CGt2dFont *
/* 0x10 */  void *mpSmallFont;                      // CGt2dFont *
/* 0x14 */  void *mpDigitalFont;                    // CGt2dFont *
/* 0x18 */  u16 *mpNoStringString;                  // GtUTF16 *
/* 0x1C */  u16 *mpHeadDollarStringString;          // GtUTF16 *
/* 0x20 */  u16 *mpTailDollarStringString;          // GtUTF16 *
/* 0x24 */  s32 meLanguage;                         // enum EGtLanguage
/* 0x28 */  bool mbIsDollarOnLeft;
/* 0x29 */  bool mbFileLoaded;
/* 0x2A */  bool mbIsBigFontLoaded;
/* 0x2B */  bool mbIsSmallFontLoaded;
};

struct CB4MenuChoices // 0x280
{
/* 0x000 */  u64 mTrackID;
/* 0x008 */  u8 __pad0[0x138];
/* 0x140 */  EB4MenuChoicesOnePlayer meOnePlayerChoice;
/* 0x144 */  u8 __pad1[0xC];
/* 0x150 */  s32 mnNumAICars;
/* 0x154 */  u8 __pad2[0x54];
/* 0x1A8 */  u64 maCarID[6];
/* 0x1D8 */  s32 maCarColor[6];
/* 0x1F0 */  u8 __pad3[0x85];
/* 0x275 */  bool mbTrafficOn;
/* 0x276 */  u8 __pad4[4];
/* 0x27A */  bool mbCrashbreakerInRaceOn;
/* 0x27B */  u8 __pad5[5];
};

struct CB4FlashMovieManager // 0x480
{
/* 0x000 */ u8 __pad0[0x384];
/* 0x384 */ s32 meCurrentPlayingFlashMovie;    // enum EFlashMovie
/* 0x388 */ u8 __pad1[0xF8];
};

struct CB4MultiplayerService // 0x240
{
    bool mbInCrashMode;
    u8 __pad0;
    s16 mnNumPlayers;
    u8 __pad1[0x23C];
};

struct CB4MultiplayerState // 0x250
{
    CGtState mState;
    CB4MultiplayerService mService;
};

struct CB4RaceSetupConfig // 0x230
{
/* 0x000 */  u64 mTrackID;
/* 0x008 */  u64 maPlayerCarID[6];
/* 0x038 */  u64 maAICarID[5];
/* 0x060 */  u64 maNetworkCarID[5];
/* 0x088 */  u64 maExtraCarsToLoad[6];
/* 0x0B8 */  u64 mStageID;
/* 0x0C0 */  s32 maPlayerCarColours[6];
/* 0x0D8 */  s32 maAICarColours[5];
/* 0x0EC */  s32 maNetworkCarColours[5];
/* 0x100 */  s32 mnNumPlayerCars;
/* 0x104 */  s32 mnNumAICars;
/* 0x108 */  s32 mnNumNetworkCars;
/* 0x10C */  s32 mnNumberOfLaps;
/* 0x110 */  s32 mnNumberOfExtraCars;
/* 0x114 */  EStageLogicType meStageLogicType;
/* 0x118 */  s32 meOpponentIndex;                 // enum EOpponentIndex
/* 0x11C */  s32 mnScoreTargetForCrashGolf;
/* 0x120 */  char macGameDataFilePath[256];
/* 0x220 */  bool mbIsRager[6];
/* 0x226 */  bool mbUseTraffic;
/* 0x227 */  bool mbUseCrashbreaker;
/* 0x228 */  bool mbRageTeamInfiniteBoost;
/* 0x229 */  s8 mnCrashGolfPar;
/* 0x22A */  u8 __pad0[6];
};

struct CB4StageLogicGameParams // 0x6C
{
/* 0x00 */  float mrAwardedBurnValueScaling;
/* 0x04 */  float mrAwardedRatingValueScaling;
/* 0x08 */  float mrMinimumFatalTrafficImpact;
/* 0x0C */  float mrTimeToDelayBeforeShowingResultsPage;
/* 0x10 */  s32 meFrameRateModifier;                        // enum EFrameRateModifier
/* 0x14 */  s32 meSoundBankType;                            // enum ESoundBankType
/* 0x18 */  s32 meResultsMenuType;                          // enum EResultsMenuType
/* 0x1C */  float mrAftertouchForceFactor;
/* 0x20 */  float mrAftertouchRollFactor;
/* 0x24 */  float mrInAirAftertouchForceFactor;
/* 0x28 */  float mrInAirAftertouchRollFactor;
/* 0x2C */  float mrCrashStartOnlineTimeout;
/* 0x30 */  bool mbAllowProps;
/* 0x31 */  bool mbWantRollingStart;
/* 0x32 */  bool mbEnableAftermath;
/* 0x33 */  bool mbAllowPlayerControlledCamera;
/* 0x34 */  bool mbAllowAftertouch;
/* 0x35 */  bool mbAllowCrashbreaker;
/* 0x36 */  bool mbRaceCarPicksUpCrashIndex;
/* 0x37 */  bool mbCarsBecomeFragileAfterBeingSlammed;
/* 0x38 */  bool mbAllowSlowMo;
/* 0x39 */  bool mbDoAfterTouchWithoutSlowMo;
/* 0x3A */  bool mbRaceCarsHaveCrashingPartsWhenDriving;
/* 0x3B */  bool mbDoSlowMoInAir;
/* 0x3C */  bool mbSlowMoOnlyForPlayerPlayerCollisions;
/* 0x3D */  bool mbPickupsAreEasierToGet;
/* 0x3E */  bool mbCrashBattleScoring;
/* 0x3F */  bool mbAudioFadesOutInOutro;
/* 0x40 */  bool mbAudioBlipsOnTimer;
/* 0x41 */  bool mbAudioOnNetworkPlayersJoinOrLeave;
/* 0x42 */  bool mbAudioOnExtraTakedowns;
/* 0x43 */  bool mbDisplayTeamName;
/* 0x44 */  bool mbOnlineRevenge;
/* 0x45 */  bool mbNetworkClientQuitEndsGame;
/* 0x46 */  bool mbSlamsAreSuperStrength;
/* 0x47 */  bool mbDisplayCheckTrafficPrompt;
/* 0x48 */  bool mbDisplayPressR1ToBoostPrompt;
/* 0x49 */  bool mbDisplayOnlineRoadRagePrompts;
/* 0x4A */  bool mbSendHealth;
/* 0x4B */  bool mbSendScoreSeparately;
/* 0x4C */  bool mbIsRoadRage;
/* 0x4D */  bool mbSendMoreTrafficOnline;
/* 0x4E */  bool mbDoCrashCarSelect;
/* 0x4F */  bool mbAIAllowedToResetOnPatches;
/* 0x50 */  bool mbDoCrashCountdownStart;
/* 0x51 */  bool mbDoCrashWaitButtonToStart;
/* 0x52 */  bool mbRatingUseGoldMedalThreshold;
/* 0x53 */  u8 __pad0;
/* 0x54 */  s32 meAssignStartPositionIndex[6];              // enum ERaceCarIndex
};

struct CB4TakedownManager // 0x28
{
    CB4RaceCar *mpCrashingCar;
    s32 meState;                              // enum ETDState
    s32 meRevengeState;                       // enum ERTDState
    float mrTimeSinceTakedownStarted;
    s32 mePlayerIndex;                        // enum EPlayerCarIndex
    s32 meTargetRaceCarIndex;                 // enum ERaceCarIndex
    s32 mnShotCount;
    s32 mnDesiredSlowMo;
    bool mbAIControlled;
    bool mbUseCamera;
    bool mbActive;
    bool mbWasBoosting;
    bool mbDoingSignatureTD;
    u8 __pad0[3];
};

struct CB4TakedownManagerSEM // 0x28
{
    float marLastDamageCriticalWarnTime;
    u8 __pad0[0x24];
};

struct CB4StageLogic // 0x11C
{
/* 0x000 */  u8 __pad0[0x3C];
/* 0x03C */  CB4StageLogicGameParams mGameParams;
/* 0x0A8 */  u8 __pad1[0x18];
/* 0x0C0 */  CB4TakedownManagerSEM maTakedownManagers[2];
/* 0x110 */  u8 __pad2[0xC];
};

struct CB4RaceCarResults // 0x16FC
{
    u8 __pad0[0x16FC];
};

struct CB4Challenge // 0xB160
{
    s32 mnStageIndex;
    s32 mnNumStages;
    CB4RaceSetupConfig maConfig[18];
    CB4RaceCarResults maResults[6];
    s32 mnWorstCrashParPossible;
    s32 meInitialRating;                // enum EB4ProgressionRating
    bool mbMenuExitSelected;
    u8 __pad0[3];
    void *__vtable;                     // struct CB4Challenge__vtable *
};

struct CB4GameMode // 0x10
{
    CB4StageLogic *mpStageLogic;
    CB4Challenge *mpChallenge;
    bool mbDoFullPrepare;
    u8 __pad0[3];
    void *__vtable;                 // struct CB4GameMode__vtable *
};

struct CB4OnePlayerStage // 0x14
{
    CB4GameMode mGameMode;
    s32 mePrepareState;             // enum EGtPrepareState
};

struct CB4MPRaceOptionsState // 0x18
{
    CGtState mState;
    EB4MenuChoicesMultiPlayer meMultiplayerMenuChoice;
    u8 __pad0[4];
};

struct CB4MPPartyOptionsState // 0x18
{
    CGtState mState;
    EB4MenuChoicesMultiPlayer meMultiplayerMenuChoice;
    u8 __pad0[4];
};

struct CB4TwoPlayerSplitScreenStage // 0x1C
{
/* 0x00 */  void *mpAptComponents;
/* 0x04 */  s8 me8State;
/* 0x05 */  s8 me8MenuType;
/* 0x06 */  s8 mn8NumAptUpdates;
/* 0x07 */  bool mbWelcomePopupShown;
/* 0x08 */  s8 mn8RivalSelection;
/* 0x09 */  s8 mn8TrafficOn;
/* 0x0A */  s8 me8TrafficCheckType;
/* 0x0B */  s8 mn8NumRivals;
/* 0x0C */  float mrTimeLimit;
/* 0x10 */  s8 mn8NumLaps;
/* 0x11 */  s8 mn8UseCrashbreaker;
/* 0x12 */  s8 mn8OncomingOn;
/* 0x13 */  s8 mn8DamageCritical;
/* 0x14 */  s8 me8AIMode;
/* 0x15 */  s8 mn8TATKTimeLimitOn;
/* 0x16 */  bool mbAptUpdatesDone;
/* 0x17 */  u8 __pad0[5];

/*
            struct CB4StageLogic *mpStageLogic;                       // Inherited from CB4GameMode
            struct CB4Challenge *mpChallenge;                         // Inherited from CB4GameMode
            bool mbDoFullPrepare;                                     // Inherited from CB4GameMode
            undefined field3_0x9;
            undefined field4_0xa;
            undefined field5_0xb;
            struct CB4TwoPlayerSplitScreenStage__vtable *__vtable;    // Inherited from CB4GameMode
            enum EGtPrepareState mePrepareState;
            int manWinPoints[2];
*/
};

struct CB4MenuFlowManager // 0x21E0
{
    /* 0x0000 */  CGtFSM mFSM;
    /* 0x0018 */  u8 __pad0[0x1980];
    /* 0x1998 */  CB4MPRaceOptionsState mMPRaceOptionsState;
    /* 0x19B0 */  u8 __pad1[0x828];
    /* 0x21D8 */  EB4MenuFlowType meMenuFlowType;
    /* 0x1998 */  u8 __pad2[4];
};

struct CB4Settings // 0x5C
{
    u8 __pad0[0x3A];
    bool mbAutoSaveIsOn;
    u8 __pad1[0x21];
    
/*
    unsigned char maun8SongFlags[40];
    signed char mabRumble[2];
    RwInt8 mn8ScreenOffsetX;
    RwInt8 mn8ScreenOffsetY;
    RwInt8 mbPad0;
    RwInt8 mn8SoundConfig;
    RwInt8 mn8SFXVolume;
    RwInt8 mn8MusicVolume;
    RwInt8 mn8DJVolume;
    RwInt8 mn8SongIndex;
    RwInt8 mn8SoundtrackIndex;
    RwInt8 mn8RadioOn;
    RwInt8 mbPlayModeRandom;
    RwInt8 mn8TakedownCamMode;
    RwInt8 mbCrashAutoSlowMo;
    signed char mabExternalCam[2];
    RwInt8 mbAutoSaveIsOn;
    RwInt8 mbViewedRaceTraining;
    RwInt8 mbViewedTrafficAttackTraining;
    RwInt8 mbViewedCrashTraining;
    RwInt8 mbViewedRoadRageTraining;
    RwInt8 mbViewedRevengeTraining;
    undefined field22_0x3f;
    enum EOptionServicePartySecurity mePartySecurity;
    enum EGtNetworkHeadsetOutputMode mePartyHeadsetOutputMode;
    bool mbPartyAppearanceOnline;
    char macPartyPassword[16];
    undefined field27_0x59;
    undefined field28_0x5a;
    undefined field29_0x5b;
*/
};

struct CB4GameState // 0x70
{
    CGtState mState;
    CB4Settings mOldSettings;
    s32 meSubState;              // enum EB4GameSubState
};

struct CB4NetworkManager // 0x23980
{
    u8 __pad0[0x23941];
    bool mbUppingInterface;
    u8 __pad1[0xF];
    bool mbIsOnline;
    u8 __pad2[0x2E];
};

struct AptBasePtrStack // 0xC
{
    s32 m_nElements;
    s32 m_nCapacity;
    void **m_aElements;
};

struct AptActionInterpreter // 0x60
{
    AptBasePtrStack stack;
    u8 __pad0[0x60];
};

struct CB4MultiplayerRoadRageLogic // 0x1A0
{
/* 0x000 */  CB4StageLogic mStageLogic;
/* 0x11C */  u8 __pad1[0x58];
/* 0x174 */  float mrEventEndTime;
/* 0x178 */  u8 __pad2[0x1C];
/* 0x194 */  bool mbPlayersCanBeDestroyed;
/* 0x195 */  bool mbDoGoFasterWarnings;
/* 0x196 */  bool mbTimerStarted;
/* 0x197 */  u8 __pad3[9];
};

struct CB4ActiveBody // 0x30
{
    u8 __pad0[0x20];     // CGtV3d maExtent[2]
    void *mpMatrix;      // CGtMatrix3x4 *
    void *mpBox;         // CGtAxisAlignedBox *
    void *mpBodyData;
    s8 meType;
    u8 mu8Index;
    bool mbRemove;
    u8 __pad1;
};

struct CB4TrafficVehicle // 0x1A0
{
/* 0x000 */  u8 __pad0[0x11C];
/* 0x11C */  CB4TrafficVehicle *mpCabVehicle;
/* 0x120 */  CB4TrafficVehicle *mpTrailerVehicle;
/* 0x124 */  u8 __pad1[0x63];
/* 0x187 */  s8 meClass;
/* 0x188 */  s8 mx8OtherFlags;
/* 0x189 */  u8 __pad2[7];
/* 0x190 */  CB4ActiveBody *mpTrafficBody;
/* 0x194 */  bool mbRemoveNextDecision;
/* 0x195 */  s8 mn8ImmediateChecking;
/* 0x196 */  u8 __pad3[0xA];
};

struct CB4VehiclePhysicsAttribs // 0xF8
{
    u64 mVehicleID;
    float mrDrivingMass;
    float mrCrashingMass;
    float mrFrontAttachHeight;
    float mrFrontSpringConstant;
    float mrFrontDampingConstant;
    float mrFrontSpringLength;
    float mrRearSpringConstant;
    float mrRearDampingConstant;
    float mrRearSpringLength;
    float mrRearAttachHeight;
    float mrRandomCrumpleFactor;
    float mrBouncyness;
    float marTotalDeformationRegionScalar[7];
    float marEnergyRegionScalar[7];
    void *mpBodyPartStrengths;                   // struct CB4VehicleBodyPartParams
    float mrVehicleVehicleDeformationFactor;
    char macPath[128];
};

struct CB4CollidingPair // 0x30
{
    u8 __pad0[0x20];
    float mrImpulse;
    CB4ActiveBody *mpBodyA;
    CB4ActiveBody *mpBodyB;
    bool mbCollision;
    u8 meCollisionType;
    u8 __pad1[0x2];
};

struct CB4CollidingBody // 0x220
{
/* 0x000 */  u8 __pad0[0x1E0];
/* 0x1E0 */  float mrMass;
/* 0x1E4 */  u8 __pad1[0x10];
/* 0x1F4 */  void *mpMatrix;
/* 0x1F8 */  u8 __pad2[7];
/* 0x1FF */  bool mbCrashing;
/* 0x200 */  u8 __pad3[5];
/* 0x205 */  s8 me8Type;
/* 0x206 */  u8 __pad4[2];
/* 0x208 */  u8 mu8CrashIndex;
/* 0x209 */  u8 __pad5[0x17];
};

struct CB4ConvexHull // 0x1C
{
/* 0x00 */  void *maPlaneVerts;     // CB4ConvexHullPlane *
/* 0x04 */  void *maPlanes;         // CGtPlane *
/* 0x08 */  CGtV3d *maVerts;
/* 0x0C */  void *maEdges;          // CB4ConvexHullEdge *
/* 0x10 */  void *maVertWeights;    // CB4ConvexHullVertMap *
/* 0x14 */  u32 mxFlags;
/* 0x18 */  u8 mu8NumVerts;
/* 0x19 */  u8 mu8NumPlanes;
/* 0x1A */  u8 mu8NumEdges;
/* 0x1B */  u8 __pad0;
};

struct CB4ConvexHullVehicle // 0x340
{
/* 0x000 */  CB4ConvexHull mConvexHull;
/* 0x01C */  u8 __pad0[0x324];
};

struct CB4HullCollideHullParams // 0x130
{
/* 0x000 */  CB4ConvexHull *mpHull;
/* 0x004 */  u8 __pad0[0x12C];
};

struct CB4HullCollideParams // 0x290
{
/* 0x000 */  CB4HullCollideHullParams mHullA;
/* 0x130 */  CB4HullCollideHullParams mHullB;
/* 0x260 */  u8 __pad[0x30];
};

struct CB4VehiclePhysics // 0x12E0
{
/* 0x000 */  CB4CollidingBody mCollidingBody;
/* 0x220 */  CB4ConvexHullVehicle mBoundingHull;
/* 0x560 */  u8 __pad2[0xD80];
};

struct CB4TrafficPhysics // 0x3740
{
/* 0x0000 */  CB4VehiclePhysics mVehiclePhysics;
/* 0x12E0 */  u8 __pad0[0x2430];
/* 0x3710 */  ETrafficVehicleCategories meClass;
/* 0x3714 */  CB4TrafficPhysics *mpArticLinkedVehicle;
/* 0x3718 */  bool mbIsTrailer;
/* 0x3719 */  u8 mu8TrafficID;
/* 0x371A */  u8 mu8TrafficSourceIndex;
/* 0x371B */  s8 me8OwnerIndex;
/* 0x371C */  bool mbInRange;
/* 0x371D */  u8 __pad1[3];
/* 0x3720 */  s32 meCheckingRaceCar;
/* 0x3724 */  u8 __pad2[0x10];
/* 0x3734 */  float mrRemainingDeadlyTime;
/* 0x3738 */  s8 mn8ImmediateChecking;
/* 0x3739 */  u8 __pad3[7];
};

struct CB4RaceCarPhysics // 0x2E40
{
/* 0x0000 */  CB4VehiclePhysics mVehiclePhysics;
/* 0x12E0 */  u8 __pad0[0x220];
/* 0x1500 */  CB4RaceCar *mpRaceCar;
/* 0x1504 */  u8 __pad1[0x193C];
};

struct CB4PlayerCarPhysics // 0x7260
{
/* 0x0000 */  CB4RaceCarPhysics mRaceCarPhysics;
/* 0x2E40 */  u8 __pad0[0x4420];
};

struct CB4LapManager // 0xD0
{
/* 0x00 */  u8 __pad0[0xC];
/* 0x0C */  float mrTimeTaken;
/* 0x10 */  float mrDistanceTravelled;
/* 0x14 */  s32 mnLapsCompleted;
/* 0x18 */  s32 mnBestRacePosition;
/* 0x1C */  float mrFastestLapTime;
/* 0x20 */  EB4ScoreRaceCarState meRaceState;
/* 0x24 */  u8 __pad1[0x70];
/* 0x94 */  s32 mnMaxLaps;
/* 0x98 */  float mrCurrentLapTime;
/* 0x9C */  float mrLastLapTotalRaceTime;
/* 0xA0 */  u8 __pad2[0x28];
/* 0xC8 */  s32 mnRealLapsCompleted;
/* 0xCC */  s32 mnRealMaxLaps;
};

struct CB4OffensiveDrivingManager // 0x440
{
/* 0x000 */  CB4RaceCar *mpRaceCar;
/* 0x004 */  u8 __pad0[0x260];
/* 0x264 */  ESlamShuntComboState meMinSlamShuntComboState;
/* 0x268 */  u8 __pad1[0x1BC];
/* 0x424 */  float mrHealth;
/* 0x428 */  u8 __pad2[0x18];
};

struct CB4RaceCar // 0x2CC0
{
/* 0x0000 */  u8 __pad0[0x24E0];
/* 0x24E0 */  CB4LapManager mLapManager;
/* 0x25B0 */  CB4OffensiveDrivingManager mOffensiveDrivingManager;
/* 0x29F0 */  u8 __pad1[0x220];
/* 0x2C10 */  EB4RaceCarType meRaceCarType;
/* 0x2C14 */  u8 __pad2[0x94];
/* 0x2CA8 */  s8 mn8RaceCarIndex;
/* 0x2CA9 */  u8 __pad3[0x17];
};

struct CB4AIDriver // 0xA80
{
/* 0x000 */  u8 __pad0[0x7E0];
/* 0x7E0 */  CB4AICar *mpCar;
/* 0x7E4 */  u8 __pad1[0x28C];
/* 0xA70 */  EDriverTakedownDifficulty meTakedownDifficulty;
/* 0xA74 */  u8 __pad2[0xC];
};

struct CB4AICar // 0x37B0
{
/* 0x0000 */  CB4RaceCar mRaceCar;
/* 0x2CC0 */  u8 __pad0[0x40];
/* 0x2D00 */  CB4AIDriver mDriver;
/* 0x3780 */  CB4RaceCarPhysics *mpPhysics;    // actually CB4AICarPhysics
/* 0x3784 */  u8 __pad1[0x2C];
};

struct CB4PlayerCar // 0x3B30
{
/* 0x0000 */  CB4AICar mAICar;
/* 0x37B0 */  u8 __pad0[0x380];
};

struct CB4CrashActionDirector // 0x3E0
{
    bool mabRaceBreakerExtension[0xF];
    s8 man8CrashOwners[0xF];
    u8 __pad0[0x3C2];
};

struct CB4ProfileStatistics // 0x8D0
{
    float marFastestLaps[52];
    u8 __pad0[0x800];
};

struct CB4HUDBurningLapTimer // 0x5C
{
    u8 __pad0[0x5C];
};

struct CB4HUDBurningLap // 0xA8
{
/* 0x00 */  u8 __pad0[0x38];
/* 0x38 */  float marMedalThresholdTimes[3];
/* 0x44 */  u8 __pad1[0x64];
};

struct CB4HUDHitCount // 0x48
{
/* 0x00 */  u8 __pad0[0x30];
/* 0x30 */  s32 mnNumHits;
/* 0x34 */  s32 mnTargetNumHits;
/* 0x38 */  u8 __pad1[0x10];
};

struct CB4SingleRevengeLogic // 0x170
{
/* 0x000 */  CB4StageLogic mStageLogic;
/* 0x11C */  u8 __pad0[0x38];
/* 0x154 */  bool mbTimerStarted;
/* 0x155 */  u8 __pad1[0x1B];
};

// SLUS, SLES, SLKA, SLAJ
struct CB4AptManager // 0x5650
{
/* 0x0000 */  u8 __pad0[0x5636];
/* 0x5636 */  bool mbEnabled;
/* 0x5637 */  u8 __pad1[2];
/* 0x5639 */  bool mbEnableVideoRendering;
/* 0x563A */  u8 __pad2[0x16];
};

// SLPM
// struct CB4AptManager // 0x5630
// {
// /* 0x0000 */  u8 __pad0[0x5616];
// /* 0x5616 */  bool mbEnabled;
// /* 0x5617 */  u8 __pad1[2];
// /* 0x5619 */  bool mbEnableVideoRendering;
// /* 0x561A */  u8 __pad2[0x16];
// };


struct CB4TrackList // 0x1000
{
/* 0x0000 */  u8 __pad0[0x1000];
};

struct CB4HUDManager // 0x5E0
{
/* 0x0000 */  u8 __pad0[0x5E0];
};

struct CB4HUDTrafficAttackScore // 0x2B8
{
/* 0x000 */  u8 __pad0[0x90];
/* 0x090 */  s32 mnCurrentDisplayScore;
/* 0x094 */  u8 __pad1[0x224];
};

struct CGTFile__vtable // 0x48
{
/* 0x00 */  u8 __pad0[0xC];
/* 0x0C */  CGTFile *(*Open)(CGTFile *lpThis, void *lpFileSystem, char *lpcFilename, u32 luOpenFlags);
/* 0x10 */  u8 __pad1[4];
/* 0x14 */  void (*Close)(CGTFile *lpThis);
/* 0x18 */  u8 __pad2[4];
/* 0x1C */  u32 (*Read)(CGTFile *lpThis, void *lpBuffer, u32 luBytesToRead);
/* 0x20 */  u8 __pad3[4];
/* 0x24 */  u32 (*Write)(CGTFile *lpThis, void *lpBuffer, u32 luBytesToWrite);
/* 0x28 */  u8 __pad4[4];
/* 0x2C */  s64 (*SetPosition)(CGTFile *lpThis, s64 lnOffset, EFileMoveMethod ePosition);
/* 0x30 */  u8 __pad5[4];
/* 0x34 */  EFileStatus (*Sync)(CGTFile *lpThis, s32 lbBlock);
/* 0x38 */  u8 __pad6[4];
/* 0x3C */  s32 (*Abort)(CGTFile *lpThis);
/* 0x40 */  u8 __pad7[4];
/* 0x44 */  EFileStatus (*GetStatus)(CGTFile *lpThis);
/* 0x48 */  u8 __pad8[4];
};

struct CGTFile // 0x30
{
/* 0x00 */  void *mpFileSys;                 // struct CGTFileSystem *
/* 0x04 */  u8 __pad0[4];
/* 0x08 */  s64 mnFileLength;
/* 0x10 */  s64 mnFilePosition;
/* 0x18 */  EFileStatus mnStatus;
/* 0x1C */  EFileError mnError;
/* 0x20 */  s32 mbAsynchronousFile;
/* 0x24 */  s32 mnPriority;
/* 0x28 */  struct CGTFile__vtable *vtbl;
/* 0x2C */  u8 __pad1[4];
};

#pragma pack(0)

#endif
