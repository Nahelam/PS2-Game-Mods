# PS2 Game Mods

A browsable compilation of my PS2 game mods.\
You will mostly find PCSX2 mods in the `pnach` format but many of them should also work on real PS2.

Non-exhaustive list of my most notable mods:

- [HostFS](https://github.com/Nahelam/PCSX2-HostFS-Patches/tree/main) *(All PS2 Criterion games)*
- [Crash Breaker Expansion](https://github.com/Nahelam/PS2-Game-Mods/tree/main/Burnout%203%20Takedown/Crash%20Breaker%20Expansion) *(Burnout 3: Takedown)*
- [Single Event Mod](https://github.com/Nahelam/PS2-Game-Mods/tree/main/Burnout%20Revenge/Single%20Event%20Mod) *(Burnout Revenge)*
- [Network Play](https://github.com/Nahelam/PS2-Game-Mods/tree/main/Burnout%203%20Takedown/Network%20Play) *(Burnout 3: Takedown)*

## Usage

### PCSX2
1. Locate the `cheats` folder of your PCSX2 installation
2. Find the [ID](https://www.ps2-home.com/forum/viewtopic.php?p=22588) of the game you want to download mods for (usually "Serial" in PCSX2 game properties)
3. Locate the mods available for your game ID (the targeted game ID is either in the file name or in the folder name)
4. Download the `.pnach` file of the mod you want and place it in the `cheats` folder
5. If the `.pnach` file is using the [new format](<https://forums.pcsx2.net/Thread-Sticky-Important-Patching-Notes-1-7-4546-Pnach-2-0>) you will be able to turn on/off the mod in the "Cheats" interface of your game properties, otherwise it will be automatically enabled and shown as "unlabelled"
6. Profit

Also, if you are using an already modded game iso, you will have to replace the CRC in the mod file name accordingly.

For example you want to use the [dev menu](https://github.com/Nahelam/PS2-Game-Mods/blob/main/Burnout%203%20Takedown/Development%20Menu/SLUS-21050/BEBF8793_dev_menu.pnach) with your modded Burnout 3 NTSC iso whose CRC is `E681D9AE`, to do so you will have to rename `BEBF8793_dev_menu.pnach` to `E681D9AE_dev_menu.pnach`.

### PS2
A good part the mods available here should work on PS2, you just have to do the pnach -> RAW conversion.

In some cases you will find a `PS2` folder containing ready-to-use PS2 RAW codes and/or xdelta patches that you'll have to apply to your game iso.

### Downloading files
To download a single file, browse it then click the `Download raw file` button.

 ![dlraw](https://github.com/user-attachments/assets/2d1fd9cc-b500-449d-bf00-fdb9ceb9321c)
