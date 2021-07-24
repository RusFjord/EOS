#include "ports.h"
#include "../include/types.h"

uint8 inb (uint16 port) {

    uint8 result;

    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}
void outb (uint16 port, uint8 data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

uint16 inw (uint16 port) {
    uint16 result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

void outw (uint16 port, uint16 data) {
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}