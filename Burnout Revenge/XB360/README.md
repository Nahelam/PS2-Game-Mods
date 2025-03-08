# Burnout Revenge XB360 Mods (Xenia)

Mods I made for the Xbox 360 version of **Burnout Revenge**.

Use the **TU0** file if you're using the base version of the game (most common).\
If you installed the game update use the **TU1** file instead.

## Enabling/Disabling patches

To enable or disable a patch, change its `is_enabled` value to `true` or `false`.

## Mod List
- Replace extras menu with debug menu
- Selectable crash vehicles in all modes
- Ignore road rage event timer (also disables timer HUD display)
- Disable game mode HUD
- Disable rating HUD
- Standing start instead of rolling start in offline modes (boost start enabled for Race, Burning Lap & Eliminator)
  - Countdowns of **3**, **5**, **10**, **15**, **30** and **60** seconds are available, uncomment/comment in the patch to enable/disable, default is **3**
- Camera speed shake (disable, super, hyper, uber) **(only one at once)**

## Troubleshooting

Currently, the provided patch files only contain the hash of the US game version.\
If the patches aren't applied at game start, it is probably because your game is from a different region or has been modded.
### Fix
  1. Quickly launch and exit the game
  2. In your Xenia folder, look for the file `xenia.log` and open it with a text editor
  3. Search for the line containing `Module Hash:`
  4. Copy the hash and add it to the patch file
  6. Done

[Example of a patch file containing multiple hashes](<https://github.com/xenia-canary/game-patches/blob/main/patches/454107D9%20-%20Need%20for%20Speed%20Most%20Wanted%20(2005).patch.toml#L3-L8>)
