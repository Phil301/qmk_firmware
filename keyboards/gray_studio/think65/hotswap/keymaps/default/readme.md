# The default keymap for the hotswap Think6.5 PCB

## Static and Dynamic lighting

The Think6.5 has three main groups of LEDs: 4 under the Escape key, 4 above the badge, and 14 under the PCB to provide underglow. This firmware allows you to enable and disable LED ranges in both dynamic and static lighting environments.

### LED cycling

This map saves and restores your current active LED group choice to user EEPROM and restores it on keyboard init, which you can cycle through all combinations of, or toggle individually.

The cycle is `Off -> Esc -> Badge -> Underglow -> Esc+Badge -> Esc+Underglow -> Badge+Underglow -> All`. Look at the keymap for the controls on layer 1. Note that dynamic lighting is not supported for `Esc+Underglow`.

### LED range colours

This map also allows you to set different colours for each of the different LED ranges (Esc, Badge and Underglow) in static lighting mode, and those colours will be restored when you restart the keyboard. Look at the keymap for the controls on layer 1.

### Known issues

Because of how RGB toggling works in QMK, if you set your own LED range colours and then toggle RGB off and on with `RGB_TOG`, you'll get QMK's view of the colours rather than the ones you set. Just adjust the user range in some way and your custom colours will be restored.
