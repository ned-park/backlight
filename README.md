# backlight
A simple C program to adjust the backlight up or down when xbacklight isn't
supported.  I use this on a linux system with an intel UHD620 graphics card,
but it can probably support other cards if you locate the backlight file. 

Binding the + and - options to brightness hotkeys allows for convenient (and 
expected) behaviour.  The s <int> option is most convenient for large changes
in brightness done through the command line or during testing.  

## Technology used
C, Linux, make, man

## Build instructions:

Locate the file that contains the brightness level, probably somewhere in
/sys/, someone may well have done this already for your card, so google is
likely the simplest, otherwise `find /sys -name *brightness* 2> /dev/null` may
help.  Determine the maximum and minimum desired values, your preferred step
sizes, and then edit the constants by creating a config.h file from the
existing config.def.h if your system or preferences for step size differ from
the defaults.  

This may not work on all systems and is provided without warranty.  By using it
you accept any risk.  

    make

    make clean

    sudo make clean install

## Usage:

    # backlight +

    # backlight -
    
    # backlight s n, where n is a number between the min and max allowed 
    values for your card.  

## What I learned
 - How to interface with the kernel using /sys files
 - How to write make files
 - How to write man pages

