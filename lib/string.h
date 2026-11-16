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

#include "../include/types.h"

/**
* @brief Вывод текста с началом в определенной строке и колонке
* @param row строка экрана начала вывода текста
* @param col колонка экрана начала вывода строки
* @param str указатель на си-подобную строку
*/
extern void print_string(uint8 row, uint8 col, const char *str);

#endif // STRING_H