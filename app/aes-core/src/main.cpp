/**
 * NOTE: This file is based on the open implementation made by Brad Conte
 * https://github.com/B-Con/crypto-algorithms
 */

/* Headers*/
// #include <avr/signature.h>
#include <stdio.h>
// #include <string.h>
#include "aes.h"
#include <print.h>
#include <Arduino.h>

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

	//printf("* CBC mode:\n");
	aes_key_setup(key[0], key_schedule, 128);

	Serial.println("\nKey          : ");
	print_hex(key[0], 16);
	Serial.println("\nIV           : ");
	print_hex(iv[0], 16);

	aes_encrypt_cbc(plaintext[0], 16, enc_buf, key_schedule, 128, iv[0]);
	Serial.println("\n\nPlaintext    : ");
	print_hex(plaintext[0], 16);
	Serial.println("\n-encrypted to: ");
	print_hex(enc_buf, 16);

	memcpy(dec_buf, enc_buf, 16);
	aes_decrypt_cbc(enc_buf, 16, dec_buf, key_schedule, 128, iv[0]);
	Serial.println("\n\nCiphertext   : ");
	print_hex(enc_buf, 16);
	Serial.println("\n-decrypted to: ");
	print_hex(dec_buf, 16);
	Serial.println("\nPlaintext   : ");
	print_hex(plaintext[0], 16);
	pass = pass && !memcmp(dec_buf, plaintext[0], 16);

	//printf("\n\n");
	return(pass);
}

// int cbc_256()
// {
// 	WORD key_schedule[60];
// 	BYTE enc_buf[32];
// 	BYTE plaintext[1][32] = {
// 		{0x6b,0xc1,0xbe,0xe2,0x2e,0x40,0x9f,0x96,0xe9,0x3d,0x7e,0x11,0x73,0x93,0x17,0x2a,0xae,0x2d,0x8a,0x57,0x1e,0x03,0xac,0x9c,0x9e,0xb7,0x6f,0xac,0x45,0xaf,0x8e,0x51}
// 	};
// 	BYTE ciphertext[1][32] = {
// 		{0xf5,0x8c,0x4c,0x04,0xd6,0xe5,0xf1,0xba,0x77,0x9e,0xab,0xfb,0x5f,0x7b,0xfb,0xd6,0x9c,0xfc,0x4e,0x96,0x7e,0xdb,0x80,0x8d,0x67,0x9f,0x77,0x7b,0xc6,0x70,0x2c,0x7d}
// 	};
// 	BYTE iv[1][16] = {
// 		{0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f}
// 	};
// 	BYTE key[1][32] = {
// 		{0x60,0x3d,0xeb,0x10,0x15,0xca,0x71,0xbe,0x2b,0x73,0xae,0xf0,0x85,0x7d,0x77,0x81,0x1f,0x35,0x2c,0x07,0x3b,0x61,0x08,0xd7,0x2d,0x98,0x10,0xa3,0x09,0x14,0xdf,0xf4}
// 	};
// 	int pass = 1;

// 	//printf("* CBC mode:\n");
// 	aes_key_setup(key[0], key_schedule, 256);

// 	print("\nKey          : ");
// 	print_hex(key[0], 32);
// 	print("\nIV           : ");
// 	print_hex(iv[0], 16);

// 	aes_encrypt_cbc(plaintext[0], 32, enc_buf, key_schedule, 256, iv[0]);
// 	print("\n\nEncrypting...\n");
// 	print("\nPlaintext    : ");
// 	print_hex(plaintext[0], 32);
// 	print("\n-encrypted to: ");
// 	print_hex(enc_buf, 32);
// 	print("\nCiphertext   : ");
// 	print_hex(ciphertext[0], 32);
// 	pass = pass && !memcmp(enc_buf, ciphertext[0], 32);

// 	aes_decrypt_cbc(ciphertext[0], 32, enc_buf, key_schedule, 256, iv[0]);
// 	print("\n\nDecrypting...\n");
// 	print("\nCiphertext   : ");
// 	print_hex(ciphertext[0], 32);
// 	print("\n-decrypted to: ");
// 	print_hex(enc_buf, 32);
// 	print("\nPlaintext   : ");
// 	print_hex(plaintext[0], 32);
// 	pass = pass && !memcmp(enc_buf, plaintext[0], 32);

// 	//printf("\n\n");
// 	return(pass);
// }

void setup(){
	Serial.begin(115200);
}

// int main(int argc, char *argv[])
void loop()
{
	char *passStr;

	// BYTE plaintext[1][16];
	// read16(plaintext);
	BYTE plaintext[1][16] = {
		{0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a}};

	passStr = cbc_128(plaintext) ? "\nSUCCEEDED\n\n" : "\nFAILED\n\n";
	Serial.println(passStr);
}