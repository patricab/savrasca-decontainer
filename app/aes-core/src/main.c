/**
 * NOTE: This file is based on the open implementation made by Brad Conte
 * https://github.com/B-Con/crypto-algorithms
 */

/* Headers*/
#include <stdio.h>
// #include <string.h>
#include "aes.h"
#include "print.h"
#include <xc.h>

#define F_CPU 20000000UL
#include <util/delay.h>


/* Functions */
int cbc_128(BYTE plaintext[1][16])
{
	WORD key_schedule[60];
	BYTE enc_buf[16];
	BYTE dec_buf[16];

	BYTE ciphertext[1][16] = {
		{0x76, 0x49, 0xab, 0xac, 0x81, 0x19, 0xb2, 0x46, 0xce, 0xe9, 0x8e, 0x9b, 0x12, 0xe9, 0x19, 0x7d}
	};
	BYTE iv[1][16] = {
		{0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f}
	};
	BYTE key[1][16] = {
		{0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c}
	};
	int pass = 1;

	aes_key_setup(key[0], key_schedule, 128);

	aes_encrypt_cbc(plaintext[0], 16, enc_buf, key_schedule, 128, iv[0]);
	// printf("\n\nPlaintext    : ");
	// print_hex(plaintext[0], 16);
	// printf("\n-encrypted to: ");
	// print_hex(enc_buf, 16);

	memcpy(dec_buf, enc_buf, 16);
	aes_decrypt_cbc(enc_buf, 16, dec_buf, key_schedule, 128, iv[0]);
	// printf("\n\nCiphertext   : ");
	// print_hex(enc_buf, 16);
	// printf("\n-decrypted to: ");
	// print_hex(dec_buf, 16);
	// printf("\nPlaintext   : ");
	// print_hex(plaintext[0], 16);
	pass = pass && !memcmp(dec_buf, plaintext[0], 16);
	if (pass) {
		print_hex(enc_buf, 16);
	}

	return(pass);
}


int main(int argc, char *argv[])
{
    SYSTEM_Initialize();
	USART3_Enable();
	char *passStr;

	// BYTE plaintext[1][16];
	// read16(plaintext);
	// BYTE plaintext[1][16] = {
	// 	{0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a}};
		// 6bc1bee22e409f96e93d7e117393172a

	BYTE plaintext[1][16] = {0};
    // unsigned char c;
    while (1) {
		get_input(plaintext);
        passStr = cbc_128(plaintext) ? "\nSUCCEEDED\n\n" : "\nFAILED\n\n";
        // printf(passStr);
        // _delay_ms(1000);
    }
	
    return 0;
}