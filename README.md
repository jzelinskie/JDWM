# JDWM 5.8.2
https://github.com/JimmyZelinskie/JDWM
http://dwm.suckless.org

License information can be found in the dwm-5.8.2.tar.gz and in src/dwm-5.8.2/LICENSE.
I take no credit for writing any of this. All that I have done is put it all together and maybe changed a few lines of code to get things to play nicely.

## WHAT IS JDWM?
JDWM is simply how I use DWM. Currently, it's a just a messy upload of my DWM build directory so that others can easily pick up a version of DWM with a few popular community patches. It's set up so that anybody running the Arch Linux GNU/Linux distribution and get everything they need right away.
If you want to know more about how I use DWM, check out my website:
http://jzelinskie.com

## HOW DOES I JDWM?
It's the same as normal DWM, but with more options from patches. The installation script in the PKGBUILD copies the config.h from the root directory into the source directory, so edit that one unless you change things or are using a distribution besides Arch Linux.
I tried to make the config.h fairly generic, while also showing off some things you can do. If you want to see a very generic configuration look at the config.h.def.

## WHAT PATCHES ARE IN JDWM?
Currently, the following patches are pre-applied:
* cycle.c
* dwm-5.8.2-bstack-alt.diff
* dwm-5.8.2-fibonacci.diff
* dwm-5.8.2-pertag.diff
* dwm-5.8-pango.patch
* dwm-uselessgap-5.8.diff

For more information on the patches check out:
http://dwm.suckless.org/patches
https://bbs.archlinux.org/viewtopic.php?id=92895
