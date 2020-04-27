#include "screen.h"
#include "ports.h"
#include "constants.h"
#include "types.h"

void screen_init() {

    clear_screen();
	init_cursor(14, 15);
    set_cursor(0, 0);
}

void clear_screen() {

    uint8* video_memory = (uint8*)VIDEO_MEMORY_ADDRESS;
	uint16 i = 0;
	while(i < MAX_COLS * MAX_ROWS * 2) {
		video_memory[i] = SPACE_CHAR;
		video_memory[i+1] = BACKGROUND_COLOR_DEFALT; 		
		i = i + 2;
	}
}

void init_cursor(uint8 cursor_start, uint8 cursor_end) {

	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3D5) & 0xE0) | cursor_end);
}

void set_cursor(uint8 row, uint8 col) {

	uint16 pos = row * MAX_COLS + col;

	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8) ((pos >> 8) & 0xFF));

}
