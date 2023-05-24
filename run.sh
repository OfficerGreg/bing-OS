#!/bin/bash

cd ./src/
nasm -f bin -o ../bin/boot_sect_main.bin boot_sect_main.asm

qemu-system-i386 -fda ../bin/boot_sect_main.bin
