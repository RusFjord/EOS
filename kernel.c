/*
*  kernel.c
*/
#include "library/string.h"

void kmain(void)
{
	const char *str = "Simple OS, version 0.0.1";

	/* Очистка экрана */
	clear_screen();

	/* Вывод наименования ОС и версии ядра */
	print_string(0, 0, str);
	
	return;
}