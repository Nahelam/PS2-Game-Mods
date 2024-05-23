# DualShock 2 PS2 stuff

## Lowering DS2 pressure sensitive buttons active zone threshold

Lower the amount of pressure required by pressure sensitive buttons to *0.15* (doesn't affect triggers/analog)

- The default active zone threshold is set to *0.9*
- The default dead zone threshold is set to *0.1*

Use the patch corresponding to your game region:

### SLES-52585 & SLUS-21050
```
Lower buttons active zone threshold
20216F80 C7828114
```

### SLES-52584
```
Lower buttons active zone threshold
20216F70 C7828114
```
