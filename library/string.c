/*
*  string.c
*/
#include "string.h"
#include "constants.h"

char* video_memory = (char*)VIDEO_MEMORY_ADDRESS;

void print_string(char row, char col, char* str) {

    unsigned int i = (row * 80 + col) * 2;
    unsigned int j = 0;
    while(str[j] != '\0') {
		video_memory[i] = str[j];
		video_memory[i+1] = BACKGROUND_COLOR_DEFALT;
		++j;
		i = i + 2;
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