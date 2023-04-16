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
 * @file data.c 
 * @brief File containing the defintion of statistics functions for an unsigned char array. 
 *
 * Contains the implementation of several statistics functions for unsigned char arrays, 
 * including the median, mean, maximum, and minimum. Additionally, there is a utility function 
 * provided to sort the array in descending order.
 *
 * @author Julian Hoyos
 * @date 16/04/2023
 *
 */


#include "data.h"

/* Size of the Data Set */
#define SIZE (40)

/* Function definition*/
