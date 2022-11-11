#include "print.h"
#include <xc.h>
// #include <usart3.h>

void putch(char data) {
    USART3_Write(data);
}

void print_hexbyte(unsigned char byte)
{
	if((byte >>4)<10 ){
		printf((byte>>4)+'0');
	}else{
		printf((byte>>4)-10+'A');
	}
	
	if((byte & 0xF)<10 ){
		printf((byte& 0xF)+'0');
	}else{
		printf((byte& 0xF)-10+'A');
	}
}

void print_hex(BYTE str[], int len)
{
	for(int idx = 0; idx < len; idx++) {
		//print_hexbyte(str[idx]);
        printf("%02x", str[idx]);
	}
	printf("\n");
}
	
void get_input(BYTE input[1][16])
{
	uint8_t i = 0;

	unsigned char c;
	while (c != "\n" && c != "\r") {
		input[0][i++] = c; // Append to input array

		/* Reset index */
		if (i >= 16) {
			i = 0;
		}
	}

	return input;
}