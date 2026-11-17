/*
*  kernel.c
*/
#include "../lib/string.h"
#include "../drivers/screen.h"
#include "gdt.h"

void kmain(void)
{
	const char *str = "EOS, version 0.0.1";

	gdt_init();
	screen_init();

	/* Вывод наименования ОС и версии ядра */
	print_string(0, 0, str);	
	
	return;
}