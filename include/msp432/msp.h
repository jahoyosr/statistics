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
 * @file msp.h
 * @brief File containing the declaration of the statistics function for an array of unsigned char.
 *
 * The functions declared in this file may include common statistical operations such as calculating 
 * the maximum, minimum, mean, and median of the array. The declaration of each function specifies its 
 * name, argument list, and return type.
 *
 * @author Julian Hoyos
 * @date 16/04/2023
 *
 */
#ifndef __MSP_H__
#define __MSP_H__


/**
 * @brief Function to print the statistics of an array including maximum, minimum, mean and median.
 *
 * This function takes in two input arguments: a pointer to an array of unsigned char values and the 
 * size of the array. The function then iterates through the array to determine maximum, minimum, media, 
 * and median values. Once all the statistical properties have been calculated, the function prints them 
 * to the console. 
 *
 * @param array_pointer Pointer to the array of unsigned char values.
 * @param array_size    Size of the array.
 *
 * @return void.
 */
//void print_statistics(unsigned char* array_pointer, unsigned int array_size);

#endif /* __MSP_H__ */
