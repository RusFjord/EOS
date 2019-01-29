BUILD_DIR=./build
CC=/usr/bin/gcc
CC_FLAGS=-m32 -c
ASM=/usr/bin/nasm
ASM_FLAGS=-f elf32
LD=/usr/bin/ld
MKDIR=mkdir -p
RM=rm -f

project_structure:
	${MKDIR} ${BUILD_DIR}
boot: project_structure boot.asm
	${ASM} ${ASM_FLAGS} boot.asm -o ${BUILD_DIR}/boot.o
kernel: project_structure kernel.c
	${CC} ${CC_FLAGS} kernel.c -o ${BUILD_DIR}/kernel.o
link: boot kernel link.ld
	${LD} -m elf_i386 -T link.ld -o ${BUILD_DIR}/kernel.bin ${BUILD_DIR}/boot.o ${BUILD_DIR}/kernel.o
clean:
	${RM} ${BUILD_DIR}/*