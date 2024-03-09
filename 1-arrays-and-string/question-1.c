/*

1. **Basic operations on Arrays and Strings**

   Implement the following tasks in your preferred language:
   
   - An operation to add and remove elements from an array.
   - A function to find the length of a String.
   - A function to reverse an array and a String. 
   

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "./utilities.c"

#define INITIAL_SIZE 10  
#define INT_RANGE 256


uint8_t* question_1__add_element_array(
    uint8_t pos, uint8_t elem,
    uint8_t *arr, uint8_t size
) {
  
    uint8_t new_size = size + 1 ; 

    uint8_t* new_arr = _alloc_uint8_array(new_size);
    
    size_t first_subset_bytes = (pos)*(sizeof(uint8_t));
    size_t second_subset_bytes = (size - pos)*(sizeof(uint8_t)); 

    uint8_t* arr_last_subset_ptr = arr + pos*(sizeof(uint8_t)) ; 
    uint8_t* newarr_last_subset_ptr = new_arr + (pos + 1)*(sizeof(uint8_t));

    memcpy(
      new_arr, 
      arr, 
      first_subset_bytes
    );

    *(new_arr + pos*(sizeof(uint8_t))) = elem ; 

    memcpy(
      newarr_last_subset_ptr, 
      arr_last_subset_ptr, 
      second_subset_bytes
    );


/*    
    uint8_t old_val ; 
    uint8_t shift_down = 0 ; 

    for(int i = 0 ; i < new_size; i++) {
      
      if(i == pos) {
        *(new_arr + i*sizeof(uint8_t)) = elem ;
        shift_down = 1 ; 
      } else {
        old_val = *(arr + (i - shift_down)*sizeof(uint8_t));
        *(new_arr + i*sizeof(uint8_t)) = old_val ;   
      }
    
    } 
*/

    return new_arr ; 
}

int main(int argc, char *argv[]) {

    uint8_t insertion_point = 6;
    uint8_t insertion_value = (uint8_t) ( rand() % INT_RANGE) ; 

    uint8_t *first_arr = _generate_array(INITIAL_SIZE);

    uint8_t new_size = INITIAL_SIZE + 1 ; 

    _print_array(first_arr, INITIAL_SIZE) ;

    printf("Inserting %d into index %d \n", insertion_value, insertion_point);
    uint8_t *new_array = question_1__add_element_array(
      insertion_point, insertion_value, first_arr, INITIAL_SIZE
    );

    _print_array(new_array, new_size) ; 

    return 0; 

}
