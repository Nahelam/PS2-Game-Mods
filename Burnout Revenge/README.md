# Burnout Revenge Mods

Various cheats/patches/mods I made/ported for **Burnout Revenge**.

## PCSX2/PS2 Features (SLUS-21242)
- Native widescreen
- Always show the progressive scan menu
- Replace extras menu with debug menu
- Speedometer HUD unit patch (MPH->KPH)
- No lap limit in Burning Lap mode
- Disable camera speed shake
- Selectable crash vehicles in all modes
- Allow online games to be started even you're the only player in the lobby (Solonline)
- Offline car air control
- Disable rating HUD component
- Disable game mode HUD component
- Enable timer in race events (cannot be used together)
  - Each lap version (with display freezing 5 seconds on new lap start)
  - Total time version (no reset between laps)
- Race events lap modifier
- Disable HUD
- Turn multiplayer mode into single event mode (WIP)
    - **NOTE**: Crash Party becomes Burning Lap and Crash Tour becomes Eliminator
- [APT debug print to PCSX2 logs](https://github.com/Nahelam/PS2-Game-Mods/assets/128867759/182b704b-1a1a-4a4f-a665-8bbf31ba9799)
    - Restored an APT debug print function, it was given args but doing nothing with it. I used scePrintf to print in the PCSX2 logs.
- Toggleable free camera (R3+UP enable, R3+DOWN disable)
- Disable "Press R1 to boost" HUD hint

## Xenia (Xbox 360) Features (.toml file)
- Replace extras menu with debug menu
- Selectable crash vehicles in all modes
- Ignore road rage event timer (also disables timer HUD display)
- Disable game mode HUD
- Disable rating HUD
