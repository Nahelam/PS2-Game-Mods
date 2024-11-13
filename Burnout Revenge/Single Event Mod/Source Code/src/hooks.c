#include "hooks.h"
#include "apt.h"
#include "utils.h"
#include "types.h"
#include "macros.h"
#include "game_funcs.h"
#include "game_vars.h"
#include "game_enums.h"

void CB4PhysicsManager__BodyBodyResponse_DeformVehicle_Hook(void *lpThis, CB4ActiveBody *lpBodyA, CB4ActiveBody *lpBodyB, u128 lCollisionPoint, u128 lNormalA, float lrEnergy, float lrForce, float *lprAbsorbedEnergy)
{
    if (lpBodyA && lpBodyB)
    {
        CB4PhysicsManager__BodyBodyResponse_DeformVehicle(lpThis, lpBodyA, lpBodyB, lCollisionPoint, lNormalA, lrEnergy, lrForce, lprAbsorbedEnergy);
    }
}

void CB4MultiplayerRoadRageLogic__UpdateAIPositions_Hook(CB4MultiplayerRoadRageLogic *lpThis)
{
    if (gSingleEvent.mn8DamageCritical
        && gaPlayerCars[0].mAICar.mRaceCar.mOffensiveDrivingManager.mrHealth <= 0.15f
        && grWorldTime > (lpThis->mStageLogic.maTakedownManagers[1].marLastDamageCriticalWarnTime + 30.0f))
    {
        CB4HUDMessageManager__OnEvent(&gHUDManager, 0xA3, 0, 2, true, false, -1);
        lpThis->mStageLogic.maTakedownManagers[1].marLastDamageCriticalWarnTime = grWorldTime;
    }
    CB4MultiplayerRoadRageLogic__UpdateAIPositions(lpThis);
}

s32 CB4BurningLapLogic__GetNumLaps_Hook(void *lpThis)
{
    return (gSingleEvent.me8State == eSingleEventState_InGame) ? 0 : CB4BurningLapLogic__GetNumLaps(lpThis);
}

s32 CB4SingleRaceLogic__GetNumLaps_Hook(void *lpThis)
{
    s32 lnNumLaps;

    if (gSingleEvent.me8State == eSingleEventState_InGame)
    {
        lnNumLaps = (gSingleEvent.mn8NumLaps > 8) ? 8 : gSingleEvent.mn8NumLaps;
    }
    else
    {
        lnNumLaps = CB4StageLogic__GetNumLaps(lpThis);
    }

    return lnNumLaps;
}

void CGtInputManagerPS2Pad2__Update_Hook(void *lpThis)
{
    if (!gSingleEvent.mbAptUpdatesDone && gSingleEvent.me8MenuType > eSingleEventMenuType_None)
    {
        __asm__
        {
            // addiu ra, ra, 0x1C4
            .word 0x27FF01C4
        }
    }
    else
    {
        __asm__
        {
            j CGtInputManagerPS2Pad2__Update
        }
    }
}

void CB4PopupManagerService__RequestPopup_Hook(void *lpThis, char *lpcTitle, char *lpcText, EB4PopupType leType, void *lpfCallback, void *lpUserData, EB4PopupButton leDefaultButton)
{
    if (gSingleEvent.me8State == eSingleEventState_InGame && OfferEndSessionRatherThanQuit())
    {
        lpcTitle = COLL_STR_EVENT_FINISHED;
        lpcText = COLL_STR_ARE_YOU_SURE;
    }
    CB4PopupManagerService__RequestPopup(lpThis, lpcTitle, lpcText, leType, lpfCallback, lpUserData, leDefaultButton);
}

void CGtTimer__Stop_Hook(void *lpThis)
{
    CB4SingleEvent *lpSingleEvent;

    lpSingleEvent = &gSingleEvent;
    if (lpSingleEvent->me8State == eSingleEventState_InGame && OfferEndSessionRatherThanQuit())
    {
        lpSingleEvent->mpAptComponents = NULL;
        lpSingleEvent->mn8NumAptUpdates = 0;
        lpSingleEvent->mbAptUpdatesDone = false;
    }
    CGtTimer__Stop(lpThis);
}

void CB4StageLogic__MenuExit_Hook(void *lpThis, bool lbQuitFromPauseMenu)
{
    typedef void (*CB4StageLogic__OnRaceCarFinish_t)(void *lpThis, CB4RaceCar *lpRaceCar, s32 leFinishState);
    typedef void (*CB4StageLogic__MenuExit_t)(void *lpThis, bool lbQuitFromPauseMenu);

    CB4StageLogic__MenuExit_t lpfMenuExit;
    void *lpVtable;

    __asm__
    {
        daddu lpfMenuExit, v0, zero
        daddu lpVtable, v1, zero
    }

    if (gSingleEvent.me8State == eSingleEventState_InGame && OfferEndSessionRatherThanQuit())
    {
        gAptManager.mbEnabled = false;

        ((CB4StageLogic__OnRaceCarFinish_t)(((u32 *)lpVtable)[0x57]))(lpThis, (CB4RaceCar *)(&gaPlayerCars[0]), 5);
        CB4PlayerCar__SetAIControlled(&gaPlayerCars[0], true);
        __asm__
        {
            ld     at, 0x40(sp)
            daddiu at, at, 0x10
            sd     at, 0x40(sp)
        }
    }
    else
    {
        lpfMenuExit(lpThis, lbQuitFromPauseMenu);
    }
}

void CB4SingleRevengeLogic__OnIntroCameraFinished_Hook(CB4SingleRevengeLogic *lpThis)
{
    CB4SingleRevengeLogic__OnIntroCameraFinished(lpThis);
    if (gSingleEvent.me8State == eSingleEventState_InGame && gSingleEvent.mn8TATKTimeLimitOn == 0)
    {
        lpThis->mbTimerStarted = false;
    }
}

bool CB4HUDTrafficAttackBar__Prepare_Hook(CB4HUDHitCount *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags)
{
    return !(gSingleEvent.me8State == eSingleEventState_InGame && gSingleEvent.mn8TATKTimeLimitOn == 0) ? CB4HUDTrafficAttackBar__Prepare(lpThis, lePlayer, leAlign, lxFlags) : true;
}

bool CB4HUDLap__Prepare_Hook(void *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags, bool lbCompact)
{
    if (gSingleEvent.me8State == eSingleEventState_InGame)
    {
        gaPlayerCars[0].mAICar.mRaceCar.mLapManager.mnRealLapsCompleted = 0;
        gaPlayerCars[0].mAICar.mRaceCar.mLapManager.mnRealMaxLaps = gSingleEvent.mn8NumLaps;
        return CB4HUDHitCount__Prepare(&gHitCountComponent, lePlayer, leAlign, lxFlags);
    }
    else
    {
        return CB4HUDLap__Prepare(lpThis, lePlayer, leAlign, lxFlags, lbCompact);
    }
}

s32 GetAIMode_Hook(void *lpThis)
{
    __asm__
    {
        daddu a4, v0, zero
    }

    if (gSingleEvent.me8State == eSingleEventState_InGame)
    {
        return gSingleEvent.me8AIMode;
    }
    else
    {
        __asm__
        {
            jr a4
        }
    }
}

void CB4HUDBurningLap__Update_Hook(CB4HUDBurningLap *lpThis, float lrTimeStep)
{
    if (!(gSingleEvent.me8State == eSingleEventState_InGame))
    {
        CB4HUDBurningLap__Update(lpThis, lrTimeStep);
    }
}

void CB4HUDBurningLapTimer__Update_Hook(CB4HUDBurningLapTimer *lpThis, float lrTimeStep)
{
    if (!(gSingleEvent.me8State == eSingleEventState_InGame
          && gaPlayerCars[0].mAICar.mRaceCar.mLapManager.mrLastLapTotalRaceTime > 10.0f
          && gaPlayerCars[0].mAICar.mRaceCar.mLapManager.mrCurrentLapTime < 5.0f))
    {
        CB4HUDBurningLapTimer__Update(lpThis, lrTimeStep);
    }
}

s32 CB4BurningLapLogic__GetCheckpointMarkerFlags_Hook(void *lpThis)
{
    return (gSingleEvent.me8State == eSingleEventState_InGame) ? 0x12 : CB4BurningLapLogic__GetCheckpointMarkerFlags(lpThis);
}

void CB4BurningLapLogic__OnRaceCarStartNewLap_Hook(void *lpThis, CB4RaceCar *lpRaceCar)
{
    CB4HUDBurningLap *lpBurningLapComponent;

    lpBurningLapComponent = &gBurningLapComponent;
    if (gSingleEvent.me8State == eSingleEventState_InGame)
    {
        if (lpBurningLapComponent->marMedalThresholdTimes[2] <= 0.0f || lpRaceCar->mLapManager.mrFastestLapTime < lpBurningLapComponent->marMedalThresholdTimes[2])
        {
            lpBurningLapComponent->marMedalThresholdTimes[2] = lpRaceCar->mLapManager.mrFastestLapTime;
            CB4HUDBurningLap__CreateMedalTimeStrings(lpBurningLapComponent);
            CB4HUDBurningLap__UpdateDisplay(lpBurningLapComponent, 2);
        }
        CB4StageLogic__OnRaceCarStartNewLap(lpThis, lpRaceCar);
    }
    else
    {
        CB4BurningLapLogic__OnRaceCarStartNewLap(lpThis, lpRaceCar);
    }
}

void CB4GameData__GetGameDataThreshold_f_Hook(void *lpThis ,float *lprBronze, float *lprSilver, float *lprGold)
{
    CB4GameData__GetGameDataThreshold_f(lpThis, lprBronze, lprSilver, lprGold);

    if (gSingleEvent.me8State == eSingleEventState_InGame)
    {
        *lprGold = gProfileStatistics.marFastestLaps[CB4TrackList__GetTrackIndexFromID(&gTrackList, gMenuChoices.mTrackID)];
    }
}

int strcasecmpBurningLap_Hook(const char *s1, const char *s2)
{
    return (gSingleEvent.me8State == eSingleEventState_InGame) ? _strcasecmp(s1, (const char *)&gpacCrownStr) : _strcasecmp(s1, s2);
}

bool CB4HUDTrafficAttackScore__Prepare_Hook(void *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags, bool lbDisplayMedalTarget)
{
    if (gSingleEvent.me8State == eSingleEventState_InGame)
    {
        lbDisplayMedalTarget = false;
    }
    return CB4HUDTrafficAttackScore__Prepare(lpThis, lePlayer, leAlign, lxFlags, lbDisplayMedalTarget);
}

void CB4AIAvoidanceMap__CheckTraffic_Hook(void *lpThis)
{
    if (!(gSingleEvent.me8State == eSingleEventState_InGame
        && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full))
    {
        CB4AIAvoidanceMap__CheckTraffic(lpThis);
    }
}

void CB4PhysicsManager__BodyBodyResponse_Hook2(void *lpThis, CB4CollidingPair *lpPair, bool lbFirstHit)
{
    if (gSingleEvent.me8State == eSingleEventState_InGame
        && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full
        && lpPair->mpBodyB->meType == eABT_CrashingTraffic
        && (lpPair->mpBodyA->meType == eABT_PlayerCar || (lpPair->mpBodyA->meType == eABT_AICar && ((CB4TrafficPhysics *)lpPair->mpBodyB->mpBodyData)->meCheckingRaceCar != gaPlayerCars[0].mAICar.mRaceCar.mn8RaceCarIndex)))
    {
        gCrashActionDirector.man8CrashOwners[((CB4TrafficPhysics *)lpPair->mpBodyB->mpBodyData)->mVehiclePhysics.mCollidingBody.mu8CrashIndex] = ((CB4RaceCarPhysics *)lpPair->mpBodyA->mpBodyData)->mpRaceCar->mn8RaceCarIndex;
        ((CB4TrafficPhysics *)lpPair->mpBodyB->mpBodyData)->me8OwnerIndex = ((CB4RaceCarPhysics *)lpPair->mpBodyA->mpBodyData)->mpRaceCar->mn8RaceCarIndex;
        ((CB4TrafficPhysics *)lpPair->mpBodyB->mpBodyData)->mn8ImmediateChecking = 2;
        CB4PhysicsManager__VehicleTrafficResponse(lpThis, lpPair);
    }
    else
    {
        CB4PhysicsManager__BodyBodyResponse(lpThis, lpPair, lbFirstHit);
    }
}

void CB4PhysicsManager__BodyBodyResponse_Hook(void *lpThis, CB4CollidingPair *lpPair, bool lbFirstHit)
{
    if (gSingleEvent.me8State == eSingleEventState_InGame
        && gSingleEvent.me8TrafficCheckType == eTrafficCheckType_Full
        && lpPair->mpBodyA->meType == eABT_CrashingTraffic
        && ((CB4TrafficPhysics *)lpPair->mpBodyA->mpBodyData)->meCheckingRaceCar >= 0)
    {
        ((CB4TrafficPhysics *)lpPair->mpBodyB->mpBodyData)->meCheckingRaceCar = ((CB4TrafficPhysics *)lpPair->mpBodyA->mpBodyData)->meCheckingRaceCar;
        if (((CB4TrafficPhysics *)lpPair->mpBodyB->mpBodyData)->mpArticLinkedVehicle)
        {
            ((CB4TrafficPhysics *)lpPair->mpBodyB->mpBodyData)->mpArticLinkedVehicle->meCheckingRaceCar = ((CB4TrafficPhysics *)lpPair->mpBodyA->mpBodyData)->meCheckingRaceCar;
        }
    }
    CB4PhysicsManager__BodyBodyResponse(lpThis, lpPair, lbFirstHit);
}

bool CB4PhysicsManager__CanCheckTraffic_Hook(void *lpThis, CB4CollidingPair *lpPair, CB4RaceCarPhysics *lpRaceCarPhysics, CB4TrafficVehicle *lpTrafficVehicle)
{
    bool lbReturn;
    CB4SingleEvent *lpSingleEvent;

    lpSingleEvent = &gSingleEvent;
    if (lpSingleEvent->me8State == eSingleEventState_InGame && lpSingleEvent->me8TrafficCheckType == eTrafficCheckType_Disabled && lpPair->mpBodyA->meType == eABT_PlayerCar)
    {
        return false;
    }

    lbReturn = CB4PhysicsManager__CanCheckTraffic(lpThis, lpPair, lpRaceCarPhysics, lpTrafficVehicle);

    if (lbReturn && lpSingleEvent->me8State == eSingleEventState_InGame && lpSingleEvent->me8TrafficCheckType == eTrafficCheckType_Full)
    {
        lbReturn = false;
        lpTrafficVehicle->mn8ImmediateChecking = 1;
    }

    return lbReturn;
}

float CB4MultiplayerRoadRageLogic__GetTimeRemaining_Hook(CB4MultiplayerRoadRageLogic *lpThis)
{
    return lpThis->mbTimerStarted ? CB4MultiplayerRoadRageLogic__GetTimeRemaining(lpThis) : gSingleEvent.mrTimeLimit;
}

void CB4MultiplayerRoadRageLogic__OnIntroCameraFinished_Hook(CB4MultiplayerRoadRageLogic *lpThis)
{
    if (gSingleEvent.mrTimeLimit > 0)
    {
        CB4MultiplayerRoadRageLogic__OnIntroCameraFinished(lpThis);
        lpThis->mrEventEndTime += (gSingleEvent.mrTimeLimit - 180.0f);
    }
    lpThis->mbPlayersCanBeDestroyed = gSingleEvent.mn8DamageCritical;
    lpThis->mStageLogic.maTakedownManagers[1].marLastDamageCriticalWarnTime = 0.0f;
}

bool CB4HUDRoadRageTimer__Prepare_Hook(void *lpThis, EPlayerCarIndex lePlayer, EHUDAlign leAlign, s32 lxFlags, bool lbCompact)
{
    return (gSingleEvent.me8State != eSingleEventState_InGame || gSingleEvent.mrTimeLimit > 0) ? CB4HUDRoadRageTimer__Prepare(lpThis, lePlayer, leAlign, lxFlags, lbCompact) : true;
}

ERacePositionType GetRacePositionType_Hook(void *lpThis)
{
    return (gSingleEvent.me8State == eSingleEventState_InGame && gSingleEvent.mn8NumRivals > 5) ? eRacePositionTypeNormal : eRacePositionTypeRace;
}

u16 *CB4LanguageManager__FindString_Hook(CB4LanguageManager *lpThis, char *lpcStringID)
{
    return (gSingleEvent.me8State == eSingleEventState_InGame && gSingleEvent.mn8NumRivals > 5) ? NULL : CB4LanguageManager__FindString(lpThis, lpcStringID);
}

bool CB4StageLogic__EventSummaryAptCall_Hook(char *lpcTitleStringID, char *lpcMessageStringID, u16 *lpGoldThresholdString, u16 *lpSilverThresholdString, u16 *lpBronzeThresholdString, bool lbDoShowContinueButton)
{
    if (gSingleEvent.me8State == eSingleEventState_InGame)
    {
        lpGoldThresholdString = NULL;
        lpSilverThresholdString = NULL;
        lpBronzeThresholdString = NULL;
        switch (gMenuChoices.meOnePlayerChoice)
        {
            case eB4MenuChoiceOnePlayer_Race:
                lpcMessageStringID = COLL_STR_RACE_SPLASH;
                break;
            case eB4MenuChoiceOnePlayer_RoadRage:
                lpcMessageStringID = COLL_STR_ROADRAGE_SPLASH;
                break;
            case eB4MenuChoiceOnePlayer_Revenge:
                lpcMessageStringID = COLL_STR_REVENGE_SPLASH;
                break;
            case eB4MenuChoiceOnePlayer_BurningLap:
                lpcMessageStringID = COLL_STR_BURNINGLAP_SPLASH;
                break;
            case eB4MenuChoiceOnePlayer_Eliminator:
                lpcMessageStringID = COLL_STR_ELIMINATOR_SPLASH;
                break;
            case eB4MenuChoiceOnePlayer_Crash:
                lpcMessageStringID = COLL_STR_CRASH_SPLASH;
                break;
        }
    }
    return CB4StageLogic__EventSummaryAptCall(lpcTitleStringID, lpcMessageStringID, lpGoldThresholdString, lpSilverThresholdString, lpBronzeThresholdString, lbDoShowContinueButton);
}

bool CB4OnePlayerStage__Prepare_Hook(CB4OnePlayerStage *lpThis)
{
    bool lbReturn;
    CB4SingleEvent *lpSingleEvent;
    EB4MenuChoicesOnePlayer leOnePlayerChoice;

    lpSingleEvent = &gSingleEvent;
    leOnePlayerChoice = gMenuChoices.meOnePlayerChoice;
    if (lpSingleEvent->me8State == eSingleEventState_InGame && leOnePlayerChoice != eB4MenuChoiceOnePlayer_Crash)
    {
        lpThis->mGameMode.mpChallenge->maConfig[0].mbUseTraffic = lpSingleEvent->mn8TrafficOn;
    }

    lbReturn = CB4OnePlayerStage__Prepare(lpThis);

    if (lpSingleEvent->me8State == eSingleEventState_InGame && leOnePlayerChoice != eB4MenuChoiceOnePlayer_Crash)
    {
        if (!lpSingleEvent->mn8TrafficOn && lpSingleEvent->mn8OncomingOn)
        {
            // if we disable traffic but set mbUseTraffic to true once CB4OnePlayerStage::Prepare has been called we'll get oncoming boost to work and traffic will stay disabled
            lpThis->mGameMode.mpChallenge->maConfig[0].mbUseTraffic = true;
        }
        lpThis->mGameMode.mpStageLogic->mGameParams.mbAllowCrashbreaker = lpSingleEvent->mn8UseCrashbreaker;
        lpThis->mGameMode.mpStageLogic->mGameParams.mbDisplayCheckTrafficPrompt = false;
        lpThis->mGameMode.mpStageLogic->mGameParams.mbDisplayPressR1ToBoostPrompt = false;
        lpThis->mGameMode.mpStageLogic->mGameParams.mbAllowSlowMo = true;
        lpThis->mGameMode.mpStageLogic->mGameParams.mbSlamsAreSuperStrength = false;
    }

    return lbReturn;
}

CB4GameMode *CB4MenuChoices__RequestOnePlayerGameMode_Hook(CB4MenuChoices *lpThis)
{
    CB4SingleEvent *lpSingleEvent;
    CB4GameMode *lpGameMode;
    CB4RaceSetupConfig *lpConfig;
    s32 lnNumAICars;
    s32 i;

    lpSingleEvent = &gSingleEvent;
    lpGameMode = CB4MenuChoices__RequestOnePlayerGameMode(lpThis);

    if (lpSingleEvent->me8State != eSingleEventState_ModeSetup)
    {
        return lpGameMode;
    }
    else if (lpThis->meOnePlayerChoice != eB4MenuChoiceOnePlayer_Crash)
    {
        lpConfig = &lpGameMode->mpChallenge->maConfig[0];

        if (lpThis->meOnePlayerChoice == eB4MenuChoiceOnePlayer_RoadRage)
        {
            lpConfig->meStageLogicType = eOfflineTwoPlayerRoadRage;
        }

        lpThis->mbTrafficOn = lpSingleEvent->mn8TrafficOn;
        lpThis->mnNumAICars = lpSingleEvent->mn8NumRivals;
        lpThis->mbCrashbreakerInRaceOn = lpSingleEvent->mn8UseCrashbreaker;

        lpConfig->mnNumAICars = lpSingleEvent->mn8NumRivals;
        lpConfig->mbUseTraffic = lpSingleEvent->mn8TrafficOn;
        lpConfig->mbUseCrashbreaker = lpSingleEvent->mn8UseCrashbreaker;

        lnNumAICars = (lpConfig->mnNumAICars > MAX_STATIC_RIVALS) ? MAX_STATIC_RIVALS : lpConfig->mnNumAICars;

        for (i = 0; i < lnNumAICars; i++)
        {
            if (lpSingleEvent->mn8RivalSelection)
            {
                lpConfig->maAICarID[i] = lpThis->maCarID[(i + 1)];
            }
            else
            {
                lpConfig->maAICarID[i] = CB4MenuChoices__GetDriverCarID(lpThis, NULL, lpConfig->maPlayerCarID[0], (i + 1), i, &lpConfig->maAICarID[0], i);
            }
            lpConfig->maAICarColours[i] = lpThis->maCarColor[(i + 1)];
        }
    }
    else
    {
        lpSingleEvent->me8TrafficCheckType = eTrafficCheckType_Default;
    }

    lpSingleEvent->mpAptComponents = NULL;
    lpSingleEvent->me8State = eSingleEventState_InGame;
    lpSingleEvent->me8MenuType = eSingleEventMenuType_InGamePause;

    return lpGameMode;
}

void CB4CarSelectService__GetTitles_Hook(void *lpThis, char *lpcTitle, char *lpcSubTitle)
{
    s32 lnTitleHashID;

    CB4CarSelectService__GetTitles(lpThis, lpcTitle, lpcSubTitle);
    if (gSingleEvent.me8State == eSingleEventState_ModeSetup && gSingleEvent.mn8RivalSelection)
    {
        lnTitleHashID = 0;
        switch (*(s32 *)((u8 *)lpThis + 4))
        {
            case 0:
                lnTitleHashID = LSH_uPLAYER;
                break;
            case 1:
                lnTitleHashID = LSH_DRIVER1;
                break;
            case 2:
                lnTitleHashID = LSH_DRIVER2;
                break;
            case 3:
                lnTitleHashID = LSH_DRIVER3;
                break;
            case 4:
                lnTitleHashID = LSH_DRIVER4;
                break;
            case 5:
                lnTitleHashID = LSH_DRIVER5;
                break;

        }
        CStringFromHash(lnTitleHashID, lpcTitle, 0x40);
        CStringFromHash(LSH_OnlineSubTitleOptions, lpcSubTitle, 0x40);
    }
}

void CB4CarSelectManager__SetNextState_Hook(void *lpThis, u64 lNextState, void *lpNextUserData)
{
    CB4SingleEvent *lpSingleEvent;
    s32 lnNumAICars;
    s32 i;

    lpSingleEvent = &gSingleEvent;
    CB4CarSelectManager__SetNextState(lpThis, lNextState, lpNextUserData);
    if (lpSingleEvent->me8State == eSingleEventState_ModeSetup && lpSingleEvent->mn8RivalSelection)
    {
        lnNumAICars = (lpSingleEvent->mn8NumRivals > MAX_STATIC_RIVALS) ? MAX_STATIC_RIVALS : lpSingleEvent->mn8NumRivals;
        for (i = 0; i < lnNumAICars; i++)
        {
            CB4CarSelectManager__SetNextState(lpThis, lNextState, (void *)(i + 1));
        }
    }
}

void CB4MPCrashOptionsState__OnActionEnter_Hook(CB4MPCrashOptionsState *lpThis, EGtStateAction leAction, void *lpOwner, void *lpActionData, void *lpUserData)
{
    SingleEventOnMenuEnter(&gSingleEvent, eSingleEventMenuType_MPCrashOptions, eSingleEventState_ModeSetup, true);
    CB4MPCrashOptionsState__OnActionEnter(lpThis, leAction, lpOwner, lpActionData, lpUserData);
}

void CB4MPRaceOptionsState__OnActionPageSelectEvent_Hook(CB4MPRaceOptionsState *lpThis, EMultiplayerButton leButton)
{
    CB4SingleEvent *lpSingleEvent;
    EB4MenuChoicesOnePlayer leOnePlayerChoice;

    lpSingleEvent = &gSingleEvent;
    leOnePlayerChoice = gMenuChoices.meOnePlayerChoice;

    if (leButton == eMultiplayerButton_Continue)
    {
        if (lpSingleEvent->me8MenuType == eSingleEventMenuType_MPRaceOptions)
        {
            if (leOnePlayerChoice == eB4MenuChoiceOnePlayer_Race)
            {
                lpSingleEvent->mn8NumLaps = AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, APT_MP_RACE_OPTS_LAPS) + 1;
            }
            else if (leOnePlayerChoice == eB4MenuChoiceOnePlayer_RoadRage)
            {
                lpSingleEvent->mrTimeLimit = (float)(AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, APT_MP_RDRG_OPTS_TIME_LIMIT) * 60);
                lpSingleEvent->mn8DamageCritical = (AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, APT_MP_RDRG_OPTS_DAMAGE_CRITICAL) == 0);
            }
            lpSingleEvent->mn8NumRivals = AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, lpSingleEvent->mn8NumRivals);
            lpSingleEvent->mn8RivalSelection = (lpSingleEvent->mn8NumRivals > 0 && AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, lpSingleEvent->mn8RivalSelection) == 0);
            lpSingleEvent->me8AIMode = AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, lpSingleEvent->me8AIMode);
        }
        else
        {
            lpSingleEvent->mn8NumRivals = 0;
            lpSingleEvent->mn8RivalSelection = 0;
        }

        if (leOnePlayerChoice != eB4MenuChoiceOnePlayer_Revenge)
        {
            lpSingleEvent->mn8TrafficOn = (AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, lpSingleEvent->mn8TrafficOn) == 0);
            lpSingleEvent->mn8OncomingOn = (AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, lpSingleEvent->mn8OncomingOn) == 0);
        }
        else
        {
            lpSingleEvent->mn8TrafficOn = 1;
            lpSingleEvent->mn8OncomingOn = 1;
            lpSingleEvent->mn8TATKTimeLimitOn = (AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, APT_MP_TATK_OPTS_TIME_LIMIT) == 0);
        }

        if (leOnePlayerChoice != eB4MenuChoiceOnePlayer_Revenge && leOnePlayerChoice != eB4MenuChoiceOnePlayer_BurningLap)
        {
            lpSingleEvent->mn8UseCrashbreaker = (AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, lpSingleEvent->mn8UseCrashbreaker) == 0);
        }
        else
        {
            lpSingleEvent->mn8UseCrashbreaker = 0;
        }

        lpSingleEvent->me8TrafficCheckType = AptGetSelectorChoiceIndex(lpSingleEvent->mpAptComponents, lpSingleEvent->me8TrafficCheckType);

        if (leOnePlayerChoice == eB4MenuChoiceOnePlayer_Revenge && lpSingleEvent->me8TrafficCheckType == eTrafficCheckType_Disabled)
        {
            lpSingleEvent->me8TrafficCheckType = eTrafficCheckType_Full;
        }

        lpSingleEvent->me8MenuType = eSingleEventMenuType_CarSelect;
    }

    CB4MPRaceOptionsState__OnActionPageSelectEvent(lpThis, leButton);
}

void CB4MPRaceOptionsState__OnActionEnter_Hook(CB4MPRaceOptionsState *lpThis, EGtStateAction leAction, void *lpOwner, void *lpActionData, void *lpUserData)
{
    ESingleEventMenuType leMenuType;

    if (gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_Revenge
        || gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_BurningLap)
    {
        leMenuType = eSingleEventMenuType_MPTrafficAttackOptions;
    }
    else
    {
        leMenuType = eSingleEventMenuType_MPRaceOptions;
    }
    SingleEventOnMenuEnter(&gSingleEvent, leMenuType, eSingleEventState_ModeSetup, false);
    CB4MPRaceOptionsState__OnActionEnter(lpThis, leAction, lpOwner, lpActionData, lpUserData);
}

void CB4MultiplayerState__OnActionPageSelectEvent_Hook(void *lpThis, EMultiplayerButton leButton)
{
    EB4MenuChoicesOnePlayer leOnePlayerChoice;

    switch (leButton)
    {
        case eMultiplayerButton_RoadRage:
            leOnePlayerChoice = eB4MenuChoiceOnePlayer_RoadRage;
            break;
        case eMultiplayerButton_TrafficAttack:
            leOnePlayerChoice = eB4MenuChoiceOnePlayer_Revenge;
            break;
        case eMultiplayerButton_CrashTour:
            leOnePlayerChoice = eB4MenuChoiceOnePlayer_Eliminator;
            break;
        case eMultiplayerButton_CrashParty:
            leOnePlayerChoice = eB4MenuChoiceOnePlayer_BurningLap;
            break;
        case eMultiplayerButton_CrashBattle:
            leOnePlayerChoice = eB4MenuChoiceOnePlayer_Crash;
            break;
        default:
            leOnePlayerChoice = eB4MenuChoiceOnePlayer_Race;
    }
    gMenuChoices.meOnePlayerChoice = leOnePlayerChoice;
    CB4MultiplayerState__OnActionPageSelectEvent(lpThis, leButton);
}

void CB4MultiplayerState__OnActionEnter_Hook(void *lpThis, EGtStateAction leAction, void *lpOwner, void *lpActionData, void *lpUserData)
{
    ESingleEventState leState;

    if (gSingleEvent.me8State == eSingleEventState_InGame && gSettings.mbAutoSaveIsOn)
    {
        leState = eSingleEventState_ProfileSave;
    }
    else
    {
        leState = eSingleEventState_ModeSelect;
    }
    SingleEventOnMenuEnter(&gSingleEvent, eSingleEventMenuType_MP, leState, true);
    CB4MultiplayerState__OnActionEnter(lpThis, leAction, lpOwner, lpActionData, lpUserData);
}

void CB4MainMenuState__Action_Hook(CB4MainMenuState* lpThis, EGtStateAction leAction, void* lpOwner, void* lpActionData, void* lpUserData)
{
    if (leAction == eGtStateActionEnter)
    {
        SingleEventOnMenuEnter(&gSingleEvent, eSingleEventMenuType_Main, eSingleEventState_None, true);
    }
    else if (leAction == eGtStateActionLeave)
    {
        gSingleEvent.me8MenuType = eSingleEventMenuType_None;
    }

    CB4MainMenuState__Action(lpThis, leAction, lpOwner, lpActionData, lpUserData);
}

void AptUpdate_Hook(unsigned int nDeltaTime)
{
    CB4SingleEvent *lpSingleEvent;
    void *lpAptComponents;
    u128 lacWelcomeTitle;
    u128 lacWelcomeMessage[5];
    bool lbMenuHasSelectors;

    lpSingleEvent = &gSingleEvent;

    AptUpdate(nDeltaTime);

    if (lpSingleEvent->me8MenuType < eSingleEventMenuType_Main
        || lpSingleEvent->me8MenuType > eSingleEventMenuType_InGamePause)
    {
        return;
    }

    lpAptComponents = AptGetComponentsArray();
    lbMenuHasSelectors = (lpSingleEvent->me8MenuType > eSingleEventMenuType_MP && lpSingleEvent->me8MenuType < eSingleEventMenuType_InGamePause);

    if (lpSingleEvent->mbAptUpdatesDone)
    {
        if (lbMenuHasSelectors)
        {
            AptUpdateSelectors(lpAptComponents);
        }
        return;
    }

    else if (lpAptComponents != lpSingleEvent->mpAptComponents)
    {
        if (lpSingleEvent->me8MenuType != eSingleEventMenuType_Main
            && lpSingleEvent->me8MenuType < eSingleEventMenuType_InGamePause)
        {
            AptSetTitlesText();
        }

        AptSetButtonsText(lpAptComponents);

        if ((lpSingleEvent->mn8NumAptUpdates == APT_SELECTORS_SETUP_UPDATE_NUM && lbMenuHasSelectors))
        {
            AptPrepareSelectors(lpAptComponents);
            AptUpdateSelectors(lpAptComponents);
        }
    }

    lpSingleEvent->mn8NumAptUpdates++;

    if (lpSingleEvent->mn8NumAptUpdates == APT_MAX_UPDATES)
    {
        if (lpSingleEvent->me8MenuType == eSingleEventMenuType_MP)
        {
            if (!lpSingleEvent->mbWelcomePopupShown)
            {
                // Pop-up title
                lacWelcomeTitle = 0x000052454E52554220454D4F434C4557;

                // Pop-up text (SLES, SLUS, SLAJ)
                lacWelcomeMessage[0] = 0x6F6D20746E65764520656C676E69530A;
                lacWelcomeMessage[1] = 0x64614D0A0A214B434142207369206564;
                lacWelcomeMessage[2] = 0x696728206D656C6168654E2079622065;
                lacWelcomeMessage[3] = 0x6D616C6568614E2F6D6F632E62756874;
                lacWelcomeMessage[4] = 0x0000000000000021594F4A4E450A0A29;

                /*
                // Pop-up text (SLPM, SLKA)
                lacWelcomeMessage[0] = 0x6F6D20746E65764520656C676E69530A;
                lacWelcomeMessage[1] = 0x64614D0A0A214B434142207369206564;
                lacWelcomeMessage[2] = 0x746967286D656C6168654E2079622065;
                lacWelcomeMessage[3] = 0x296D616C6568614E2F6D6F632E627568;
                lacWelcomeMessage[4] = 0x00000000000000000000000000000000;
                */

                CB4PopupManagerService__RequestPopup(&gFlashMovieManager, (char *)&lacWelcomeTitle, (char *)lacWelcomeMessage, eB4PopupType_OK, NULL, NULL, eB4PopupButton_OK);
                lpSingleEvent->mbWelcomePopupShown = true;
            }
            else if (lpSingleEvent->me8State == eSingleEventState_ProfileSave)
            {
                CB4PopupManagerService__RequestPopup(&gFlashMovieManager, COLL_STR_AUTOSAVE_POPUP_TITLE, COLL_STR_AUTOSAVE_POPUP_TEXT, eB4PopupType_YesNo, &SaveProfileCallback, &gMenuFlowManager.mFSM.mpState->mID, eB4PopupButton_Yes);
            }
        }
        lpSingleEvent->mpAptComponents = lpAptComponents;
        lpSingleEvent->mbAptUpdatesDone = true;
        gAptManager.mbEnableVideoRendering = true;
    }
}
