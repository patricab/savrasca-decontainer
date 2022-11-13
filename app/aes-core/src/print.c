#include "print.h"
#include <xc.h>
// #include <usart3.h>

void putch(char data) {
    USART3_Write(data);
}

void print_hexbyte(unsigned char byte)
{
	if((byte >> 4) < 10){
		// printf("Test1\n");
		printf("%c", (byte>>4)+'0');
	}else{
		// printf("Test2\n");
		printf("%c", (byte>>4)-10+'A');
	}
	
	if((byte & 0xF)<10 ){
		// printf("Test3\n");
		printf("%c", (byte& 0xF)+'0');
	}else{
		// printf("Test4\n");
		printf("%c", (byte& 0xF)-10+'A');
	}
}

void print_hex(BYTE str[], int len)
{
	for(int idx = 0; idx < len; idx++) {
		print_hexbyte(str[idx]);
        // printf("%02x", str[idx]);
	}
	printf("\n");
}
	
void get_input(BYTE input[1][16])
{
	uint8_t i = 0;
	unsigned char c;

	while (1) {
		c = USART3_Read();
		input[0][i] = c; // Append to input array
		i++;

		/* Reset index */
		if (i >= 16) {
			i = 0;
            // print_hex(input, 16);
			break;
		}
	}
}