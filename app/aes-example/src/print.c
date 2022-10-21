#include "aes.h"
#include "print.h"

#define outport (*( (volatile char *)0x20))
#define inpport  (*( (volatile char *)0x22))

void print_hexbyte(unsigned char byte)
{
	// outport = '0';
	// outport = 'x';
	if((byte >>4)<10 ){
		outport = (byte>>4)+'0';
	}else{
		outport = (byte>>4)-10+'A';
	}
	
	if((byte & 0xF)<10 ){
		outport = (byte& 0xF)+'0';
	}else{
		outport = (byte& 0xF)-10+'A';
	}
}

void print(const char *str)
{
  const char *c;

  for (c=str ; *c ; c++)
    outport = *c;
}

void print_hex(BYTE str[], int len)
{
	int idx;

	for(idx = 0; idx < len; idx++)
		print_hexbyte(str[idx]);
}