#ifndef PRINT_H
#define PRINT_H

#include "aes.h"

/**
 * @brief Print array of hex bytes to output
 * 
 * @param str Hex array
 * @param len Length of array
 */
void print_hex(BYTE str[], int len);

/**
 * @brief Print single hex byte to output
 * 
 * @param byte Hex byte
 */
void print_hexbyte(unsigned char byte);

/**
 * @brief Get hex array from USART input
 * 
 * @return byte Input hex array
 */
// BYTE *get_input(void);
// void get_input(BYTE input[1][16]);

void putch(char data);

#endif