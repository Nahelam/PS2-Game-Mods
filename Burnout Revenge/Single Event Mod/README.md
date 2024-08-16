# Single Event Mod

![b4sem](https://github.com/user-attachments/assets/4f689fb9-bd03-48fb-86de-bc9cf7fb6552)

## About

This mod replaces the **Multiplayer** option with a brand new **Create Game** (single event) option.

It lets you choose between the following one player game modes:
- Race
- Road Rage
- Traffic Attack
- Crash
- Burning Lap
- Eliminator

Modifying the menus and preserving a "vanilla" look has been tough but I'm quite proud of the end result.  
A lot of function hooks were implemented to make the game handle everything correctly (menus, new options, etc.).

I wanted to make this patch available for all regions of the game thus I used as much localized strings as possible.  
Only a few are still hardcoded in english.

## New Options

### Race

- **Laps**: The number of laps you'll have to perform *(0-99)*
- **Rivals**: The number of opponents you want to face *(0-99)*
- **Select Rivals**: Choose the vehicle and color of all the opponents *(Yes/No)*
- **AI Mode**: Choose opponents behavior *(Race/Road Rage)*
- **Traffic**: Enable or disable traffic *(Yes/No)*
- **Traffic Checking**: Enable or disable traffic checking *(Yes/No/Insane)*
- **Oncoming**: Enable or disable oncoming boost reward *(Yes/No, always Yes when traffic is enabled)*
- **Crashbreaker**: Enable or disable the Crashbreaker *(Yes/No)*

### Road Rage

- **Time Limit**: Choose or disable time limit *(Off/1-16 minutes)*
- **Damage Critical**: Enable or disable elimination when your car is too damaged *(Yes/No, always Yes if there is no time limit)*
- **Rivals**: The number of opponents you want to face *(0-5)*
- **Select Rivals**: Choose the vehicle and color of all the opponents *(Yes/No)*
- **AI Mode**: Choose opponents behavior *(Race/Road Rage)*
- **Traffic**: Enable or disable traffic *(Yes/No)*
- **Traffic Checking**: Enable or disable traffic checking *(Yes/No/Insane)*
- **Oncoming**: Enable or disable oncoming boost reward *(Yes/No, always Yes when traffic is enabled)*
- **Crashbreaker**: Enable or disable the Crashbreaker *(Yes/No)*

### Traffic Attack

- **Traffic Checking**: Enable or disable traffic checking *(Default/Insane)*
- **Time Limit**: Enable or disable time limit *(Yes/No)*

### Burning Lap

- **Traffic**: Enable or disable traffic *(Yes/No)*
- **Traffic Checking**: Enable or disable traffic checking *(Yes/No/Insane)*
- **Oncoming**: Enable or disable oncoming boost reward *(Yes/No, always Yes when traffic is enabled)*

### Eliminator

- **Rivals**: The number of opponents you want to face *(0-99)*
- **Select Rivals**: Choose the vehicle and color of all the opponents *(Yes/No)*
- **AI Mode**: Choose opponents behavior *(Race/Road Rage)*
- **Traffic**: Enable or disable traffic *(Yes/No)*
- **Traffic Checking**: Enable or disable traffic checking *(Yes/No/Insane)*
- **Oncoming**: Enable or disable oncoming boost reward *(Yes/No, always Yes when traffic is enabled)*
- **Crashbreaker**: Enable or disable the Crashbreaker *(Yes/No)*

## Extras

### Profile Save

After each event you will have the choice to save your profile data or not.

### Burning Lap -> Time Attack

Burning Lap mode behavior has been changed to Time Attack:
- No lap limit
- Personal best shown
- Lap marker enabled

### Finish Session

You can end the current event from the pause menu in
- the Burning Lap mode after performing at least one lap.
- the Traffic Attack mode when the time limit is disabled and your score is > 0.

### Opponent Limit

In Race and Eliminator modes you can choose up to **99** opponents.  
The "active" opponents limit is still **5**, they will be adjusted according to your position.  
The "adjusting" mechanic was only working properly in Race mode, support for Eliminator has been added.

### Lap Limit

In Race mode you can choose up to **99** laps.  
The "Hit Count" HUD component from Crash mode has been used to display 2 digits laps properly.  
The default lap HUD component couldn't display more than 1 digit.

### Insane Traffic Checking

My favorite one, when the **Traffic Cheking** option is set to *Insane* you will be able to check all the traffic.  
You can check the same traffic vehicle until it vanishes.  
Each time you touch a traffic car with enough speed it will count as a check.  
Opponents are also given that power but they can't take you or other drivers down with traffic.

## Install

Follow the [install instructions](https://github.com/Nahelam/PS2-Game-Mods/blob/main/README.md) and make sure to delete/disable the previous WIP Single Event patch.
