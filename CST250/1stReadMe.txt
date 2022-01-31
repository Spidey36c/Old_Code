---------------------------------------------------------
1stReadMe for PIC32MX Peripheral Support Libraries, V1.00
---------------------------------------------------------

Overview:
---------
Starting with XC32 V1.40, PIC32MX peripheral support libraries are no longer
installed as part of the compiler's installation.  These libraries are now
installed as a second step, *after* the installation of an XC32 compiler.

The compiler must be installed *first* so that the directories 

    .\Microchip\xc32\v*\docs
    .\Microchip\xc32\v*\pic32-libs
    .\Microchip\xc32\v*\pic32mx
    
have been created.  The peripheral support library installer will write
additional files into these directories.


System Requirements:
--------------------
Basically if you can install an XC32 compiler then you can install the PIC32MX
peripheral support libraries.  (See the compiler's README.html for more 
details.)  Windows, Linux, and Macintosh OS X operating sytems are supported.

These libraries are compatible with XC32 V1.40 or later.


Devices Supported:
------------------
Only PIC32MX devices are supported by these peripheral support libraries.
Support for new PIC32MX devices (PIC32MX130F256B, PIOC32MX130F256D, 
PIC32MX230F256B, and PIC32MX230F256D) has been added with this version.


PIC32MX Peripheral Support Library Documentation:
-------------------------------------------------
Library documentation can be found in 

    .\Microchip\xc32\v*\docs\pic32-lib-help\*.chm

help files.


Peripheral Support Library Revision History:
--------------------------------------------
V1.00:
  First release of perpheral support libraries separate from compiler 
  installation.  In XC32 V1.34 and earlier PIC32MX peripheral support libraries
  were installed as part of compiler installation.  From XC32 V1.40 and later
  PIC32MX peripheral support libraries are installed separately, after the 
  compiler is installed.
  
  Support for new devices (PIC32MX130F256B, PIOC32MX130F256D, PIC32MX230F256B,
  and PIC32MX230F256D) has been added.


Customer Support:
-----------------
Microchip provides online support via our home page at:
    http://www.microchip.com

Technical support is available through the web site at:
    http://www.microchip.com/support

A forum for discussion of Microchip products and tools is available at:
    http://www.microchip.com/forums
    See the 
        Development Tools>>MPLAB XC32
    or 
        32-Microcontrollers>>General PIC32 Topics
    subforums.

Microchip PIC32 documentation and product info is available at:
    http://www.microchip.com/pic32

Microchip MPLAB XC Compiler info is available at:
    http://www.microchip.com/MPLABXCcompilers
