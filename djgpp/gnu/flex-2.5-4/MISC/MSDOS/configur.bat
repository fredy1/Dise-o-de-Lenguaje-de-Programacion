@echo off

sed -f MISC/MSDOS/djgpp.sed Makefile.in > Makefile
update MISC/MSDOS/config.h config.h
touch config.status
