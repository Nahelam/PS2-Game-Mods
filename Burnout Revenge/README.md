# Burnout Revenge Mods

Various cheats/patches/mods I made/ported for **Burnout Revenge**.

### Note
PCSX2/PS2 features listed below aren't fully available for all regions, please check the `.pnach` file of your game region for a definitive list.

## PCSX2/PS2 Features
- Native widescreen
- Always show the progressive scan menu
- Replace extras menu with debug menu
- Speedometer HUD unit patch (MPH->KPH)
- No lap limit in Burning Lap mode
- Disable camera speed shake
- Selectable crash vehicles in all modes
- Allow online games to be started even you're the only player in the lobby (Solonline)
- Offline car air control
- Disable rating HUD display
- Disable game mode HUD display
- Enable timer in race events **(only one at once)**
  - Each lap version (with display freezing 5 seconds on new lap start)
  - Total time version (no reset between laps)
- Race events lap modifier
- Disable HUD
- [Single Event Mod](https://github.com/Nahelam/PS2-Game-Mods/tree/main/Burnout%20Revenge/Single%20Event%20Mod)
- [APT debug print to PCSX2 logs](https://github.com/Nahelam/PS2-Game-Mods/assets/128867759/182b704b-1a1a-4a4f-a665-8bbf31ba9799)
    - Restored an APT debug print function, it was given args but doing nothing with it. I used scePrintf to print in the PCSX2 logs.
- Toggleable free camera (R3+UP enable, R3+DOWN disable) **(only one at once)**
  - Basic version
  - No HUD version
- Disable "Press R1 to boost" HUD hint
- Render all extra particles while driving
- Toggleable gameplay (R2+DPAD UP enable, R2+DPAD DOWN disable) **(only one at once)**
  - Basic version
  - No HUD version
- Falling car parts during takedowns and traffic checks 
- Moon jump (DPAD UP) [\[demo\]](https://www.reddit.com/r/Burnout/comments/1dghna2/predator_missile_inbound)
- Third person rear view [\[demo\]](https://i.imgur.com/tVVHGAR.png)
- Toggle the player being AI controlled (L3+UP enable, L3+DOWN disable)
- Enable props in Road Rage and Traffic Attack
- Force a specific LOD for race cars (+ optionally prevent race cars reflections from fading further away)
- Kamikaze traffic
- Prevent out of range removal of crashing traffic
- Toggle menus rendering

## Xenia (Xbox 360) Features (.toml file)
- Replace extras menu with debug menu
- Selectable crash vehicles in all modes
- Ignore road rage event timer (also disables timer HUD display)
- Disable game mode HUD
- Disable rating HUD
