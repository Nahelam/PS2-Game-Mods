# Various Game Modifications

These folders contains various cheats/patches/mods I made for Burnout 3: Takedown.

## Features
- Speedometer HUD unit patches (mph->kph & kph->mph) [\[demo\]](https://i.imgur.com/PbpCkr6.png)
- Heavyweights class always available in garage (ported, original SLUS patch made by [escape209](https://github.com/escape209))
- Allow heavyweights class to be chosen in all online game modes (all players must enable it)
- Allow online games to be started even you're the only player in the lobby  [\[demo\]](https://i.imgur.com/H1bmaBl.mp4)
- AI road rage behavior in normal races [\[demo\]](https://i.imgur.com/RLtPeuw.mp4)
- Turn all cars (except traffic) into tuk-tuks
- Enable non-takedown burnout points in road rage mode
- Force standing start in offline modes [\[demo\]](https://i.imgur.com/ZGCcGan.mp4)
- Change deformation impulse scale (set the float value of your choice on line 6, current value is default) [\[demo\]](https://i.imgur.com/iG091lm.png)
- Crash your car on demand by pressing SELECT\* [\[demo\]](https://i.imgur.com/3JVfbuU.mp4)
- Moon jump by pressing DPAD UP\* (you can set the float value of your choice on line 6, current value is 1.0) [\[demo\]](https://i.imgur.com/zzAqRfu.mp4)
- Partial mirror mode (everything is mirrored but controls work) [\[demo\]](https://i.imgur.com/WlghMuC.mp4)
- Vertical split screen [\[demo\]](https://i.imgur.com/5crTbar.png)
- Enable time limit in single event road rage\* (you can set the float value of your choice on line 6, current value is default) [\[demo\]](https://i.imgur.com/5uQTYw4.mp4)
- Enable lap timer in race mode\* (you can set the float value of your choice on line 6, current value is 88.0) [\[demo\]](https://i.imgur.com/zP0iQnc.png)
- Enable lap timer in road rage mode\* (you can set the float value of your choice on line 6, current value is 88.0)
- Show distance between you and other drivers in races (disables score HUD)\* (use **_ws** file if you're using PCSX2 widescreen patches) [\[demo\]](https://i.imgur.com/qws0uEH.mp4)
- Disable traffic\*
- Show AI drivers names\* [\[demo\]](https://i.imgur.com/RwdDiob.jpg)
- Draw all checkpoints on the track\* [\[demo\]](https://i.imgur.com/n1puKRi.jpg)
- Rivals number in road rage options\* [\[demo\]](https://i.imgur.com/IUVA81H.png)
- Select rivals cars in garage before single event start\* [\[demo\]](https://i.imgur.com/2w6035K.mp4)
- Disable HUD\*
- Toggle pause gameplay (R2+DPAD UP and R2+DPAD DOWN)\* [\[demo\]](https://i.imgur.com/6swIHzt.mp4) in combination with the [free camera code](https://tcrf.net/Burnout_3:_Takedown#Camera_Modes), now we can take good shots ;p
- Toggle AI controlled player car (DPAD DOWN)\*
- Disable 5 minutes idle check (pause menu opening automatically)\*
- Disable automatic event ending for very long games\*
- Disable camera switch when crashing\*
- Change offline traffic generation seed\*
- Kamikaze traffic "clean" (no more "crashing" state but the game still crashes when too many traffic vehicles have crashed, also affects AI)\*
- Force specific LOD level (details in patch comments)\*
- Chrome color on all vehicles\*
- Draw debug body hulls\*
- Draw debug collision world (see patch comments for "leaf" mode and track rendering fix)\*
- Draw debug intervals\*
- Draw debug near miss data\*
- Draw debug traffic spatial triggers\*
- Disable vehicle sounds (makes driveable traffic mods on real hardware possible)\*
- Turn back on the horn volume, press CIRCLE or R3 to honk (the functionality was always there, but the volume was turned off, see patch comments for button remapping)
- Enable manual transmission (L2 downshift, R2 upshift, see patch comments for button remapping)\*
- Turn on vehicle headlights while holding horn buttons (CIRCLE or R3 by default)\* [\[demo\]](https://i.imgur.com/U87YRuD.mp4)
- Turn on all race cars headlights permanently\*
- Glass cars (make all vehicles look ghostly)\* [\[demo\]](https://i.imgur.com/LVm50S9.png)
- Activatable Crash Breaker in all modes (R2, see patch comments for unlimited mode)\* [\[demo\]](https://i.imgur.com/PzgJJgr.mp4)
- Render other vehicles explosions while driving\*

\*: SLES-52584, SLES-52585 & SLUS-21050 only  

## Notes
- "Heavyweights always available" is **required** to get heavyweights online working.
- "Rivals number in road rage options" is also included in "Select rivals cars in garage".
- **DO NOT** use "Enable lap timer in race mode" and "Enable lap timer in road rage mode" together.
- Disable the takedown camera if you don't want the game to bring you back car controls while using the AI controlled patch
