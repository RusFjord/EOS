#include "gdt.h"
#include "../include/types.h"

#define GDT_ENTRIES 3

/* Дескриптор сегмента: формат задан процессором, ровно 8 байт */
struct gdt_entry {
	uint16 limit_low;	/* лимит, биты 0..15 */
	uint16 base_low;	/* база, биты 0..15 */
	uint8  base_middle;	/* база, биты 16..23 */
	uint8  access;		/* P, DPL, S, тип */
	uint8  granularity;	/* флаги (старшие 4 бита) и лимит, биты 16..19 */
	uint8  base_high;	/* база, биты 24..31 */
} __attribute__((packed));

/* Операнд инструкции lgdt: 6 байт */
struct gdt_ptr {
	uint16 limit;	/* размер таблицы минус 1 */
	uint32 base;	/* линейный адрес таблицы */
} __attribute__((packed));

_Static_assert(sizeof(struct gdt_entry) == 8, "gdt_entry must be 8 bytes");
_Static_assert(sizeof(struct gdt_ptr) == 6, "gdt_ptr must be 6 bytes");

static struct gdt_entry gdt[GDT_ENTRIES];
static struct gdt_ptr gdt_pointer;

static void gdt_set_entry(uint8 index, uint32 base, uint32 limit, uint8 access, uint8 flags) {

	gdt[index].limit_low   = limit & 0xFFFF;
	gdt[index].base_low    = base & 0xFFFF;
	gdt[index].base_middle = (base >> 16) & 0xFF;
	gdt[index].access      = access;
	gdt[index].granularity = ((flags & 0x0F) << 4) | ((limit >> 16) & 0x0F);
	gdt[index].base_high   = (base >> 24) & 0xFF;
}

void gdt_init() {

	/* Плоская модель: база 0, лимит 4 Гб (0xFFFFF страниц по 4 Кб), 32 бита */
	gdt_set_entry(0, 0, 0, 0, 0);			/* нулевой дескриптор (обязателен) */
	gdt_set_entry(1, 0, 0xFFFFF, 0x9A, 0xC);	/* код ядра */
	gdt_set_entry(2, 0, 0xFFFFF, 0x92, 0xC);	/* данные ядра */

	gdt_pointer.limit = sizeof(gdt) - 1;
	gdt_pointer.base  = (uint32)gdt;

	/* CS нельзя изменить через mov, только дальним прыжком */
	__asm__ volatile (
		"lgdt %0\n"
		"movw %%ax, %%ds\n"
		"movw %%ax, %%es\n"
		"movw %%ax, %%fs\n"
		"movw %%ax, %%gs\n"
		"movw %%ax, %%ss\n"
		"ljmp $0x08, $1f\n"	/* 0x08 = KERNEL_CODE_SELECTOR */
		"1:\n"
		: : "m" (gdt_pointer), "a" (KERNEL_DATA_SELECTOR)
	);
}
