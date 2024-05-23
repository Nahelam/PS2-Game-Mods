# DualShock 2 PS2 stuff

## Lowering DS2 pressure sensitive buttons active zone threshold

Lower the amount of pressure required by pressure sensitive buttons (doesn't affect triggers/analog)

The default active zone threshold is set to 0.9
The default dead zone threshold is set to 0.1

To set the active zone threshold to 0.15, use the patch corresponding to your game region:

### SLES-52585 & SLUS-21050
```
Lower buttons active zone threshold (0.15)
20216F80 C7828114
```

### SLES-52584 & SLUS-21050
```
Lower buttons active zone threshold (0.15)
20216F70 C7828114
```
