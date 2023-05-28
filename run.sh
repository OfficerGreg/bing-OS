#!/bin/bash


Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Color_Off='\033[0m'       # Text Reset


BOOT_DIR="./src/boot/"
KERNEL_DIR="./src/kernel/"
BIN_DIR="./bin/"


cd "$BOOT_DIR"
nasm boot_sect.asm -f bin -o ../../$BIN_DIR/boot_sect.bin 


echo -e "${Green}Compiled boot sector${Color_Off}"

cd ../..

cd "$KERNEL_DIR"

i386-elf-gcc -ffreestanding -c kernel.c -o kernel.o

echo -e "${Green}Compiled the kernel${Color_Off}"

i386-elf-ld -o ../../$BIN_DIR/kernel.bin -Ttext 0x1000 kernel.o --oformat binary

echo -e "${Green}Linked the kernel${Color_Off}"

rm -f kernel.o

cd ../..

cd "$BIN_DIR"

cat boot_sect.bin kernel.bin > ../OS-img.bin

cd ../
echo " "
echo " "

while true; do
  read -rp "Run the OS?  [Y/n] " choice

  if [[ $choice == "Y" || $choice == "y" || $choice == "" ]]; then
    qemu-system-i386 -fda OS-img.bin
    break
  elif [[ $choice == "N" || $choice == "n" ]]; then
    echo "Exiting."
    break
  else
    echo "Invalid input. Please enter 'Y' or 'n'."
  fi
done
