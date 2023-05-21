#!/bin/bash

nasm boot_sector.asm -f bin -o boot_sector.bin

qemu-system-i386 -fda boot_sector.bin
