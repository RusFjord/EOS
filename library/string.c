#include "string.h"

void print_string(char* vidptr, char row, char col, char* str) {
    unsigned int i = 0;
    unsigned int j = 0;
    while(str[j] != '\0') {
		vidptr[i] = str[j];
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}

}