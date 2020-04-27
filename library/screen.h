/**
* @brief Функции для работы с экраном в текстовом режиме
*/

#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"

/** @fn screen_init
* @brief Инициализация экрана
*/
extern void screen_init();

/** @fn clear_screen
* @brief Очистка экрана
*/
extern void clear_screen();

/** @fn set_cursor
* @brief Установка курсора
* @param row Колонка курсора
* @param col Строка курсора
*/
extern void set_cursor(uint8 row, uint8 col);

#endif // SCREEN_H
