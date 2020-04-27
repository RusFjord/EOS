/**
 * @file string.h
 * @author Федор Ендовицкий (f.endovitskiy@ulteam8.ru)
 * @brief Работа со строками
 * @version 0.1
 * @date 27-04-2020
 * 
 */
#ifndef STRING_H
#define STRING_H

#include "types.h"

/**
* @brief Вывод текста с началом в определенной строке и колонке
* @param col колонка экрана начала вывода строки
* @param row строка экрана начала вывода текста 
* @param str указатель на си-подобную строку
*/
extern void print_string(uint8 col, uint8 row, const char *str);

#endif // STRING_H