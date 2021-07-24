/**
 * @file screen.h
 * @author Федор Ендовицкий (f.endovitskiy@ulteam8.ru)
 * @brief Работа с экраном в текстовом режиме
 * @version 0.1
 * @date 27-04-2020
 * 
 */
#ifndef SCREEN_H
#define SCREEN_H

#include "../include/types.h"

/** @fn screen_init()
* @brief Инициализация экрана
*/
extern void screen_init();

/** @fn clear_screen()
* @brief Очистка экрана
*/
extern void clear_screen();

/** @fn set_cursor(uint8 row, uint8 col)
* @brief Установка курсора
* @param row Колонка курсора
* @param col Строка курсора
*/
extern void set_cursor(uint8 row, uint8 col);

#endif // SCREEN_H