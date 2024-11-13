#ifndef MACROS_H
#define MACROS_H

#define NULL (void *)0
#define true (u8)1
#define false (u8)0

// Using CB4TwoPlayerSplitScreenStage as our Single Event struct
#define CB4SingleEvent                      CB4TwoPlayerSplitScreenStage
#define gSingleEvent                        gTwoPlayerSplitScreenStage

#define APT_MP_RACE_OPTS_NUM_CLONES         7
#define APT_MP_RACE_OPTS_Y_ADJUST           110
#define APT_MP_RACE_OPTS_Y_SPACING          31
#define APT_MP_RACE_OPTS_Y_SCALE            91
#define APT_MP_RACE_OPTS_LOCATION           0
#define APT_MP_RACE_OPTS_TRACK              1
#define APT_MP_RACE_OPTS_LAPS               2
#define APT_MP_RACE_OPTS_RIVALS             3
#define APT_MP_RACE_OPTS_SELECT_RIVALS      4
#define APT_MP_RACE_OPTS_AI_MODE            5
#define APT_MP_RACE_OPTS_TRAFFIC            6
#define APT_MP_RACE_OPTS_TRAFFIC_CHECKING   7
#define APT_MP_RACE_OPTS_ONCOMING           8
#define APT_MP_RACE_OPTS_CRASHBREAKER       9

#define APT_MP_RDRG_OPTS_NUM_CLONES         8
#define APT_MP_RDRG_OPTS_Y_ADJUST           110
#define APT_MP_RDRG_OPTS_Y_SPACING          28
#define APT_MP_RDRG_OPTS_Y_SCALE            88
#define APT_MP_RDRG_OPTS_LOCATION           0
#define APT_MP_RDRG_OPTS_TRACK              1
#define APT_MP_RDRG_OPTS_TIME_LIMIT         2
#define APT_MP_RDRG_OPTS_DAMAGE_CRITICAL    3
#define APT_MP_RDRG_OPTS_RIVALS             4
#define APT_MP_RDRG_OPTS_SELECT_RIVALS      5
#define APT_MP_RDRG_OPTS_AI_MODE            6
#define APT_MP_RDRG_OPTS_TRAFFIC            7
#define APT_MP_RDRG_OPTS_TRAFFIC_CHECKING   8
#define APT_MP_RDRG_OPTS_ONCOMING           9
#define APT_MP_RDRG_OPTS_CRASHBREAKER       10

#define APT_MP_ELIM_OPTS_NUM_CLONES         6
#define APT_MP_ELIM_OPTS_Y_ADJUST           110
#define APT_MP_ELIM_OPTS_Y_SPACING          34
#define APT_MP_ELIM_OPTS_Y_SCALE            94
#define APT_MP_ELIM_OPTS_LOCATION           0
#define APT_MP_ELIM_OPTS_TRACK              1
#define APT_MP_ELIM_OPTS_RIVALS             2
#define APT_MP_ELIM_OPTS_SELECT_RIVALS      3
#define APT_MP_ELIM_OPTS_AI_MODE            4
#define APT_MP_ELIM_OPTS_TRAFFIC            5
#define APT_MP_ELIM_OPTS_TRAFFIC_CHECKING   6
#define APT_MP_ELIM_OPTS_ONCOMING           7
#define APT_MP_ELIM_OPTS_CRASHBREAKER       8

#define APT_MP_TATK_OPTS_NUM_CLONES         2
#define APT_MP_TATK_OPTS_Y_ADJUST           177
#define APT_MP_TATK_OPTS_Y_SPACING          40
#define APT_MP_TATK_OPTS_LOCATION           0
#define APT_MP_TATK_OPTS_TRACK              1
#define APT_MP_TATK_OPTS_TRAFFIC_CHECKING   2
#define APT_MP_TATK_OPTS_TIME_LIMIT         3

#define APT_MP_BLAP_OPTS_NUM_CLONES         3
#define APT_MP_BLAP_OPTS_Y_ADJUST           165
#define APT_MP_BLAP_OPTS_Y_SPACING          40
#define APT_MP_BLAP_OPTS_LOCATION           0
#define APT_MP_BLAP_OPTS_TRACK              1
#define APT_MP_BLAP_OPTS_TRAFFIC            2
#define APT_MP_BLAP_OPTS_TRAFFIC_CHECKING   3
#define APT_MP_BLAP_OPTS_ONCOMING           4

#define LSH_OnlineCreateGame                0x8BE899E8
#define LSH_MPSelectMode                    0xBA4BD295
#define LSH_GameModeCrash                   0x9A9C71BA
#define LSH_FESELECTTYPE                    0x75521CF2 // [SELECT EVENT]
#define LSH_GameModeRace                    0x131AF6E9
#define LSH_GameModeRoadRage                0x8F6955BA
#define LSH_GameModeTrafficAttack           0x361DB397
#define LSH_GameModeCrash                   0x9A9C71BA
#define LSH_GameModePreviewLap              0x139FF4DF // looks like this is "BURNING LAP", swapped by error ?
#define LSH_GameModeEliminator              0xD03C2DB0
#define LSH_OnlineSubTitleGameOptions       0xE78A7271
#define LSH_FESINGLEPLAYERSUB               0x3F83A3CF
#define LSH_OnlineGameOptionsLaps           0xEE2AB403
#define LSH_MPRIVALS                        0x4E38F70B
#define LSH_ONCOMING                        0x4E4B203D
#define LSH_CRASHBREAKER                    0xF5FF5A4C
#define LSH_FEDANGEROUS                     0xBE85355F // INSANE
#define LSH_OnlineGameOptionsLapsDefault    0xFD8A987F // DEFAULT
#define LSH_uTIME_LIMIT                     0x5968AD3B
#define LSH_uDAMAGECRITICAL                 0x9174C564
#define LSH_uPLAYER                         0xD0B9625A
#define LSH_DRIVER1                         0xAA55F4F6
#define LSH_DRIVER2                         0x335CA54C
#define LSH_DRIVER3                         0x445B95DA
#define LSH_DRIVER4                         0xDA3F0079
#define LSH_DRIVER5                         0xAD3830EF
#define LSH_OnlineSubTitleOptions           0x3F084C04
#define LSH_YES                             0x1C4077DC
#define LSH_NO                              0x3640D38A
#define LSH_OFF                             0x42E41F36
#define LSH_VirtualKeyboardDone             0xFA4D35D0

#define APT_MAIN_BTN_MULTI                  1

#define APT_MP_BTN_RACE                     0
#define APT_MP_BTN_ROAD_RAGE                1
#define APT_MP_BTN_TRAFFIC_ATTACK           2
#define APT_MP_BTN_CRASH                    3
#define APT_MP_BTN_BURNING_LAP              4
#define APT_MP_BTN_ELIMINATOR               5

#define APT_PAUSE_BTN_QUIT                  3

#define APT_MAX_UPDATES                     8
#define APT_SELECTORS_SETUP_UPDATE_NUM      5
#define MIN_STATIC_RIVALS                   0
#define MAX_STATIC_RIVALS                   5
#define MIN_CIRCULAR_RIVALS                 0
#define MAX_CIRCULAR_RIVALS                 98
#define MIN_LAPS                            1
#define MAX_LAPS                            99
#define MAX_RDRG_TIME                       16

#define STR_TRAFFIC                         "TRAFFIC"
#define STR_SELECT_RIVALS                   "SELECT RIVALS"
#define STR_TRAFFIC_CHECK                   "TRAFFIC CHECKING"
#define STR_AI_MODE                         "AI MODE"

#define STATE_AUTOSAVE                      0x9614A335FC1EF47Full

#define WELCOME_POPUP_TITLE                 "WELCOME BURNER"
#define WELCOME_POPUP_TEXT                  "\nSingle Event mode is BACK!\n\nMade by Nehalem (github.com/Nahelam)\n\nENJOY!"

#define COLL_STR_AUTOSAVE_POPUP_TITLE       "$Tj:CST"
#define COLL_STR_AUTOSAVE_POPUP_TEXT        "$?)+~00"
#define COLL_STR_RACE_SPLASH                "$>^7RY1"
#define COLL_STR_ROADRAGE_SPLASH            "$HUFi45"
#define COLL_STR_REVENGE_SPLASH             "$33JAUS"
#define COLL_STR_BURNINGLAP_SPLASH          "$P$)]DA"
#define COLL_STR_ELIMINATOR_SPLASH          "$b50nce"
#define COLL_STR_CRASH_SPLASH               "$VKy6st"
#define COLL_STR_EVENT_FINISHED             "$x_v;LE"
#define COLL_STR_DONE                       "$)+u<me"
#define COLL_STR_ARE_YOU_SURE               "$alP5qw"

#endif
