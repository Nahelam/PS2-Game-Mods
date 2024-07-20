# How to use/install these mods

## PCSX2
1. Locate the `cheats` folder of your PCSX2 installation
2. Find the [ID](https://www.ps2-home.com/forum/viewtopic.php?p=22588) of the game you want to download mods for (usually "Serial" in PCSX2 game properties)
3. Locate the mods available for your game ID (the targeted game ID is either in the file name or in the folder name)
4. Download the `.pnach` file of the mod you want and place it in the `cheats` folder
5. If the `.pnach` file is using the [new format](<https://forums.pcsx2.net/Thread-Sticky-Important-Patching-Notes-1-7-4546-Pnach-2-0>) you will be able to turn on/off the mod in the "Cheats" interface of your game properties, otherwise it will be automatically enabled and shown as "unlabelled"
6. Profit

Also, if you are using an already modded game iso, you will have to replace the CRC in the mod file name accordingly.

For example you want to use the [dev menu](https://github.com/Nahelam/PS2-Game-Mods/blob/main/Burnout%203%20Takedown/Development%20Menu/SLUS-21050/BEBF8793_dev_menu.pnach) with your modded Burnout 3 NTSC iso whose CRC is `E681D9AE`, to do so you will have to rename `BEBF8793_dev_menu.pnach` to `E681D9AE_dev_menu.pnach`.

## PS2
A good part the mods available here should work on PS2, you just have to do the pnach -> RAW conversion.

In some cases you will find a `PS2` folder containing ready-to-use PS2 RAW codes and/or xdelta patches that you'll have to apply to your game iso.

## Downloading files
To download a single file, browse it then click the `Download raw file` button.

 ![dlraw](https://github.com/user-attachments/assets/2d1fd9cc-b500-449d-bf00-fdb9ceb9321c)
