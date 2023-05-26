#!/bin/bash

cd ./src/boot/
nasm -f bin -o ../../bin/32bit_main.bin 32bit_main.asm

qemu-system-x86_64 -fda ../../bin/32bit_main.bin
