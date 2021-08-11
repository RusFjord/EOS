#include "gdt.h"
#include "../include/constants.h"

extern void gdt_flush(u32int);

gdt_entry_t gdt_entries[NUM_GDT_ENTRIES];
gdt_ptr_t   gdt_ptr;

void set_gdt_entry(uint32 num, uint32 base, uint32 limit, uint8 access, uint8 gran) {
    gdt_entries[num].base_low    = (base & 0xFFFF);
    gdt_entries[num].base_middle = (base >> 16) & 0xFF;
    gdt_entries[num].base_high   = (base >> 24) & 0xFF;

    gdt_entries[num].limit_low   = (limit & 0xFFFF);
    gdt_entries[num].granularity = (limit >> 16) & 0x0F;

    gdt_entries[num].granularity |= gran & 0xF0;
    gdt_entries[num].access      = access;
}

void init_gdt() {
    gdt_ptr.limit = (sizeof(gdt_entry_t) * NUM_GDT_ENTRIES) - 1;
    gdt_ptr.base  = (uint32)&gdt_entries;

    set_gdt_entry(0, 0, 0, 0, 0);                // Нулевой сегмент, обязателен в архитектуре x86
    set_gdt_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Сегмент кода ядра 
    set_gdt_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Сегмент данных ядра
    set_gdt_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // Сегмент кода пользовательского режима
    set_gdt_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // Сегмент данных пользовательского режима

    gdt_flush((uint32)&gdt_ptr);

}