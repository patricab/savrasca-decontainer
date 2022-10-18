/**
 * NOTE: This file is based on the opn implementation
 * https://github.com/B-Con/crypto-algorithms
 */

/* Headers*/
#include <stdio.h>
#include <string.h>
#include "aes.h"

#define out (*( (volatile char *)0x20))
#define in (*( (volatile char *)0x22))

/* Functions */
// void print_hex(BYTE str[], int len)
// {
// 	int idx;

// 	for(idx = 0; idx < len; idx++)
// 		printf("%02x", str[idx]);
// }

int aes_cbc_test()
{
	WORD key_schedule[60];
	BYTE enc_buf[128];
	BYTE plaintext[1][32] = {
		{0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51}
	};
	BYTE ciphertext[1][32] = {
		{0xf5,0x8c,0x4c,0x04,0xd6,0xe5,0xf1,0xba,0x77,0x9e,0xab,0xfb,0x5f,0x7b,0xfb,0xd6,0x9c,0xfc,0x4e,0x96,0x7e,0xdb,0x80,0x8d,0x67,0x9f,0x77,0x7b,0xc6,0x70,0x2c,0x7d}
	};
	BYTE iv[1][16] = {
		{0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f}
	};
	BYTE key[1][32] = {
		{0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
	};
	int pass = 1;

	//printf("* CBC mode:\n");
	aes_key_setup(key[0], key_schedule, 256);

	//printf(  "Key          : ");
	//print_hex(key[0], 32);
	//printf("\nIV           : ");
	//print_hex(iv[0], 16);

	aes_encrypt_cbc(plaintext[0], 32, enc_buf, key_schedule, 256, iv[0]);
	//printf("\nPlaintext    : ");
	//print_hex(plaintext[0], 32);
	//printf("\n-encrypted to: ");
	//print_hex(enc_buf, 32);
	//printf("\nCiphertext   : ");
	//print_hex(ciphertext[0], 32);
	pass = pass && !memcmp(enc_buf, ciphertext[0], 32);

	aes_decrypt_cbc(ciphertext[0], 32, enc_buf, key_schedule, 256, iv[0]);
	//printf("\nCiphertext   : ");
	//print_hex(ciphertext[0], 32);
	//printf("\n-decrypted to: ");
	//print_hex(enc_buf, 32);
	//printf("\nPlaintext   : ");
	//print_hex(plaintext[0], 32);
	pass = pass && !memcmp(enc_buf, plaintext[0], 32);

	//printf("\n\n");
	return(pass);
}

int main(int argc, char *argv[])
{
	out = "Hello world";
	int pass = 1 && aes_cbc_test();
	// printf("AES Tests: %s\n", pass ? "SUCCEEDED" : "FAILED");
	char *passStr = pass ? "SUCCEEDED" : "FAILED";
	// printf("AES Tests: %s\n", pass ? "SUCCEEDED" : "FAILED");
	// out = passStr;

	return(0);
}