#ifndef APT_H
#define APT_H

#include "types.h"
#include "game_vars.h"
#include "game_enums.h"

void *AptStringFromHash(s32 lnHashID);
void *AptGetVariable(char *lpcVarName, void *lpContext);
void AptSetVariable(char *lpcVarName, EAptVarType leVarType, void *lpContext, void *lpUserData);
void *AptGetComponentsArray();
bool AptIsSelectorEnabled(void *lpAptComponents, s32 lnComponentIndex);
s32 AptGetSelectorChoiceIndex(void *lpAptComponents, s32 lnComponentIndex);
void AptComponentGetVariableFullName(void *lpAptComponents, s32 lnComponentIndex, char *lpcVarNameSecondHalf, char *lpcVarFullName);
void AptSetSelectorText(void *lpAptComponents, s32 lnComponentIndex, s32 lnStringHashID, char *lpcCustomText);
void AptSetSelectorInactiveText(void *lpAptComponents, s32 lnComponentIndex, s32 lnChoiceIndex, bool lbDisable);
void AptEnableComponent(void *lpAptComponents, s32 lnComponentIndex);
void AptSelectorUpdateEnabled(void *lpAptComponents, s32 lnSourceComponentIndex, s32 lnTargetComponentIndex, bool lbYesNoSelector, bool lbNoWhenDisabled);
void AptUpdateSelectors(void *lpAptComponents);
void AptSetTitles(s32 lnTitleHashID, s32 lnSubTitleHashID);
void AptSetTitlesText();
void AptSetButtonLabelText(void *lpAptComponents, s32 lnButtonIndex, s32 lnHashID, bool lbIsSubLabel);
void AptSetButtonsText(void *lpAptComponents);
s32 AptGetNumComponents(void *lpAptComponents);
void AptCloneSelector(void *lpAptComponents, void *lpAptCloneSource, s32 lnCloneSourceIndex);
void AptSetComponentYScale(void *lpComponent, s32 lnScale);
void AptAdjustSelectorsPlacement(void *lpAptComponents, s32 lnYAdjust, s32 lnYSpacing, bool lbRescale, s32 lnNewScale);
void AptFixUpHighlighter(void *lpAptComponents, s32 lnYAdjust);
void AptAddSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex, s32 lnNumClones, s32 lnYAdjust, s32 lnYSpacing, bool lbRescale, s32 lnNewScale);
void *AptCreateEmptyArray();
void AptSetSelectorOptions(void *lpAptComponents, s32 lnComponentIndex, void *lpAptArray);
void AptCreateSelectorIntArrayWithinRange(void *lpAptComponents, s32 lnComponentIndex, s32 lnMin, s32 lnMax, s32 lnStep);
s32 AptPrepareIntArraySelector(void *lpAptComponents, s32 lnComponentIndex, s32 lnMin, s32 lnMax, s32 lnStep, s32 lnStringHashID, char *lpcCustomText, s32 lnChoiceIndex, bool lbDisable);
void AptCreateYesNoSelector(void *lpAptComponents, s32 lnComponentIndex);
s32 AptPrepareYesNoSelector(void *lpAptComponents, s32 lnComponentIndex, s32 lnStringHashID, char *lpcCustomText, s32 lnChoiceIndex, bool lbDisable);
void *AptGetSelectorOptions(void *lpAptComponents, s32 lnComponentIndex);
void AptPrepareRoadRageTimeLimitSelector(void *lpAptComponents, s32 lnComponentIndex);
s32 AptPrepareAIModeSelector(void *lpAptComponents, s32 lnComponentIndex, s32 lnChoiceIndex);
s32 AptPrepareTrafficCheckingSelector(void *lpAptComponents, s32 lnComponentIndex);
void AptPrepareCommonSelectors(void *lpAptComponents, s32 lnStartIndex, s32 lnNumRivals);
void AptPrepareRaceSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex);
void AptPrepareRoadRageSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex);
void AptPrepareTrafficAttackSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex);
void AptPrepareBurningLapSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex);
void AptPrepareEliminatorSelectors(void *lpAptComponents, void *lpCloneSource, s32 lnCloneSourceIndex);
void AptPrepareSelectors(void *lpAptComponents);

#endif
