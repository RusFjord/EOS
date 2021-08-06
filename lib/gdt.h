/**
 * @file gdt.h
 * @author Федор Ендовицкий (f.endovitskiy@ulteam8.ru)
 * @brief Определение структуры данных глобальной таблицы дескрипторов, а также определение функций для работы с ней
 * @version 0.1
 * @date 05-08-2021
 * 
 */
#ifndef GDT_H
#define GDT_H

#include "../include/types.h"

/** @struct gdt_entry_t
* @brief Структура данных для одной записи в таблицу дескрипторов
* @property
* @property
* @property
* @property
* @property
* @property
*/
struct gdt_entry
{
   uint16 limit_low;           // Младшие 16 битов граничного значения limit.
   uint16 base_low;            // Младшие 16 битов адресной базы.
   uint8  base_middle;         // Следующие 8 битов адресной базы.
   uint8  access;              // Флаги доступа, определяющие в каком кольце можно использовать этот сегмент.
   uint8  granularity;
   uint8  base_high;           // Последние 8 битов адресной базы.
} __attribute__((packed));
typedef struct gdt_entry gdt_entry_t;

/** @struct gdt_ptr_t
* @brief Структура данных, содержащая ссылку на таблицу дескрипторов 
* @property base - Адрес начала таблицы дескрипторов
* @property limit - Верхние 16 битов всех предельных значений селектора 
*/
struct gdt_ptr {
   uint32 base;
   uint16 limit; 
} __attribute__((packed));
typedef struct gdt_ptr gdt_ptr_t; 

/** @fn init_gdt()
* @brief Первоначальная инициализация глобальной таблицы дескрипторов
*/
void init_gdt();

#endif // GDT_H