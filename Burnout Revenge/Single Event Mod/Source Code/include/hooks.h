#ifndef HOOKS_H
#define HOOKS_H

#include "types.h"
#include "game_enums.h"
#include "game_structs.h"

void CB4PhysicsManager__BodyBodyResponse_DeformVehicle_Hook(void *lpThis, CB4ActiveBody *lpBodyA, CB4ActiveBody *lpBodyB, u128 lCollisionPoint, u128 lNormalA, float lrEnergy, float lrForce, float *lprAbsorbedEnergy);
void CB4MultiplayerRoadRageLogic__UpdateAIPositions_Hook(CB4MultiplayerRoadRageLogic *lpThis);
s32 CB4BurningLapLogic__GetNumLaps_Hook(void *lpThis);
s32 CB4SingleRaceLogic__GetNumLaps_Hook(void *lpThis);
void CGtInputManagerPS2Pad2__Update_Hook(void *lpThis);
void CB4PopupManagerService__RequestPopup_Hook(void *lpThis, char *lpcTitle, char *lpcText, EB4PopupType leType, void *lpfCallback, void *lpUserData, EB4PopupButton leDefaultButton);
void CGtTimer__Stop_Hook(void *lpThis);
void CB4StageLogic__MenuExit_Hook(void *lpThis, bool lbQuitFromPauseMenu);
void CB4SingleRevengeLogic__OnIntroCameraFinished_Hook(CB4SingleRevengeLogic *lpThis);
bool CB4HUDTrafficAttackBar__Prepare_Hook(CB4HUDHitCount *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags);
bool CB4HUDLap__Prepare_Hook(void *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags, bool lbCompact);
s32 GetAIMode_Hook(void *lpThis);
void CB4HUDBurningLap__Update_Hook(CB4HUDBurningLap *lpThis, float lrTimeStep);
void CB4HUDBurningLapTimer__Update_Hook(CB4HUDBurningLapTimer *lpThis, float lrTimeStep);
s32 CB4BurningLapLogic__GetCheckpointMarkerFlags_Hook(void *lpThis);
void CB4BurningLapLogic__OnRaceCarStartNewLap_Hook(void *lpThis, CB4RaceCar *lpRaceCar);
void CB4GameData__GetGameDataThreshold_f_Hook(void *lpThis ,float *lprBronze, float *lprSilver, float *lprGold);
int strcasecmpBurningLap_Hook(const char *s1, const char *s2);
bool CB4HUDTrafficAttackScore__Prepare_Hook(void *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags, bool lbDisplayMedalTarget);
void CB4AIAvoidanceMap__CheckTraffic_Hook(void *lpThis);
void CB4PhysicsManager__BodyBodyResponse_Hook2(void *lpThis, CB4CollidingPair *lpPair, bool lbFirstHit);
void CB4PhysicsManager__BodyBodyResponse_Hook(void *lpThis, CB4CollidingPair *lpPair, bool lbFirstHit);
bool CB4PhysicsManager__CanCheckTraffic_Hook(void *lpThis, CB4CollidingPair *lpPair, CB4RaceCarPhysics *lpRaceCarPhysics, CB4TrafficVehicle *lpTrafficVehicle);
float CB4MultiplayerRoadRageLogic__GetTimeRemaining_Hook(CB4MultiplayerRoadRageLogic *lpThis);
void CB4MultiplayerRoadRageLogic__OnIntroCameraFinished_Hook(CB4MultiplayerRoadRageLogic *lpThis);
bool CB4HUDRoadRageTimer__Prepare_Hook(void *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags, bool lbCompact);
ERacePositionType GetRacePositionType_Hook(void *lpThis);
u16 *CB4LanguageManager__FindString_Hook(CB4LanguageManager *lpThis, char *lpcStringID);
bool CB4StageLogic__EventSummaryAptCall_Hook(char *lpcTitleStringID, char *lpcMessageStringID, u16 *lpGoldThresholdString, u16 *lpSilverThresholdString, u16 *lpBronzeThresholdString, bool lbDoShowContinueButton);
bool CB4OnePlayerStage__Prepare_Hook(CB4OnePlayerStage *lpThis);
CB4GameMode *CB4MenuChoices__RequestOnePlayerGameMode_Hook(CB4MenuChoices *lpThis);
void CB4CarSelectService__GetTitles_Hook(void *lpThis, char *lpcTitle, char *lpcSubTitle);
void CB4CarSelectManager__SetNextState_Hook(void *lpThis, u64 lNextState, void *lpNextUserData);
void CB4MPCrashOptionsState__OnActionEnter_Hook(CB4MPCrashOptionsState *lpThis, EGtStateAction leAction, void *lpOwner, void *lpActionData, void *lpUserData);
void CB4MPRaceOptionsState__OnActionPageSelectEvent_Hook(CB4MPRaceOptionsState *lpThis, EMultiplayerButton leButton);
void CB4MPRaceOptionsState__OnActionEnter_Hook(CB4MPRaceOptionsState *lpThis, EGtStateAction leAction, void *lpOwner, void *lpActionData, void *lpUserData);
void CB4MultiplayerState__OnActionPageSelectEvent_Hook(void *lpThis, EMultiplayerButton leButton);
void CB4MultiplayerState__OnActionEnter_Hook(void *lpThis, EGtStateAction leAction, void *lpOwner, void *lpActionData, void *lpUserData);
void CB4MainMenuState__Action_Hook(CB4MainMenuState* lpThis, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData);
void AptUpdate_Hook(unsigned int nDeltaTime);

#endif
