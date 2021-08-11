/*
*  kernel.c
*/
#include "../lib/string.h"
#include "../drivers/screen.h"
#include "../lib/gdt.h"

void kmain(void)
{
	const char *str = "EOS, version 0.0.1";
	const char *str_gdt_flush = "Set GDT";
	
	screen_init();

	/* Вывод наименования ОС и версии ядра */
	print_string(0, 0, str);
	init_gdt();
	print_string(1, 0, str_gdt_flush);	
	
	return;
}