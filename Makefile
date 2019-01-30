BUILD_DIR=./build
CC=/usr/bin/gcc
CC_FLAGS=-m32 -c
ASM=/usr/bin/nasm
ASM_FLAGS=-f elf32
LD=/usr/bin/ld
MKDIR=mkdir -p
RM=rm -f -r

project_structure:
	${MKDIR} ${BUILD_DIR}
boot: project_structure boot.asm
	${ASM} ${ASM_FLAGS} boot.asm -o ${BUILD_DIR}/boot.o
kernel: project_structure kernel.c
	${CC} ${CC_FLAGS} kernel.c -o ${BUILD_DIR}/kernel.o
link: boot kernel link.ld
	${LD} -m elf_i386 -T link.ld -o ${BUILD_DIR}/kernel.bin ${BUILD_DIR}/boot.o ${BUILD_DIR}/kernel.o
iso: link
	${MKDIR} ${BUILD_DIR}/isofiles/boot/grub
	cp grub.cfg ${BUILD_DIR}/isofiles/boot/grub
	cp ${BUILD_DIR}/kernel.bin ${BUILD_DIR}/isofiles/boot
	grub-mkrescue -o ${BUILD_DIR}/simpleos.iso ${BUILD_DIR}/isofiles
qemu: iso
	qemu-system-i386 build/simpleos.iso
qemu_cd: iso
	qemu-system-i386 -cdrom build/simpleos.iso
clean:
	${RM} ${BUILD_DIR}/*