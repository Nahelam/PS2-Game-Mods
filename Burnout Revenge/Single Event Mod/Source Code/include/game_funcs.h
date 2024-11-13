#ifndef GAME_FUNCS_H
#define GAME_FUNCS_H

#include "game_structs.h"
#include "game_enums.h"

extern void sceMc2Init();
extern void *_memset(void *__s, int __c, u32 __n);
extern void FlushCache(int mode);
extern CGTFile *CGTFileSystem__Open(void *lpThis, char *lpcFilename, u32 luOpenFlags);
extern void CB4PhysicsManager__BodyBodyResponse_DeformVehicle(void *lpThis, CB4ActiveBody *lpBodyA, CB4ActiveBody *lpBodyB, u128 lCollisionPoint, u128 lNormalA, float lrEnergy, float lrForce, float *lprAbsorbedEnergy);
extern void AptUpdate(unsigned int nDeltaTime);
extern void *_AptGetAnimationAtLevel(int nLevel);
extern void EAStringC__Ctor(AptNativeString *lpThis, char *pStrText);
extern void EAStringC__Dtor(AptNativeString *lpThis, int __in_chrg);
extern void *AptActionInterpreter__getVariable(AptActionInterpreter *lpThis, void *pCurrentContext, void *pWith, AptNativeString *pVarName, int bGlobal, int bLookInFunctionScope, int bIsMember);
extern bool AptActionInterpreter__setVariable(AptActionInterpreter *lpThis, void *pCurrentContext, void *pWith, AptNativeString *pVarName, void *pValue, int bGlobal, int bLookInFunctionScope, int bIsMember);
extern void AptArray__set(void *lpThis, int nIndex, void *pValue);
extern void *AptArray__get(void *lpThis, int nIndex);
extern int  AptValue__toInteger(void *lpThis);
extern bool AptValue__toBool(void *lpThis);
extern void AptValue__toString(void *lpThis, char *szBuf);
extern int  _sprintf(char *s, char *format, ...);
extern u16  *CGtHashIDStringArray__GetString(CGtHashIDStringArray *lpThis, s32 lnHashID);
extern void *UTF16StringToAptString(u16 *lpString);
extern void *AptInteger__Create(int nValue);
extern void _itoa(int n, char *dst, int base);
extern void AptCallFunction(char *szName, char *szReturnValue, char *szThisObject, int nNumParams, ...);
extern void CGtUnicode__ConvertUTF16toUTF8Fast(u16 *lpaSource, u8 *lpaTarget, s32 lnTargetLength);
extern void *AptActionInterpreter__doCloneSprite(AptActionInterpreter *lpThis, void *pCurrentCIH, void *pWith, void *pSource, void *pTarget, int nDepthInt, void *pInitObject);
extern void *AptValueGC_PoolManager__AllocateAptValueGC(void *lpThis, u32 nAllocatedSize);
extern void *AptArray__AptArray(void *lpThis);
extern void *AptString__Create(char *szValue);
extern void CB4PopupManagerService__RequestPopup(void *lpThis, char *lpcTitle, char *lpcText, EB4PopupType leType, void *lpfCallback, void *lpUserData, EB4PopupButton leDefaultButton);
extern CGtState *CGtFSM__GetStateFromID(CGtFSM* lpThis, u64 lStateID);
extern void CGtFSM__StateLeave(CGtFSM* lpThis, CGtState* lpNewState, void* lpUserData);
extern void CGtFSM__StateEnter(CGtFSM* lpThis, CGtState* lpOldState, void* lpUserData);
extern void CB4MainMenuState__Action(CB4MainMenuState* lpThis, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
extern void CB4MultiplayerState__OnActionEnter(CB4MultiplayerState *lpThis, EGtStateAction leAction, void *lpOwner, void *lpActionData, void *lpUserData);
extern void CB4MultiplayerState__OnActionPageSelectEvent(void *lpThis, EMultiplayerButton leButton);
extern void CB4MPRaceOptionsState__OnActionEnter(CB4MPRaceOptionsState *lpThis, EGtStateAction leAction, void *lpOwner, void *lpActionData, void *lpUserData);
extern void CB4MPRaceOptionsState__OnActionPageSelectEvent(CB4MPRaceOptionsState *lpThis, EMultiplayerButton leButton);
extern void CB4MPCrashOptionsState__OnActionEnter(CB4MPCrashOptionsState *lpThis, EGtStateAction leAction, void *lpOwner, void *lpActionData, void *lpUserData);
extern void CB4CarSelectManager__SetNextState(void *lpThis, u64 lNextState, void *lpNextUserData);
extern void CB4CarSelectService__GetTitles(void *lpThis, char *lpcTitle, char *lpcSubTitle);
extern CB4GameMode *CB4MenuChoices__RequestOnePlayerGameMode(CB4MenuChoices *lpThis);
extern u64 CB4MenuChoices__GetDriverCarID(CB4MenuChoices *lpThis, void *lpStage, u64 lPlayerCarID, s32 lnDriverIndex, s32 lnAICarIndex, u64 *lpaCarIDs, s32 lnIDArraySize);
extern bool CB4OnePlayerStage__Prepare(CB4OnePlayerStage *lpThis);
extern bool CB4StageLogic__EventSummaryAptCall(char *lpcTitleStringID, char *lpcMessageStringID, u16 *lpGoldThresholdString, u16 *lpSilverThresholdString, u16 *lpBronzeThresholdString, bool lbDoShowContinueButton);
extern u16 *CB4LanguageManager__FindString(CB4LanguageManager *lpThis, char *lpcStringID);
extern bool CB4HUDRoadRageTimer__Prepare(void *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags, bool lbCompact);
extern void CB4MultiplayerRoadRageLogic__OnIntroCameraFinished(CB4MultiplayerRoadRageLogic *lpThis);
extern float CB4MultiplayerRoadRageLogic__GetTimeRemaining(CB4MultiplayerRoadRageLogic *lpThis);
extern bool CB4PhysicsManager__CanCheckTraffic(void *lpThis, void *lpPair, CB4RaceCarPhysics *lpRaceCarPhysics, void *lpTrafficVehicle);
extern void CB4PhysicsManager__BodyBodyResponse(void *lpThis, CB4CollidingPair *lpPair, bool lbFirstHit);
extern void CB4PhysicsManager__VehicleTrafficResponse(void *lpThis, CB4CollidingPair *lpPair);
extern void CB4AIAvoidanceMap__CheckTraffic(void *lpThis);
extern bool CB4HUDTrafficAttackScore__Prepare(CB4HUDTrafficAttackScore *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags, bool lbDisplayMedalTarget);
extern int _strcasecmp(const char *s1, const char *s2);
extern void CB4GameData__GetGameDataThreshold_f(void *lpThis ,float *lprBronze, float *lprSilver, float *lprGold);
extern s32 CB4TrackList__GetTrackIndexFromID(CB4TrackList *lpThis, u64 lTrackID);
extern s32 CB4BurningLapLogic__GetNumLaps(void *lpThis);
extern void CB4BurningLapLogic__OnRaceCarStartNewLap(void *lpThis, CB4RaceCar *lpRaceCar);
extern void CB4HUDBurningLap__CreateMedalTimeStrings(CB4HUDBurningLap *lpThis);
extern void CB4HUDBurningLap__UpdateDisplay(CB4HUDBurningLap *lpThis, s32 leMedalToDisplay);
extern void CB4StageLogic__OnRaceCarStartNewLap(void *lpThis, CB4RaceCar *lpRaceCar);
extern s32 CB4BurningLapLogic__GetCheckpointMarkerFlags(void *lpThis);
extern void CB4HUDBurningLapTimer__Update(CB4HUDBurningLapTimer *lpThis, float lrTimeStep);
extern void CB4HUDBurningLap__Update(CB4HUDBurningLap *lpThis, float lrTimeStep);
extern bool CB4HUDLap__Prepare(void *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags, bool lbCompact);
extern bool CB4HUDHitCount__Prepare(CB4HUDHitCount *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags);
extern bool CB4HUDTrafficAttackBar__Prepare(CB4HUDHitCount *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags);
extern void CB4SingleRevengeLogic__OnIntroCameraFinished(CB4SingleRevengeLogic *lpThis);
extern void CB4HUDMessageManager__OnRaceCarElimination(void *lpThis, s32 lnCarPlacing);
extern void CB4SingleRaceLogic__HandleAdjustedAIPositions(void *lpThis);
extern void CB4PhysicsManager__CalculateAndApplyCheckingImpulse(void *lpThis, CB4VehiclePhysics *lpCheckerPhysics, CB4VehiclePhysics *lpVictimPhysics, CB4CollidingPair *lpPair, void *lpCollideParams, bool lbTreatAsStationaryCheck);
extern void CGtTimer__Stop(void *lpThis);
extern void CGtInputManagerPS2Pad2__Update(void *lpThis);
extern void CB4PlayerCar__SetAIControlled(CB4PlayerCar *lpThis, bool lbAIControlled);
extern s32 CB4StageLogic__GetNumLaps(void *lpThis);
extern s32 CB4EliminatorLogic__GetNumLaps(void *lpThis);
extern void CB4MultiplayerRoadRageLogic__UpdateAIPositions(CB4MultiplayerRoadRageLogic *lpThis);
extern bool CB4HUDMessageManager__OnEvent(void *lpThis, s32 leEvent, s32 lnScore, s32 lxScoreMode, bool lbShowWhenCrashing, bool lbIsRevengeAttack, s32 lnNumStars);

#endif
