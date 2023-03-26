# Statistics Functions for Unsigned Char Arrays

This project implements several statistics functions for unsigned char arrays, including the median, mean, maximum, and minimum. Additionally, there is a utility function provided to sort the array in descending order.

## Usage
To use the statistics functions in your own code, include the stats.h header file and link against the stats.c source file. Then, call the functions as needed with your own unsigned char arrays.

```
#include "stats.h"

unsigned char my_array[SIZE] = { ... };

print_statistics(my_array, SIZE);
sort_array(my_array, SIZE);
print_array(my_array, SIZE);
```

##  Function Descriptions
`print_statistics(unsigned char* array_pointer, unsigned int array_size)`
Prints the median, mean, maximum, and minimum values of the provided unsigned char array to the console.

`print_array(unsigned char* array_pointer, unsigned int array_size)`
Prints each element of the provided unsigned char array to the console, with the element's index and value.

`find_median(unsigned char* array_pointer, unsigned int array_size)`
Finds the median value of the provided unsigned char array.

`find_mean(unsigned char* array_pointer, unsigned int array_size)`
Finds the mean value of the provided unsigned char array.

`find_maximum(unsigned char* array_pointer, unsigned int array_size)`
Finds the maximum value of the provided unsigned char array.

`find_minimum(unsigned char* array_pointer, unsigned int array_size)`
Finds the minimum value of the provided unsigned char array.

`sort_array(unsigned char* array_pointer, unsigned int array_size)`
Sorts the provided unsigned char array in descending order.

# License
This code is released under the terms of the MIT License.

# Contact
If you'd like to contact me, please send me an email.
jahoyosr@gmail.com