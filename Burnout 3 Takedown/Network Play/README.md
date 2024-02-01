# PCSX2 Burnout 3: Takedown Network Play

These patches are bringing back network play by connecting to No23's server emulator.

The new patches doesn't rely on IOP addresses for patching the certificate verification, everything is done through the EE, which means 100% reliability.

I wrote a stub which loads the DirtySock module file into a buffer located in the EE memory, applies the certificate verification patch to it, then tells the IOP to load this buffer as a module (sceSifLoadModuleBuffer function) instead of reading it directly from the file system. Once the module is loaded, the memory allocated for this operation is freed, the buffer is cleared and the game continues its execution normally.

If you were fine with the previous (less reliable) version of these patches, you can still find them in the [Old Patches](https://github.com/Nahelam/PCSX2-Burnout-Mods/tree/main/Burnout%203%20Takedown/Network%20Play/Old%20Patches) folder.
