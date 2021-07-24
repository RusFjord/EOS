/**
 * @file ports.h
 * @author Федор Ендовицкий (f.endovitskiy@ulteam8.ru)
 * @brief Работа с портами ввода/вывода
 * @version 0.1
 * @date 2020-04-27
 * 
 */
#ifndef PORTS_H
#define PORTS_H

#include "../include/types.h"

/**
 * @fn uint8 inb (uint16 port)
 * 
 * @brief Получения 8-битного значения из порта
 * 
 * @param port номер порта
 * @return (uint8) получаемое значение
 */
extern uint8 inb (uint16 port);
/**
 * @fn void outb (uint16 port, uint8 data)
 * @brief ФПередача 8-битного значения в порт
 * 
 * @param port номер порта
 * @param data передаваемое значение
 */
extern void outb (uint16 port, uint8 data);
/**
 * @fn uint16 inw (uint16 port)
 * @brief Получение 16-битного значения из порта
 * 
 * @param port номер порта
 * @return (uint16) получаемое значение
 */
extern uint16 inw (uint16 port);
/**
 * @fn void outw (uint16 port, uint16 data)
 * @brief Передача 16-битного значения в порт
 * 
 * @param port номер порта
 * @param data передаваемое значение
 */
extern void outw (uint16 port, uint16 data);

#endif // PORTS_H