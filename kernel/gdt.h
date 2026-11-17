/**
 * @file gdt.h
 * @brief Глобальная таблица дескрипторов (GDT)
 */
#ifndef GDT_H
#define GDT_H

/**
 * @brief Селектор сегмента кода ядра (запись 1 GDT, кольцо 0)
 */
#define KERNEL_CODE_SELECTOR 0x08

/**
 * @brief Селектор сегмента данных ядра (запись 2 GDT, кольцо 0)
 */
#define KERNEL_DATA_SELECTOR 0x10

/** @fn gdt_init()
* @brief Заполнение и загрузка плоской GDT ядра вместо таблицы загрузчика
*/
extern void gdt_init();

#endif // GDT_H
