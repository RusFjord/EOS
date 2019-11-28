/*
*  kernel.c
*/

#include "library/string.h";

char *vidptr = (char*)0xB8000;

void kmain(void)
{
	const char *str = "Simple OS, version 0.0.1";
	//char *vidptr = (char*)0xb8000; 	// Помещаем в указатель адрес на первый байт видеопамяти
	unsigned int i = 0;
	unsigned int j = 0;

	/* Очистка экрана */
	while(j < 80 * 25 * 2) {
		vidptr[j] = ' ';
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}

	j = 0;

	/* Вывод наименования ОС и версии ядра */
	print_string(vidptr, 0, 0, str);
	
	return;
}