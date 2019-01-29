section .multiboot_header
header_start:
    dd 0xe85250d6                ; магическое число (multiboot 2)
    dd 0                         ; архитектура 0 (защищённый режим i386)
    dd header_end - header_start ; длина заголовка
    ; контрольная сумма
    dd 0x100000000 - (0xe85250d6 + 0 + (header_end - header_start))

    ; вставьте опциональные `multiboot` тэги здесь

    ; требуется завершающий тэг
    dw 0    ; тип
    dw 0    ; флаги
    dd 8    ; размер
header_end:
section .text
bits 32	
global start
extern kmain	        ;kmain is defined in the c file

start:
  cli 			;block interrupts
  mov esp, stack_space	;set stack pointer
  call kmain
  hlt		 	;halt the CPU

section .bss
resb 8192		;8KB for stack
stack_space: