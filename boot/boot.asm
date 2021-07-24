section .multiboot_header
header_start:
    dd 0xE85250D6                ; магическое число (multiboot 2)
    dd 0                         ; архитектура 0 (защищённый режим i386)
    dd header_end - header_start ; длина заголовка
    ; контрольная сумма
    dd 0x100000000 - (0xE85250D6 + 0 + (header_end - header_start))

    ; завершающий тэг
    dw 0    ; тип
    dw 0    ; флаги
    dd 8    ; размер
header_end:
section .text
bits 32	
global start
extern kmain	        ; kmain определена в файле Си

start:
  cli 			; блокировка исключений
  mov esp, stack_space	; указатель на стек
  call kmain ;Вызов функции
  hlt		 	; остановка процессора

section .bss
resb 8192		; 8 Кб для стека 
stack_space: