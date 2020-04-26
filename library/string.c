/*
*  string.c
*/
#include "string.h"
#include "constants.h"

uint8* video_memory = (uint8*)VIDEO_MEMORY_ADDRESS;

void print_string(uint8 row, uint8 col, char* str) {

    uint32 i = (row * 80 + col) * 2;
    uint32 j = 0;
    while(str[j] != '\0') {
		video_memory[i] = str[j];
		video_memory[i+1] = BACKGROUND_COLOR_DEFALT;
		++j;
		i += 2;
	}
}

void clear_screen() {

	unsigned int i = 0;
	while(i < 80 * 25 * 2) {
		video_memory[i] = SPACE_CHAR;
		video_memory[i+1] = BACKGROUND_COLOR_DEFALT; 		
		i = i + 2;
	}
}