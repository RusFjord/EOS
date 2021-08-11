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
global gdt_flush
extern kmain	        ; kmain определена в файле Си

start:
  cli 			; блокировка исключений
  mov esp, stack_space	; указатель на стек
  call kmain ;Вызов функции
  hlt		 	; остановка процессора

gdt_flush:
    mov eax, [esp + 4]
    lgdt [eax]        ; Загружает новый указатель GDT

    mov ax, 0x10      ; 0x10 является смещением, находящимся в таблице GDT и указываемым на наш сегмент данных
    mov ds, ax        ; Загрузка переключателей всех сегментов данных
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:.flush   ; 0x08 является смещением на наш сегмент кода: Длинный переход!
.flush:
    ret

section .bss
resb 8192		; 8 Кб для стека 
stack_space: