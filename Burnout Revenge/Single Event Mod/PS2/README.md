# Single Event Mod (PS2) - WIP, needs testing

First attempt of porting the mod on real PS2 consoles, testing with the NTSC version of the game.  
Not guaranted to work, only use if you're willing to help testing on real hardware.  
Use the provided **xdelta** file to patch your game iso (there are various patching tools available, such as [Delta Patcher](https://github.com/marco-calautti/DeltaPatcher/releases/latest))  

Please leave feedback [here](https://www.reddit.com/r/Burnout/comments/1eu2xe4/burnout_revenge_ps2_single_event_mod/) or in [issues](https://github.com/Nahelam/PS2-Game-Mods/issues).

## Mastercode

If your Mastercode is different from the one below, replace it.
```
Mastercode
90449D08 0C1126EA
```

## Enable the Single Event Mod

Use the following code to enable the Single Event Mod embedded in your freshly patched iso.

```
Enable Single Event Mod
20255F50 0C042746
```
### ~~~
