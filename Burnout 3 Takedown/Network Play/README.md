# Burnout 3: Takedown - Online

*Online mode is back thanks to /dev/ghostline's [server emulator](https://gitlab.com/gh0stl1ne/eaps)!*

In this category you will find an alternative patch method that leaves your game iso untouched.

Available patches are currently redirecting the game network traffic to `bosrv.org`, hosted by [/dev/ghostline](https://gitlab.com/gh0stl1ne) himself.

## New Method

Except iso patching only one method was available to bypass the certificate check (while keeping encryption enabled).

It was done by patching the IOP network module named `DRTYSCKF.IRX` (which handles network communications between EA servers and your console by default) in PCSX2 IOP memory at a specific address but this wasn't truly reliable because this address, for some reason, could change, which was bad because a PCSX2 patch requires fixed addresses to work properly.

The new patching method uses the EE memory instead, where addresses are guaranted to stay the same for our use case, which makes it fully reliable. This new method is compatible with [HostFS patches](https://github.com/Nahelam/PCSX2-HostFS-Patches/tree/main/Criterion%20Games) and is also working on [real consoles](https://github.com/Nahelam/PS2-Game-Mods/tree/main/Burnout%203%20Takedown/Network%20Play/PS2) using a cheat engine (Action Replay, ps2rd, etc.).

## How?

The patch applied to `DRTYSCKF.IRX` is exactly the same as the one used in a pre-patched iso, except that it gets patched on the fly instead of patching the whole iso.

It works by altering the game behaviour when it comes to loading `DRTYSCKF.IRX`. By default the game will ask the IOP to read it directly from the game disc.

Using the new method an authentic copy `DRTYSCKF.IRX` is written into the EE memory, then the certificate check bypass patch is applied to the memory copy of the module and finally we ask the IOP to load `DRTYSCKF.IRX` from a memory location instead of the game disc by using the `sceSifLoadModuleBuffer` function.

Once the module is loaded, the necessary cleanup is made in the EE memory and the game can continue its execution normally.

## Extra Patches

### Disable UPnP

If you want to prevent the game from using UPnP.

### Disable Buddy System

The current server emulator has a known issue causing a lot of pre-game timeouts when using the buddy system .\
Preventing the game from communcating with the buddy server avoids this issue, please note that **ALL** players must have it enabled.
