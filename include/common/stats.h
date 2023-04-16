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
 * @file stats.h
 * @brief File containing the declaration of the statistics function for an array of unsigned char.
 *
 * The functions declared in this file may include common statistical operations such as calculating 
 * the maximum, minimum, mean, and median of the array. The declaration of each function specifies its 
 * name, argument list, and return type.
 *
 * @author Julian Hoyos
 * @date 26/03/2023
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


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
void print_statistics(unsigned char* array_pointer, unsigned int array_size);


/**
 * @brief Function to print an array of unsigned char.
 *
 * This function takes in two input arguments: a pointer to an array of unsigned char values and the 
 * size of the array. The function prints the data array to the console. 
 *
 * @param array_pointer Pointer to the array of unsigned char values.
 * @param array_size    Size of the array.
 *
 * @return void.
 */
void print_array(unsigned char* array_pointer, unsigned int array_size);

/**
 * @brief Function to calculate the median value of an array of unsigned char values.
 *
 * This function takes in two input arguments: a pointer to an array of unsigned char values and the 
 * size of the array and returns the calculated median value as a single numerical value.
 *
 * @param array_pointer Pointer to the array of unsigned char values.
 * @param array_size    Size of the array.
 *
 * @return Median value of the input array.
 */
unsigned char find_median(unsigned char* array_pointer, unsigned int array_size);

/**
 * @brief Function to calculate the mean value of an array of unsigned char values.
 *
 * This function takes in two input arguments: a pointer to an array of unsigned char values and the 
 * size of the array and returns the calculated mean value as a single numerical value.
 *
 * @param array_pointer Pointer to the array of unsigned char values.
 * @param array_size    Size of the array.
 *
 * @return Mean value of the input array.
 */
unsigned char find_mean(unsigned char* array_pointer, unsigned int array_size);

/**
 * @brief Function to find the maximum value of an array of unsigned char values.
 *
 * This function takes in two input arguments: a pointer to an array of unsigned char values and the 
 * size of the array and returns the maximum value as a single numerical value.
 *
 * @param array_pointer Pointer to the array of unsigned char values.
 * @param array_size    Size of the array.
 *
 * @return Maximum value of the input array.
 */
unsigned char find_maximum(unsigned char* array_pointer, unsigned int array_size);

/**
 * @brief Function to find the minimum value of an array of unsigned char values.
 *
 * This function takes in two input arguments: a pointer to an array of unsigned char values and the 
 * size of the array and returns the minimum value as a single numerical value.
 *
 * @param array_pointer Pointer to the array of unsigned char values.
 * @param array_size    Size of the array.
 *
 * @return Minimum value of the input array.
 */
unsigned char find_minimum(unsigned char* array_pointer, unsigned int array_size);

/**
 * @brief Function to sort an array from the largest to the smallest value.
 *
 * This function takes in two input arguments: a pointer to an array of unsigned char values and the 
 * size of the array. The function then iterates through the array to sort the elements in descending
 * order.
 *
 * @param array_pointer Pointer to the array of unsigned char values.
 * @param array_size    Size of the array.
 *
 * @return void.
 */
void sort_array(unsigned char* array_pointer, unsigned int array_size);

#endif /* __STATS_H__ */
