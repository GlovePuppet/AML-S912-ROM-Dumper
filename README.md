# AML-S912-ROM-Dumper

Replace the file:

arch/arm/cpu/armv8/gxb/firmware/bl21/bl21_main.c

With this one, build FW & UBoot as normal, during boot the S912 ROM will be spewed out of the serial port (all 256KB of it)

Capture the spew into a file called rom.txt (trim of the AMLogic startup noise) and convert to a binary suitable for reversing:

cat rom.txt | xxd -r -p > rom.bin
