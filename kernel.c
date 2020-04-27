/*
*  kernel.c
*/
#include "library/string.h"
#include "library/screen.h"

void kmain(void)
{
	const char *str = "Simple OS, version 0.0.1";

	screen_init();

	/* Вывод наименования ОС и версии ядра */
	print_string(0, 0, str);	
	
	return;
}