# Crash Breaker Expansion (PS2)

## Embedding

Since this patch is too big for PS2 cheat engines, it has to be embedded in the game executable to work properly.

Thanks to the [ELF Code Cave](https://github.com/Nahelam/PS2-Game-Mods/tree/main/Burnout%203%20Takedown/ELF%20Code%20Cave) we have more than enough space to make it happen.

Please note that it hasn't been embedded fully (to remain toggleable).\
After patching your game iso, you have to enable it with the following code:

```
Crash Breaker Expansion
201BB9B8 00000000
201BEA14 0C05AD3C
201B2C90 0260202D
201B2C94 0C05AD64
201B2C98 0200282D
201B2D38 0C05AD94
201B2D50 0C05ADC6
201B2D54 0260202D
201B2D58 00000000
201B2D88 0C05ADD2
201B2D8C 0260202D
201B2D90 00000000
201B3714 0260202D
201B3718 0C05ADDE
201B371C 0200282D
201B3724 0040902D
201B3728 00000000
201B39D0 0C05AE1E
201A1410 0C05AE2A
204DDE34 0016B9A0
203A34B8 0C05AE94
```

## Notes

Online support is included in the provided xdelta patches.
