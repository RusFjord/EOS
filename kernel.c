/*
*  kernel.c
*/
void kmain(void)
{
	const char *str = "Simple OS, version 0.0.1";
	char *vidptr = (char*)0xb8000; 	// Помещаем в указатель адрес на первый байт видеопамяти
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
	while(str[j] != '\0') {
		vidptr[i] = str[j];
		/* Указатель на строку увеличиваем на 1, а указатель видеопамяти
    		на 2 байта (символ + аттрибут цвета) */
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
	return;
}