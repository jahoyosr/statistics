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
 * @brief File containing the defintion of data manipulation functions. 
 *
 * Contains the implementation of two functions for converting an integer to a string and vice versa.
 * The code also includes a helper function my_pow for computing the power of a number.
 *
 * @author Julian Hoyos
 * @date 16/04/2023
 *
 */

#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#include "data.h"
#include "memory.h"
#include "platform.h"

static int32_t my_pow( uint32_t a , uint32_t b );

static int32_t my_pow( uint32_t base , uint32_t exponent ) {  
    int32_t power = 1;
    uint32_t i ;  
    for ( i = 1 ; i <= exponent ; i++ ) {  
        power = power * base ;  
    }  
    return power ;  
} 

/* Function definition*/
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    uint32_t tmp = abs(data);
    uint8_t mod;
    uint8_t length = 1;
    uint8_t digits = 0;

    *(ptr)= '\0';

    while(tmp != 0){
        digits++;
        mod = tmp%base;
        if(mod <10){
            *(ptr+length++)= '0' + mod;
        }
        else{
            *(ptr+length++)= 'A' + (mod%10);
        }
        tmp=tmp/base;
    }

    /* If the value is negative */
    if(data < 0){
        *(ptr+length++)= '-';
    }

    ptr = my_reverse(ptr,length);   

    return digits;
    
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    int32_t conv_number = 0;
    int8_t sign, shift, i;

    if(*ptr == '-'){
        sign = -1;
        shift = 1;
    }
    else{
        sign = 1;
        shift = 0;
    }
    for(i = shift; i < digits+shift; i++){
        if(*(ptr+i) == '\0'){
            /* NOP */
        }
        else if(*(ptr+i) >= 'A'){
            conv_number += (*(ptr+i) - 55)*my_pow( base, digits+shift-i-1);
        }
        else{
            conv_number += (*(ptr+i) - 48)*my_pow( base, digits+shift-i-1);
        }
    }

    return conv_number*sign;

}