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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick/Julian Hoyos
 * @date April 16 2023
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stddef.h>
/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Function to move a block of memory to another location.
 *
 * This function takes in three input arguments: a pointer to the source memory block, a pointer to the 
 * destination memory block and the length of the block to be moved. The function handle overlap of source 
 * and destination.
 *
 * @param src    Pointer to the source memory block.
 * @param dst    Pointer to the destination memory block.
 * @param length Length of the memory block to be moved.
 *
 * @return A pointer to the destination memory block.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Function to copy a block of memory from a source to a destination location.
 *
 * This function takes in three input arguments: a pointer to the source memory location, a pointer to the 
 * destination memory location, and the size of the block of memory to be copied. The function iterates through 
 * the block of memory and copies each byte from the source to the destination location. If doesn't handle 
 * overlap of source and destination.
 *
 * @param src    Pointer to the source memory location.
 * @param dst    Pointer to the destination memory location.
 * @param length Size of the block of memory to be copied.
 *
 * @return Pointer to the destination memory location if successful, otherwise NULL.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Function to set a specified value in the memory.
 *
 * This function sets the specified value in the memory block pointed by the source pointer. 
 * The function takes in three input arguments: a pointer to the source memory block, the size of 
 * the memory block, and the value to be set. The function iterates through the memory block and 
 * sets each byte to the specified value.
 *
 * @param src Pointer to the memory block to be set.
 * @param length Size of the memory block to be set.
 * @param value The value to be set in the memory block.
 *
 * @return A pointer to the memory block that has been set.
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);


/**
 * @brief Function to set all bytes of a memory block to zero.
 *
 * This function sets all bytes of a memory block to zero. The function takes in two input arguments: 
 * a pointer to the source memory block and the size of the memory block. The function then calls 
 * my_memset function with the value of 0 as the third argument to set all the bytes to zero.
 *
 * @param src Pointer to the memory block to be set to zero.
 * @param length Size of the memory block to be set to zero.
 *
 * @return A pointer to the memory block that has been set to zero.
 */
uint8_t * my_memzero(uint8_t * src, size_t length);


/**
 * @brief Function to reverse the order of bytes in a memory block.
 *
 * This function reverses the order of bytes in a memory block pointed by the source pointer. The 
 * function takes in two input arguments: a pointer to the source memory block and the size of the 
 * memory block. The function creates a temporary memory block, copies the original memory block in 
 * reverse order to the temporary block and then copies the temporary block back to the original block.
 *
 * @param src Pointer to the memory block to be reversed.
 * @param length Size of the memory block to be reversed.
 *
 * @return A pointer to the memory block that has been reversed.
 */
uint8_t * my_reverse(uint8_t * src, size_t length);


/**
 * @brief Function to allocate a memory block of specified size.
 *
 * This function allocates a memory block of the specified size in bytes. The function takes in 
 * one input argument: the size of the memory block to be allocated. The function allocates the 
 * memory block using the malloc function and returns a pointer to the first byte of the memory block.
 *
 * @param length Size of the memory block to be allocated.
 *
 * @return A pointer to the first byte of the allocated memory block.
 */
int32_t * reserve_words(size_t length);


/**
 * @brief Function to free the memory allocated by the reserve_words function.
 *
 * This function frees the memory block that was allocated using the reserve_words function. The 
 * function takes in one input argument: a pointer to the first byte of the memory block. The 
 * function frees the memory block using the free function.
 *
 * @param src Pointer to the first byte of the memory block to be freed.
 *
 * @return void.
 */
void free_words(int32_t * src);
#endif /* __MEMORY_H__ */
