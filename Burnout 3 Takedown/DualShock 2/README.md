# DualShock 2 PS2 stuff

Only use one of the following at once.

## Disable buttons analog

This cheat disables the analog feature of the buttons, no more pressure sensitivity for them.

### SLES-52585 & SLUS-21050
```
Disable buttons analog
00214E48 00000004
00214F08 00000005
00214E88 00000006
00214EC8 00000007
00215000 00000008
00215080 00000009
00214FB4 0000000A
00215040 0000000B
00214D48 0000000C
00214E08 0000000D
00214DC8 0000000E
00214D88 0000000F
20216F80 03E00008
20216F84 46000806
20216F10 03E00008
20216F14 46000806
```

### SLES-52584
```
Disable buttons analog
00214E38 00000004
00214EF8 00000005
00214E78 00000006
00214EB8 00000007
00214FF0 00000008
00215070 00000009
00214FA4 0000000A
00215030 0000000B
00214D38 0000000C
00214DF8 0000000D
00214DB8 0000000E
00214D78 0000000F
20216F70 03E00008
20216F74 46000806
20216F00 03E00008
20216F04 46000806
```

## Reduce required pressure

This cheat reduces the analog buttons active zone pressure threshold to `0.15`.

- The default active zone pressure threshold is set to `0.9`
- The default dead zone pressure threshold is set to `0.1`

### SLES-52585 & SLUS-21050
```
Reduce analog buttons required pressure
20216F10 C7828114
20216F80 C7828114
```

### SLES-52584
```
Reduce analog buttons required pressure
20216F00 C7828114
20216F70 C7828114
```
