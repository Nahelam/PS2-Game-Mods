#ifndef UTILS_H
#define UTILS_H

#include "macros.h"
#include "game_structs.h"
#include "game_enums.h"

void CStringFromHash(s32 lnHashID, char *lpacDestBuf, s32 lnDestBufSize);
bool IsSingleEventMode();
void ChangeState(CGtFSM *lpThis, u64 lu64DestinationState, void* lpUserData);
void SaveProfileCallback(EB4PopupButton leSelectedButton, void *lpUserData);
void SingleEventOnMenuEnter(CB4SingleEvent *lpThis, ESingleEventMenuType leMenuType, ESingleEventState leState, bool lbDisableAptRendering);
bool OfferEndSessionRatherThanQuit();

#endif
