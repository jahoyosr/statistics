/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.h
 * @brief File containing the declaration of data manipulation functions. 
 *
 * Contains the declaration of two functions for converting an integer to a string and vice versa.
 *
 * @author Julian Hoyos
 * @date 16/04/2023
 *
 */
#ifndef __DATA_H__
#define __DATA_H__


/**
 *   @brief Converts an integer to an ASCII string in the given base.
 *   This function takes in three input arguments: the integer data to be converted, a pointer to an
 *   array of unsigned char to store the converted ASCII string, and the base to be used for conversion..
 *
 *   @param data Integer value to be converted to ASCII string.
 *   @param ptr Pointer to an array of unsigned char to store the resulting ASCII string.
 *   @param base Base to be used for conversion (e.g. 10 for decimal, 16 for hexadecimal).
 *
 *   @return Number of digits in the resulting ASCII string.
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 *   @brief Function to convert a string of ASCII characters to an integer value.
 *   This function takes in three input arguments: a pointer to a string of ASCII characters, the
 *   number of digits in the string, and the base of the number system used in the string. The function
 *   then iterates through the string to convert it to an integer value using the provided base. 
 *
 *   @param ptr Pointer to the string of ASCII characters.
 *   @param digits Number of digits in the string.
 *   @param base Base of the number system used in the string.
 *
 *   @return int32_t The integer value obtained from the string after the conversion.
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
#endif /* __DATA_H__ */
