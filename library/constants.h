#ifndef CONSTANTS_H
#define CONSTANTS_H

/**
 * @brief Адрес видеопамяти
 */
#define VIDEO_MEMORY_ADDRESS 0xB8000 

/**
 * @brief Символ пробела
 */
#define SPACE_CHAR ' '

/**
 * @brief Аттрибуты цвета для символа по умолчанию
 */
#define BACKGROUND_COLOR_DEFALT 0x07 

/**
 * @brief Максимальное количество строк в текстовом режиме
 */
#define MAX_ROWS 25

/**
 * @brief Максимальное количество колонок в текстовом режиме
 */
#define MAX_COLS 80

/**
 * @brief Порты ввода/вывода экрана
 */
#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

#endif