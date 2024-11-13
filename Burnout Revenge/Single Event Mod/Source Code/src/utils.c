#include "apt.h"
#include "utils.h"
#include "types.h"
#include "macros.h"
#include "game_funcs.h"
#include "game_vars.h"
#include "game_enums.h"

void CStringFromHash(s32 lnHashID, char *lpacDestBuf, s32 lnDestBufSize)
{
    CGtUnicode__ConvertUTF16toUTF8Fast(CGtHashIDStringArray__GetString(gLanguageManager.mpMainStrings, lnHashID), (u8 *)lpacDestBuf, lnDestBufSize);
}

bool IsSingleEventMode()
{
    return (gSingleEvent.me8State > eSingleEventState_None);
}

void ChangeState(CGtFSM *lpThis, u64 lu64DestinationState, void* lpUserData)
{
    CGtState *lpNewState;
    CGtState *lpOldState;

    lpNewState = CGtFSM__GetStateFromID(lpThis, lu64DestinationState);
    if (lpThis->mpState != lpNewState)
    {
        CGtFSM__StateLeave(lpThis, lpNewState, lpUserData);
        lpOldState = lpThis->mpState;
        lpThis->mpState = lpNewState;
        if (lpThis->mpStateTimer != NULL)
        {
            lpThis->mrTimeStateEntered = lpThis->mpStateTimer->mrTime;
            if (lpNewState != NULL)
            {
                lpNewState->mrTimeStateEntered = lpThis->mpStateTimer->mrTime;
            }
        }
        CGtFSM__StateEnter(lpThis, lpOldState, lpUserData);
    }
}

void SaveProfileCallback(EB4PopupButton leSelectedButton, void *lpUserData)
{
    if (leSelectedButton == eB4PopupButton_Yes)
    {
        ChangeState(&gMenuFlowManager.mFSM, STATE_AUTOSAVE, lpUserData);
    }
}

void SingleEventOnMenuEnter(CB4SingleEvent *lpThis, ESingleEventMenuType leMenuType, ESingleEventState leState, bool lbAptRenderingEnabled)
{
    gAptManager.mbEnableVideoRendering = lbAptRenderingEnabled;
    lpThis->me8MenuType = leMenuType;
    lpThis->me8State = leState;
    lpThis->mn8NumAptUpdates = 0;
    lpThis->mpAptComponents = AptGetComponentsArray();
    lpThis->mbAptUpdatesDone = false;
}

bool OfferEndSessionRatherThanQuit()
{
    return (gaPlayerCars[0].mAICar.mRaceCar.mLapManager.meRaceState == eScoreRaceCarStateRacing
    && ((gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_BurningLap
        && gaPlayerCars[0].mAICar.mRaceCar.mLapManager.mrLastLapTotalRaceTime > 10.0f)
    || (gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_Revenge
        && gSingleEvent.mn8TATKTimeLimitOn == 0
        && gTrafficAttackScoreComponent.mnCurrentDisplayScore > 0)));
}
