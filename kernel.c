/*
*  kernel.c
*/
#include "library/string.h"
#include "library/ports.h"

void kmain(void)
{
	const char *str = "Simple OS, version 0.0.1";

	/* Очистка экрана */
	clear_screen();

	/* Вывод наименования ОС и версии ядра */
	print_string(0, 0, str);
	
	unsigned char cursor_start = 14;
	unsigned char cursor_end = 15;

	port_byte_out(0x3D4, 0x0A);
	port_byte_out(0x3D5, (port_byte_in(0x3D5) & 0xC0) | cursor_start);
	port_byte_out(0x3D4, 0x0B);
	port_byte_out(0x3D5, (port_byte_in(0x3D5) & 0xE0) | cursor_end);
	
	
	return;
}