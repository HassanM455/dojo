#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define INITIAL_SIZE 10 
#define INT_RANGE 256
#define MALLOC_ATTEMPTS_ALLOWED 4


void _print_space_btw_ans() {printf("\n\n\n"); }

uint8_t* _alloc_uint8_array(uint8_t size) {
    
    uint8_t *array = (uint8_t*)calloc(size, sizeof(uint8_t));
    int attempt = 0 ; 

    while(array == NULL) { 
      
      if (attempt >= MALLOC_ATTEMPTS_ALLOWED) {
        printf("Could not allocated memory after %d attempts \n", MALLOC_ATTEMPTS_ALLOWED);
        exit(-1) ; 
      }

      array = (uint8_t*)calloc(size, sizeof(uint8_t));
      attempt++ ; 
    }
    
   
    return array ; 
}

char* _alloc_char_array(uint8_t size) {

    char* string = (char *)malloc((size + 1)*sizeof(char)); // alloc extra space for null character 
    int attempt = 0 ; 

    while(string == NULL) {

      if (attempt >= MALLOC_ATTEMPTS_ALLOWED) {
        printf("Could not allocated memory after %d attempts \n", MALLOC_ATTEMPTS_ALLOWED);
        exit(-1) ; 
      }

      string = (char *)malloc(size*sizeof(char));
      attempt++ ; 
    }

    return string;
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
