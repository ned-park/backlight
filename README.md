# backlight
A simple C program to adjust the backlight up or down when xbacklight isn't supported.
I use this on a linux system with an intel UHD620 graphics card, but it can probably support other cards
if you locate the backlight file.  

Occasionally the intel video driver is buggy and I switch to the MESA driver which 
leaves xbacklight unable to find a supported display.  Binding this to brightness keys
enables easy adjustment through my window manager.

By using the program, you agree that the author is not responsible for any damage caused
from misconfiguring the program.  

## Technology used
C, Linux

## Build instructions:

Locate the file that contains the brightness level, probably somewhere in /sys/,
someone may well have done this already for your card, so google is likely the simplest,
otherwise `find /sys -name *brightness* 2> /dev/null` may help.  Determine the maximum and 
minimum desired values, your preferred step sizes, and edit the constants at the 
top of the file so that it points to the brightness file.  

This may not work on all systems and is provided here as a convenience without warranty.

    gcc -o backlight backlight.c

## Usage:

    # backlight +

    # backlight -
    
    # backlight s n, where n is a number between the min and max allowed values for your card.  

I have these bound to hotkeys in dwm, which works quite well.  I've (probably against security best practices) setup passwordless sudo on the backlight command to allow for convenient invocation.  I suspect similar behaviour could be achieved in other window managers as well.

## What I learned

How to interface with the kernel using files in /sys to alter screen brightness settings (and other things)
