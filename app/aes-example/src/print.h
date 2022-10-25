#ifndef PRINT_H
#define PRINT_H

#define outport (*( (volatile char *)0x20))
#define inport  (*( (volatile char *)0x22))

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
 * @brief Print string to output
 * 
 * @param str String
 */
void print(const char *str);

#endif