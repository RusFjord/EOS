#ifndef STRING_H
#define STRING_H

#include "types.h"

/**
* @brief Вывод текста с началом в определенной строке и колонке
* @param col колонка экрана начала вывода строки
* @param row строка экрана начала вывода текста 
* @param str указатель на си-подобную строку
*/
extern void print_string(uint8 col, uint8 row, char *str);

/**
* @brief Очистка экрана
*/
extern void clear_screen();

#endif // STRING_H


