#!/bin/bash

cd ./src/boot/
nasm boot_sect.asm -f bin -o ../../bin/boot_sect.bin 

echo "Compiled boot sector\n"

cd ..

cd ./kernel/

i386-elf-gcc -ffreestanding -c kernel.c -o kernel.o

echo "Compiled the kernel\n"

i386-elf-ld -o ../../bin/kernel.bin -Ttext 0x1000 kernel.o --oformat binary

echo "Linked the kernel\n"

rm -f kernel.o

cd ../../bin/

cat boot_sect.bin kernel.bin > ../OS-img.bin

cd ../

qemu-system-i386 -fda OS-img.bin
