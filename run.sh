#!/bin/bash


nasm -f bin -o boot_sector.bin boot_sector.asm
nasm -f bin -o print.bin print.asm
nasm -f bin -o print_hez.bin print_hex.asm

cat boot_sector.bin print.bin print_hex.bin > main.bin

qemu-system-i386 -fda main.bin
