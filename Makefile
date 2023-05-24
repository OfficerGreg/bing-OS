OS: 
	nasm -f bin -o ./bin/boot_sect_main.bin boot_sect_main.asm
	cd ./bin/
	qemu-system-i386 -fda boot_sect_main.bin



clean:
	rm *.bin