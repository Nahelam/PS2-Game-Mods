# Burnout Revenge Madden Demo PS2 Mods (PCSX2)

Mods I made for the PlayStation 2 demo version of **Burnout Revenge** (available in the US version of **Madden NFL 06**).

## Mod List
- Host filesystem (easy file swaps/additions)
- 480p video mode
- Native widescreen (16:9)
- Prevent boot TLB miss errors
- No in-game idle time limit
- Main menu "QUIT" option opens the debug (quick start) menu
- Pause menu "QUIT" option goes back to the main menu
- 3 laps Single Race mode

## HostFS Repack

Repacking the game demo to a standalone and host filesystem compatible version is the most convenient way to play it on emulator.\
The game will have its own configurable properties and game fixes (no black skybox etc.) will be applied correctly.

### Create iso

- Extract the `B4` folder (located in the `BURNOUT` folder) of your **Madden NFL 06** iso to the location of your choice
- Create a new temporary folder, copy `B4_NTSC.ELF` (located in the `B4` folder we preivously extracted) into it and rename it to `SLUS_212.42`
- Create a new file named `SYSTEM.CNF` and fill it with the following content using a text editor:
   ```
   BOOT2 = cdrom0:\SLUS_212.42;1
   VER = 1.00
   VMODE = NTSC
   ```
- Now your temporary folder contains two files, `SLUS_212.42` and `SYSTEM.CNF`
- [Create a new iso file](https://github.com/Nahelam/PCSX2-HostFS-Patches/tree/main/Criterion%20Games#additional-steps-optional) based on your temporary folder (it is the equivalent of the `whatever` folder in the video)
- Copy the new iso file into the `B4` folder we created earlier (you can now remove the temporary folder if you want to)

### Add iso to PCSX2

- Add the `B4` folder to your PCSX2 game search directories
- Make sure `Enable Host Filesystem` is checked in your PCSX2 emulation settings
- In the game cheat settings, make sure `All CRCs` is unchecked, click `Reload Cheats` and they should be listed correctly
- Always keep the `HostFS` cheat enabled

### Start game and profit
