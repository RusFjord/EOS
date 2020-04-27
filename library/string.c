#include "string.h"
#include "constants.h"
#include "screen.h"

void print_string(uint8 row, uint8 col, const char* str) {

	uint8* video_memory = (uint8*)VIDEO_MEMORY_ADDRESS;
    uint32 i = (row * 80 + col) * 2;
    uint32 j = 0;
    while(str[j] != '\0') {
		video_memory[i] = str[j];
		video_memory[i+1] = BACKGROUND_COLOR_DEFALT;
		++j;
		i += 2;
	}

	set_cursor(row, col + j);
}