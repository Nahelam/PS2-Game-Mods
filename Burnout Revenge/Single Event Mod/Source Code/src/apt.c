#include "apt.h"
#include "utils.h"
#include "types.h"
#include "macros.h"
#include "game_funcs.h"
#include "game_vars.h"
#include "game_enums.h"

void *AptStringFromHash(s32 lnHashID)
{
    return UTF16StringToAptString(CGtHashIDStringArray__GetString(gLanguageManager.mpMainStrings, lnHashID));
}

void *AptGetVariable(char *lpcVarName, void *lpContext)
{
    AptNativeString sVarName;
    void *lpAptValue;
    void *lpCurrentContext;

    if (lpContext == NULL)
    {
        lpCurrentContext = _AptGetAnimationAtLevel(0);
    }
    else
    {
        lpCurrentContext = lpContext;
    }

    EAStringC__Ctor(&sVarName, lpcVarName);
    lpAptValue = AptActionInterpreter__getVariable(&gAptActionInterpreter, lpCurrentContext, NULL, &sVarName, 1, 1, 0);
    EAStringC__Dtor(&sVarName, 2);
    return lpAptValue;
}

void AptSetVariable(char *lpcVarName, EAptVarType leVarType, void *lpContext, void *lpUserData) // void *lpSecondaryUserData)
{
    AptNativeString sVarName;
    void *lpAptValue;
    void *lpCurrentContext;

    if (lpContext == NULL)
    {
        lpCurrentContext = _AptGetAnimationAtLevel(0);
    }
    else
    {
        lpCurrentContext = lpContext;
    }

    EAStringC__Ctor(&sVarName, lpcVarName);

    switch (leVarType)
    {
        case eAptVarType_StringHash:
            lpAptValue = AptStringFromHash((s32)lpUserData);
            break;
        case eAptVarType_Integer:
            lpAptValue = AptInteger__Create((s32)lpUserData);
            break;
        default:
            lpAptValue = lpUserData;
    }

    AptActionInterpreter__setVariable(&gAptActionInterpreter, lpCurrentContext, NULL, &sVarName, lpAptValue, 1, 1, 0);

    EAStringC__Dtor(&sVarName, 2);
}

void *AptGetComponentsArray()
{
    return AptGetVariable("gFM.m_arrItems", NULL);
}

bool AptIsSelectorEnabled(void *lpAptComponents, s32 lnComponentIndex)
{
    return AptValue__toBool(AptGetVariable("m_bEnabled", AptArray__get(lpAptComponents, lnComponentIndex)));
}

s32 AptGetSelectorChoiceIndex(void *lpAptComponents, s32 lnComponentIndex)
{
    return AptValue__toInteger(AptGetVariable("selectedChoiceIndex", AptArray__get(lpAptComponents, lnComponentIndex)));
}

void AptComponentGetVariableFullName(void *lpAptComponents, s32 lnComponentIndex, char *lpcVarNameSecondHalf, char *lpcVarFullName)
{
    void *lpAptComponent;

    lpAptComponent = AptArray__get(lpAptComponents, lnComponentIndex);
    if (lpcVarNameSecondHalf != NULL)
    {
        char lacVarNameFirstHalf[0x40];
        AptValue__toString(lpAptComponent, lacVarNameFirstHalf);
        _sprintf(lpcVarFullName, "%s.%s", lacVarNameFirstHalf, lpcVarNameSecondHalf);
    }
    else
    {
        AptValue__toString(lpAptComponent, lpcVarFullName);
    }
}

void AptSetSelectorText(void *lpAptComponents, s32 lnComponentIndex, s32 lnStringHashID, char *lpcCustomText)
{
    char *lpcNewText;
    char lacVarFullName[0x80];
    char lacNewText[0x40];

    AptComponentGetVariableFullName(lpAptComponents, lnComponentIndex, "text_mc.label_txt", lacVarFullName);
    if (lpcCustomText != NULL)
    {
        lpcNewText = lpcCustomText;
    }
    else
    {
        CStringFromHash(lnStringHashID, lacNewText, sizeof(lacNewText));
        lpcNewText = lacNewText;
    }
    AptCallFunction("setText", NULL, lacVarFullName, 1, lpcNewText);
}

void AptSetSelectorInactiveText(void *lpAptComponents, s32 lnComponentIndex, s32 lnChoiceIndex, bool lbDisable)
{
    char lacVarFullName[0x40];
    char lacChoiceIndex[0x10];

    AptComponentGetVariableFullName(lpAptComponents, lnComponentIndex, NULL, lacVarFullName);
    AptSetVariable("selectedChoiceIndex", eAptVarType_Integer, AptArray__get(lpAptComponents, lnComponentIndex), (void *)lnChoiceIndex);
    _itoa(lnChoiceIndex, lacChoiceIndex, 10);
    AptCallFunction("setInactiveText", NULL, lacVarFullName, 1, lacChoiceIndex);
    if (lbDisable)
    {
        AptCallFunction("disable", NULL, lacVarFullName, 0);
    }
}

void AptEnableComponent(void *lpAptComponents, s32 lnComponentIndex)
{
    char lacVarFullName[0x40];
    AptComponentGetVariableFullName(lpAptComponents, lnComponentIndex, NULL, lacVarFullName);
    AptCallFunction("enable", NULL, lacVarFullName, 0);
}

void AptSelectorUpdateEnabled(void *lpAptComponents, s32 lnSourceComponentIndex, s32 lnTargetComponentIndex, bool lbYesNoSelector, bool lbNoWhenDisabled)
{
    bool lbSourceSelectorEnabled;
    bool lbTargetSelectorEnabled;

    if (lbYesNoSelector)
    {
        lbSourceSelectorEnabled = (AptGetSelectorChoiceIndex(lpAptComponents, lnSourceComponentIndex) == 0);
    }
    else
    {
        lbSourceSelectorEnabled = (AptGetSelectorChoiceIndex(lpAptComponents, lnSourceComponentIndex) > 0);
    }
    lbTargetSelectorEnabled = AptIsSelectorEnabled(lpAptComponents, lnTargetComponentIndex);

    if (lbNoWhenDisabled)
    {
        if (!lbSourceSelectorEnabled && lbTargetSelectorEnabled)
        {
            AptSetSelectorInactiveText(lpAptComponents, lnTargetComponentIndex, 1, true);
        }
        else if (lbSourceSelectorEnabled && !lbTargetSelectorEnabled)
        {
            AptEnableComponent(lpAptComponents, lnTargetComponentIndex);
        }
    }
    else
    {
        if (lbSourceSelectorEnabled && lbTargetSelectorEnabled)
        {
            AptSetSelectorInactiveText(lpAptComponents, lnTargetComponentIndex, 0, true);
        }
        else if (!lbSourceSelectorEnabled && !lbTargetSelectorEnabled)
        {
            AptEnableComponent(lpAptComponents, lnTargetComponentIndex);
        }
    }
}

void AptUpdateSelectors(void *lpAptComponents)
{
    switch (gMenuChoices.meOnePlayerChoice)
    {
        case eB4MenuChoiceOnePlayer_Race:
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_RACE_OPTS_TRAFFIC, APT_MP_RACE_OPTS_TRAFFIC_CHECKING, true, true);
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_RACE_OPTS_RIVALS, APT_MP_RACE_OPTS_SELECT_RIVALS, false, true);
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_RACE_OPTS_TRAFFIC, APT_MP_RACE_OPTS_ONCOMING, true, false);
            break;
        case eB4MenuChoiceOnePlayer_RoadRage:
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_RDRG_OPTS_TRAFFIC, APT_MP_RDRG_OPTS_TRAFFIC_CHECKING, true, true);
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_RDRG_OPTS_RIVALS, APT_MP_RDRG_OPTS_SELECT_RIVALS, false, true);
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_RDRG_OPTS_TIME_LIMIT, APT_MP_RDRG_OPTS_DAMAGE_CRITICAL, true, false);
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_RDRG_OPTS_TRAFFIC, APT_MP_RDRG_OPTS_ONCOMING, true, false);
            break;
        case eB4MenuChoiceOnePlayer_Revenge:
            break;
        case eB4MenuChoiceOnePlayer_BurningLap:
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_BLAP_OPTS_TRAFFIC, APT_MP_BLAP_OPTS_TRAFFIC_CHECKING, true, true);
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_BLAP_OPTS_TRAFFIC, APT_MP_BLAP_OPTS_ONCOMING, true, false);
            break;
        case eB4MenuChoiceOnePlayer_Eliminator:
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_ELIM_OPTS_TRAFFIC, APT_MP_ELIM_OPTS_TRAFFIC_CHECKING, true, true);
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_ELIM_OPTS_RIVALS, APT_MP_ELIM_OPTS_SELECT_RIVALS, false, true);
            AptSelectorUpdateEnabled(lpAptComponents, APT_MP_ELIM_OPTS_TRAFFIC, APT_MP_ELIM_OPTS_ONCOMING, true, false);
            break;
    }
}

void AptSetTitles(s32 lnTitleHashID, s32 lnSubTitleHashID)
{
    char lacTitle[0x40];
    char lacSubTitle[0x40];

    CStringFromHash(lnTitleHashID, lacTitle, sizeof(lacTitle));
    CStringFromHash(lnSubTitleHashID, lacSubTitle, sizeof(lacSubTitle));
    AptCallFunction("setText", NULL, "gStdTitle.title_mc", 2, lacTitle, lacSubTitle);
}

void AptSetTitlesText()
{
    s32 lnTitleHashID = 0;
    s32 lnSubTitleHashID = 0;

    if (gSingleEvent.me8MenuType == eSingleEventMenuType_MP)
    {
        lnTitleHashID = LSH_OnlineCreateGame;
        lnSubTitleHashID = LSH_MPSelectMode;
    }
    else if (gSingleEvent.me8MenuType == eSingleEventMenuType_MPCrashOptions)
    {
        lnTitleHashID = LSH_GameModeCrash;
        lnSubTitleHashID = LSH_FESELECTTYPE;
    }
    else
    {
        switch (gMenuChoices.meOnePlayerChoice)
        {
            case eB4MenuChoiceOnePlayer_Race:
                lnTitleHashID = LSH_GameModeRace;
                break;
            case eB4MenuChoiceOnePlayer_RoadRage:
                lnTitleHashID = LSH_GameModeRoadRage;
                break;
            case eB4MenuChoiceOnePlayer_Revenge:
                lnTitleHashID = LSH_GameModeTrafficAttack;
                break;
            case eB4MenuChoiceOnePlayer_BurningLap:
                lnTitleHashID = LSH_GameModePreviewLap;
                break;
            case eB4MenuChoiceOnePlayer_Eliminator:
                lnTitleHashID = LSH_GameModeEliminator;
                break;
        }
        lnSubTitleHashID = LSH_OnlineSubTitleGameOptions;
    }

    AptSetTitles(lnTitleHashID, lnSubTitleHashID);
}

void AptSetButtonLabelText(void *lpAptComponents, s32 lnButtonIndex, s32 lnHashID, bool lbIsSubLabel)
{
    void *lpAptComponent;
    char *lpcTextVarName;

    lpAptComponent = AptArray__get(lpAptComponents, lnButtonIndex);
    if (lbIsSubLabel)
    {
        lpcTextVarName = "text_mc.subLabel_txt.text";
    }
    else
    {
        lpcTextVarName = "text_mc.label_txt.text";
    }
    AptSetVariable(lpcTextVarName, eAptVarType_StringHash, lpAptComponent, (void *)lnHashID);
}

void AptSetButtonsText(void *lpAptComponents)
{
    switch (gSingleEvent.me8MenuType)
    {
        case eSingleEventMenuType_Main:
            AptSetButtonLabelText(lpAptComponents, APT_MAIN_BTN_MULTI, LSH_OnlineCreateGame, false);
            AptSetButtonLabelText(lpAptComponents, APT_MAIN_BTN_MULTI, LSH_FESINGLEPLAYERSUB, true);
            break;
        case eSingleEventMenuType_MP:
            AptSetButtonLabelText(lpAptComponents, APT_MP_BTN_RACE, LSH_GameModeRace, false);
            AptSetButtonLabelText(lpAptComponents, APT_MP_BTN_ROAD_RAGE, LSH_GameModeRoadRage, false);
            AptSetButtonLabelText(lpAptComponents, APT_MP_BTN_TRAFFIC_ATTACK, LSH_GameModeTrafficAttack, false);
            AptSetButtonLabelText(lpAptComponents, APT_MP_BTN_CRASH, LSH_GameModeCrash, false);
            AptSetButtonLabelText(lpAptComponents, APT_MP_BTN_BURNING_LAP, LSH_GameModePreviewLap, false);
            AptSetButtonLabelText(lpAptComponents, APT_MP_BTN_ELIMINATOR, LSH_GameModeEliminator, false);
            break;
        case eSingleEventMenuType_InGamePause:
            AptSetButtonLabelText(lpAptComponents, APT_PAUSE_BTN_QUIT, LSH_VirtualKeyboardDone, false);
            break;
    }
}

s32 AptGetNumComponents(void *lpAptComponents)
{
    return AptValue__toInteger(AptGetVariable("length", lpAptComponents));
}

void AptCloneSelector(void *lpAptComponents, void *lpAptCloneSource, s32 lnCloneSourceIndex)
{
    void *lpClone;
    s32 lnNumComponents;

    lnNumComponents = AptGetNumComponents(lpAptComponents);
    lpClone = AptActionInterpreter__doCloneSprite(&gAptActionInterpreter, lpAptCloneSource, NULL, lpAptCloneSource, gpUndefinedValue, lnNumComponents + 0x4000, NULL);
    AptArray__set(lpAptComponents, lnCloneSourceIndex, lpAptCloneSource);
    AptArray__set(lpAptComponents, lnNumComponents, lpClone);
}

void AptSetComponentYScale(void *lpComponent, s32 lnScale)
{
    AptSetVariable("_yscale", eAptVarType_Integer, lpComponent, (void *)lnScale);
}

void AptAdjustSelectorsPlacement(void *lpAptComponents, s32 lnYAdjust, s32 lnYSpacing, bool lbRescale, s32 lnNewScale)
{
    void *lpComponent;
    s32 lnNumComponents;
    s32 i;

    lnNumComponents = AptGetNumComponents(lpAptComponents);
    for (i = 0; i < lnNumComponents; i++)
    {
        lpComponent = AptArray__get(lpAptComponents, i);
        AptSetVariable("_y", eAptVarType_Integer, lpComponent, (void *)(lnYAdjust + (i * lnYSpacing)));
        if (lbRescale)
        {
            AptSetComponentYScale(lpComponent, lnNewScale);
        }
    }

    if (lbRescale)
    {
        AptSetComponentYScale(AptGetVariable("m_highlighter", lpComponent), lnNewScale);
    }
}

void AptFixUpHighlighter(void *lpAptComponents, s32 lnYAdjust)
{
    AptSetVariable("target", eAptVarType_Integer, AptArray__get(AptGetVariable("m_properties", AptGetVariable("m_animator", AptGetVariable("m_highlighter", AptArray__get(lpAptComponents, 0)))), 1), (void *)(lnYAdjust - 5));
}

void AptAddSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex, s32 lnNumClones, s32 lnYAdjust, s32 lnYSpacing, bool lbRescale, s32 lnNewScale)
{
    s32 i;

    for (i = 0; i < lnNumClones; i++)
    {
        AptCloneSelector(lpAptComponents, lpCloneSource, lnCloneSourceIndex);
    }
    AptAdjustSelectorsPlacement(lpAptComponents, lnYAdjust, lnYSpacing, lbRescale, lnNewScale);
    AptFixUpHighlighter(lpAptComponents, lnYAdjust);
}

void *AptCreateEmptyArray()
{
    void *lpAptArray;

    lpAptArray = AptValueGC_PoolManager__AllocateAptValueGC(gpGCPoolManager, 0x2C);
    AptArray__AptArray(lpAptArray);

    return lpAptArray;
}

void AptSetSelectorOptions(void *lpAptComponents, s32 lnComponentIndex, void *lpAptArray)
{
    AptSetVariable("m_options", eAptVarType_Max, AptArray__get(lpAptComponents, lnComponentIndex), lpAptArray);
}

void AptCreateSelectorIntArrayWithinRange(void *lpAptComponents, s32 lnComponentIndex, s32 lnMin, s32 lnMax, s32 lnStep)
{
    void *lpAptArray;
    s32 lnArrayIndex;
    s32 i;

    lpAptArray = AptCreateEmptyArray();
    lnArrayIndex = 0;

    for (i = lnMin; i <= lnMax; i += lnStep)
    {
        AptArray__set(lpAptArray, lnArrayIndex, AptInteger__Create(i));
        lnArrayIndex++;
    }

    AptSetSelectorOptions(lpAptComponents, lnComponentIndex, lpAptArray);
}

s32 AptPrepareIntArraySelector(void *lpAptComponents, s32 lnComponentIndex, s32 lnMin, s32 lnMax, s32 lnStep, s32 lnStringHashID, char *lpcCustomText, s32 lnChoiceIndex, bool lbDisable)
{
    AptCreateSelectorIntArrayWithinRange(lpAptComponents, lnComponentIndex, lnMin, lnMax, lnStep);
    AptSetSelectorText(lpAptComponents, lnComponentIndex, lnStringHashID, lpcCustomText);
    AptSetSelectorInactiveText(lpAptComponents, lnComponentIndex, lnChoiceIndex, lbDisable);
    return lnComponentIndex;
}

void AptCreateYesNoSelector(void *lpAptComponents, s32 lnComponentIndex)
{
    void *lpAptArray;

    lpAptArray = AptCreateEmptyArray();
    AptArray__set(lpAptArray, 0, AptStringFromHash(LSH_YES));
    AptArray__set(lpAptArray, 1, AptStringFromHash(LSH_NO));
    AptSetSelectorOptions(lpAptComponents, lnComponentIndex, lpAptArray);
}

s32 AptPrepareYesNoSelector(void *lpAptComponents, s32 lnComponentIndex, s32 lnStringHashID, char *lpcCustomText, s32 lnChoiceIndex, bool lbDisable)
{
    AptCreateYesNoSelector(lpAptComponents, lnComponentIndex);
    AptSetSelectorText(lpAptComponents, lnComponentIndex, lnStringHashID, lpcCustomText);
    AptSetSelectorInactiveText(lpAptComponents, lnComponentIndex, lnChoiceIndex, lbDisable);
    return lnComponentIndex;
}

void *AptGetSelectorOptions(void *lpAptComponents, s32 lnComponentIndex)
{
    return (AptGetVariable("m_options", AptArray__get(lpAptComponents, lnComponentIndex)));
}

s32 AptPrepareAIModeSelector(void *lpAptComponents, s32 lnComponentIndex, s32 lnChoiceIndex)
{
    void *lpOptions;

    AptPrepareYesNoSelector(lpAptComponents, lnComponentIndex, 0, STR_AI_MODE, 0, false);
    lpOptions = AptGetSelectorOptions(lpAptComponents, lnComponentIndex);
    AptArray__set(lpOptions, 0, AptStringFromHash(LSH_GameModeRace));
    AptArray__set(lpOptions, 1, AptStringFromHash(LSH_GameModeRoadRage));
    AptSetSelectorInactiveText(lpAptComponents, lnComponentIndex, lnChoiceIndex, false);
    return lnComponentIndex;
}

s32 AptPrepareTrafficCheckingSelector(void *lpAptComponents, s32 lnComponentIndex)
{
    void *lpOptions;
    s32 lnNewOptionIndex;

    AptPrepareYesNoSelector(lpAptComponents, lnComponentIndex, 0, STR_TRAFFIC_CHECK, 0, false);
    lpOptions = AptGetSelectorOptions(lpAptComponents, lnComponentIndex);

    if (gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_Revenge)
    {
        AptArray__set(lpOptions, 0, AptStringFromHash(LSH_OnlineGameOptionsLapsDefault));
        AptSetSelectorInactiveText(lpAptComponents, lnComponentIndex, 0, false);
        lnNewOptionIndex = 1;
    }
    else
    {
        lnNewOptionIndex = 2;
    }

    AptArray__set(lpOptions, lnNewOptionIndex, AptStringFromHash(LSH_FEDANGEROUS));

    return lnComponentIndex;
}

void AptPrepareRoadRageTimeLimitSelector(void *lpAptComponents, s32 lnComponentIndex)
{
    void *lpOptions;

    AptPrepareIntArraySelector(lpAptComponents, lnComponentIndex, 0, MAX_RDRG_TIME, 1, LSH_uTIME_LIMIT, NULL, 0, false);
    lpOptions = AptGetSelectorOptions(lpAptComponents, lnComponentIndex);
    AptArray__set(lpOptions, 0, AptStringFromHash(LSH_OFF));
    AptSetSelectorInactiveText(lpAptComponents, lnComponentIndex, 0, false);
}

void AptPrepareCommonSelectors(void *lpAptComponents, s32 lnStartIndex, s32 lnNumRivals)
{
    CB4SingleEvent *lpSingleEvent;

    lpSingleEvent = &gSingleEvent;
    if (lpSingleEvent->me8MenuType == eSingleEventMenuType_MPRaceOptions)
    {
        lpSingleEvent->mn8NumRivals = AptPrepareIntArraySelector(lpAptComponents, lnStartIndex++, 0, lnNumRivals, 1, LSH_MPRIVALS, NULL, 0, false);
        lpSingleEvent->mn8RivalSelection = AptPrepareYesNoSelector(lpAptComponents, lnStartIndex++, 0, STR_SELECT_RIVALS, 0, false);
        lpSingleEvent->me8AIMode = AptPrepareAIModeSelector(lpAptComponents, lnStartIndex++, (gMenuChoices.meOnePlayerChoice == eB4MenuChoiceOnePlayer_RoadRage));
    }
    if (gMenuChoices.meOnePlayerChoice != eB4MenuChoiceOnePlayer_Revenge)
    {
        lpSingleEvent->mn8TrafficOn = AptPrepareYesNoSelector(lpAptComponents, lnStartIndex++, 0, STR_TRAFFIC, 0, false);
        lpSingleEvent->me8TrafficCheckType = AptPrepareTrafficCheckingSelector(lpAptComponents, lnStartIndex++);
        lpSingleEvent->mn8OncomingOn = AptPrepareYesNoSelector(lpAptComponents, lnStartIndex++, LSH_ONCOMING, NULL, 0, false);
    }
    else
    {
        lpSingleEvent->me8TrafficCheckType = AptPrepareTrafficCheckingSelector(lpAptComponents, lnStartIndex++);
    }
    if (lpSingleEvent->me8MenuType == eSingleEventMenuType_MPRaceOptions)
    {
        lpSingleEvent->mn8UseCrashbreaker = AptPrepareYesNoSelector(lpAptComponents, lnStartIndex, LSH_CRASHBREAKER, NULL, 0, false);
    }
}

void AptPrepareRaceSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex)
{
    AptAddSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex, APT_MP_RACE_OPTS_NUM_CLONES, APT_MP_RACE_OPTS_Y_ADJUST, APT_MP_RACE_OPTS_Y_SPACING, true, APT_MP_RACE_OPTS_Y_SCALE);
    AptPrepareIntArraySelector(lpAptComponents, APT_MP_RACE_OPTS_LAPS, MIN_LAPS, MAX_LAPS, 1, LSH_OnlineGameOptionsLaps, NULL, 0, false);
    AptPrepareCommonSelectors(lpAptComponents, APT_MP_RACE_OPTS_RIVALS, MAX_CIRCULAR_RIVALS);
}

void AptPrepareRoadRageSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex)
{
    AptAddSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex, APT_MP_RDRG_OPTS_NUM_CLONES, APT_MP_RDRG_OPTS_Y_ADJUST, APT_MP_RDRG_OPTS_Y_SPACING, true, APT_MP_RDRG_OPTS_Y_SCALE);
    AptPrepareRoadRageTimeLimitSelector(lpAptComponents, APT_MP_RDRG_OPTS_TIME_LIMIT);
    AptPrepareYesNoSelector(lpAptComponents, APT_MP_RDRG_OPTS_DAMAGE_CRITICAL, LSH_uDAMAGECRITICAL, NULL, 0, false);
    AptPrepareCommonSelectors(lpAptComponents, APT_MP_RDRG_OPTS_RIVALS, MAX_STATIC_RIVALS);
}

void AptPrepareTrafficAttackSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex)
{
    AptAddSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex, APT_MP_TATK_OPTS_NUM_CLONES, APT_MP_TATK_OPTS_Y_ADJUST, APT_MP_TATK_OPTS_Y_SPACING, false, 0);
    AptPrepareCommonSelectors(lpAptComponents, APT_MP_TATK_OPTS_TRAFFIC_CHECKING, 0);
    AptPrepareYesNoSelector(lpAptComponents, APT_MP_TATK_OPTS_TIME_LIMIT, LSH_uTIME_LIMIT, NULL, 0, false);
}

void AptPrepareBurningLapSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex)
{
    AptAddSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex, APT_MP_BLAP_OPTS_NUM_CLONES, APT_MP_BLAP_OPTS_Y_ADJUST, APT_MP_BLAP_OPTS_Y_SPACING, false, 0);
    AptPrepareCommonSelectors(lpAptComponents, APT_MP_BLAP_OPTS_TRAFFIC, 0);
}

void AptPrepareEliminatorSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex)
{
    AptAddSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex, APT_MP_ELIM_OPTS_NUM_CLONES, APT_MP_ELIM_OPTS_Y_ADJUST, APT_MP_ELIM_OPTS_Y_SPACING, false, APT_MP_ELIM_OPTS_Y_SCALE);
    AptPrepareCommonSelectors(lpAptComponents, APT_MP_ELIM_OPTS_RIVALS, MAX_CIRCULAR_RIVALS);
}

void AptPrepareSelectors(void *lpAptComponents)
{
    void *lpCloneSource;
    s32 lnCloneSourceIndex;

    lnCloneSourceIndex = AptGetNumComponents(lpAptComponents) - 1;
    lpCloneSource = AptArray__get(lpAptComponents, lnCloneSourceIndex);

    switch (gMenuChoices.meOnePlayerChoice)
    {
        case eB4MenuChoiceOnePlayer_Race:
            AptPrepareRaceSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex);
            break;
        case eB4MenuChoiceOnePlayer_RoadRage:
            AptPrepareRoadRageSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex);
            break;
        case eB4MenuChoiceOnePlayer_Revenge:
            AptPrepareTrafficAttackSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex);
            break;
        case eB4MenuChoiceOnePlayer_BurningLap:
            AptPrepareBurningLapSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex);
            break;
        case eB4MenuChoiceOnePlayer_Eliminator:
            AptPrepareEliminatorSelectors(lpAptComponents, lpCloneSource, lnCloneSourceIndex);
            break;
    }
}
