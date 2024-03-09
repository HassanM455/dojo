#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define INITIAL_SIZE 10 
#define INT_RANGE 256

uint8_t* _alloc_uint8_array(uint8_t size) {
    
    uint8_t *array = (uint8_t*)calloc(size, sizeof(uint8_t));
    
    while(array == NULL) { 
      array = (uint8_t*)calloc(size, sizeof(uint8_t));
    }
    
   
    return array ; 
}

uint8_t* _generate_array(uint8_t size) {

     
    uint8_t* rand_array = _alloc_uint8_array(size);

    
    for(uint8_t i = 0; i < size; i++) {
       *(rand_array + i*sizeof(uint8_t)) = rand() % INT_RANGE ;  
    }

    return rand_array ; 

}

void _print_array(uint8_t* arr, uint8_t size) {
    printf("[ ");

    for(uint8_t i = 0 ; i < size; i++) {
      printf("%d, ", *(arr + i*sizeof(uint8_t)) ) ; 
    }

    printf("]\n");
}
