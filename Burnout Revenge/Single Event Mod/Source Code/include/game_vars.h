#ifndef GAME_VARS_H
#define GAME_VARS_H

#include "game_structs.h"

extern u8 rwDMAMinVsyncCnt;
extern CB4TwoPlayerSplitScreenStage gTwoPlayerSplitScreenStage;
extern CB4MenuChoices gMenuChoices;
extern AptActionInterpreter gAptActionInterpreter;
extern CB4LanguageManager gLanguageManager;
extern void *gpUndefinedValue;
extern void *gpGCPoolManager;
extern CB4FlashMovieManager gFlashMovieManager;
extern CB4MenuFlowManager gMenuFlowManager;
extern CB4Settings gSettings;
extern CB4CrashActionDirector gCrashActionDirector;
extern CB4PlayerCar gaPlayerCars[2];
extern CB4ProfileStatistics gProfileStatistics;
extern CB4TrackList gTrackList;
extern CB4HUDBurningLap gBurningLapComponent;
extern CB4HUDHitCount gHitCountComponent;
extern CB4HUDTrafficAttackScore gTrafficAttackScoreComponent;
extern CB4AptManager gAptManager;
extern CB4HUDManager gHUDManager;
extern const char *gpacCrownStr;
extern float grWorldTime;
extern void *gpFileSystem;

#endif
