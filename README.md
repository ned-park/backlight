# backlight
Simple C program to adjust the backlight up or down when xbacklight isn't supported.
I use this on a linux system with an intel card UHD620, but it can probably support other cards
if you locate the backlight file.  

Occasionally the xorg intel driver is buggy and I switch to the MESA driver which 
leaves xbacklight unable to find a supported display.  Binding this to brightness keys
enables easy adjustment.

By using the program, you agree that the author is not responsible for any damage caused
by misconfiguring the program.  

## Build instructions:

Locate the file that contains the brightness level, probably somewhere in /sys/,
someone may well have done this already for your card, so google is worth a look
look, otherwise `find /sys -name *brightness` may help.  Determine the maximum and 
minimum desired values, and your preferred step sizes and edit the constants at the 
top of the file so that it points to the brightness file.  

This may not work on all systems, and is provided here as a convenience without warranty.
Odds are high it won't work if your driver is different, or if your video card is different
from my own.

    gcc -o backlight backlight.c

## Usage:

    # backlight +

    # backlight -


