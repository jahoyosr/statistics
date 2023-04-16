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
 * @file stats.c 
 * @brief File containing the defintion of statistics functions for an unsigned char array. 
 *
 * Contains the implementation of several statistics functions for unsigned char arrays, 
 * including the median, mean, maximum, and minimum. Additionally, there is a utility function 
 * provided to sort the array in descending order.
 *
 * @author Julian Hoyos
 * @date 27/03/2023
 *
 */

#include <stdio.h>
#include <string.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/* Function definition*/
void print_statistics(unsigned char* array_pointer, unsigned int array_size)
{
  unsigned char median;
  unsigned char mean;
  unsigned char maximum;
  unsigned char minimum;

  median = find_median(array_pointer, array_size);
  mean = find_mean(array_pointer, array_size);
  maximum = find_maximum(array_pointer, array_size);
  minimum = find_minimum(array_pointer, array_size);

  printf("Median: %d  - Mean: %d  - Maximum: %d - Minimum: %d \n", median, mean, maximum, minimum);

}

void print_array(unsigned char* array_pointer, unsigned int array_size)
{
  unsigned char i;
  for(i = 0; i < array_size ; ++i)
  {
    printf("%dth element: %d\n", i, *(array_pointer+i));
  }
}

unsigned char find_median(unsigned char* array_pointer, unsigned int array_size)
{
  unsigned char median;
  unsigned char mid_element;
  unsigned char sorted_array[array_size];
  unsigned char* sorted_array_pointer = sorted_array;

  /* Copy array */
  memcpy(sorted_array_pointer, array_pointer, array_size * sizeof(unsigned char));
  sort_array(sorted_array_pointer, array_size);
  mid_element = array_size/2;
 
  if(0 != array_size % 2 )
  {
    median = *(sorted_array_pointer+mid_element);
  }
  else
  {
    median = (*(sorted_array_pointer+mid_element) + *(sorted_array_pointer+mid_element-1))/2;
  }

  return median;
}

unsigned char find_mean(unsigned char* array_pointer, unsigned int array_size)
{
  unsigned int sum_value = 0;
  unsigned char mean = 0;
  unsigned char i;

  for(i = 0; i < array_size ; ++i)
  {
    sum_value += *(array_pointer+i);
  }

  mean = (unsigned char)(sum_value/array_size);

  return mean;
}

unsigned char find_maximum(unsigned char* array_pointer, unsigned int array_size)
{
  unsigned char maximum = 0;
  unsigned char i;

  for(i = 0; i < array_size ; ++i)
  {
    maximum = maximum < *(array_pointer+i) ? *(array_pointer+i) : maximum;
  }

  return maximum;
}

unsigned char find_minimum(unsigned char* array_pointer, unsigned int array_size)
{
  unsigned char minimum = 255;
  unsigned char i;

  for(i = 0; i < array_size ; ++i)
  {
    minimum = minimum > *(array_pointer+i) ? *(array_pointer+i) : minimum;
  }

  return minimum;
}

void sort_array(unsigned char* array_pointer, unsigned int array_size)
{
  unsigned char i;
  unsigned char j;
  unsigned char current_value;
  unsigned char max_value;
  unsigned char max_index;
  

  for(i = 0; i < array_size ; ++i)
  {
    current_value = *(array_pointer+i);
    max_value = current_value;

    for(j = i; j < array_size ; ++j)
    {
      if( max_value < *(array_pointer+j))
      {
        max_value = *(array_pointer+j);
        max_index = j;
      }
    }

    if(max_value != current_value)
    {
      *(array_pointer+i) = max_value;
      *(array_pointer+max_index) = current_value;
    }
  }

}

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};


  print_statistics(test, SIZE);
  sort_array(test, SIZE);
  print_array(test,SIZE);

}

