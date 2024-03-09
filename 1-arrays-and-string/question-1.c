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
#define SIZEOF_UINT8 sizeof(uint8_t)


typedef struct {
  uint8_t size;
  uint8_t* array;
  uint8_t* (*add_elem)(uint8_t, uint8_t, uint8_t*, uint8_t) ;
  void (*rm_elem)(uint8_t* , uint8_t , uint8_t ) ;  
  uint8_t* (*reverse_array)(uint8_t*, uint8_t) ; 
} MyUInt8Array ; 

uint8_t* question_1__add_elem_to_array(
    uint8_t pos, uint8_t elem,
    uint8_t *arr, uint8_t size
) {
  
    uint8_t new_size = size + 1 ; 

    uint8_t* new_arr = _alloc_uint8_array(new_size);
    
    size_t first_subset_bytes = (pos)*(SIZEOF_UINT8);
    size_t second_subset_bytes = (size - pos)*(SIZEOF_UINT8); 

    uint8_t* arr_last_subset_ptr = arr + pos*(SIZEOF_UINT8) ; 
    uint8_t* newarr_last_subset_ptr = new_arr + (pos + 1)*(SIZEOF_UINT8);

    memcpy(
      new_arr, 
      arr, 
      first_subset_bytes
    );

    *(new_arr + pos*(SIZEOF_UINT8)) = elem ; 

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
        *(new_arr + i*SIZEOF_UINT8) = elem ;
        shift_down = 1 ; 
      } else {
        old_val = *(arr + (i - shift_down)*SIZEOF_UINT8);
        *(new_arr + i*SIZEOF_UINT8) = old_val ;   
      }
    
    } 
*/

    return new_arr ; 
}

int question_1__get_string_len(char str[]) {
    
    int str_len = 0 ; 
    char character = *str ;  

    while(character != '\0') {
      str_len++ ;
      character = *(str + str_len) ; 
    }

    return str_len; 
}

void question_1__rm_elem_from_array(
  uint8_t arr[], uint8_t size, uint8_t pos
) {
  
  memcpy(
      arr + (pos)*SIZEOF_UINT8, 
      arr + (pos + 1)*SIZEOF_UINT8,
      (size - (pos + 1))*SIZEOF_UINT8
  );

  *(arr + (size - 1)*SIZEOF_UINT8) = 0;
}

uint8_t* question_1__reverse_array(uint8_t arr[], uint8_t size) {
    
    uint8_t *new_array = _alloc_uint8_array(size) ; 

    for(int i = 0; i < size; i++) {
      *(new_array + (size - i - 1)) = *(arr + i) ; 
    }

    return new_array ; 

}
 
void question_1__reverse_string(char* str, uint8_t str_len) {

    char temp[str_len] ; 

    for(int i = 0 ; i <= str_len  ; i++) {
      temp[i] = *(str + str_len - 1 - i);
    }

    strcpy(str, temp);  
}

int main(int argc, char *argv[]) {

    printf(
    "1. **Basic operations on Arrays and Strings** \n\
    \n\
    Implement the following tasks in your preferred language: \n\
    \n\
      - An operation to add and remove elements from an array. \n\
      - A function to find the length of a String. \n\
      - A function to reverse an array and a String. \n\
    \n"
    );

    //  An operation to add and remove elements from an array.   
    uint8_t insertion_point = 6;
    uint8_t insertion_value = (uint8_t) ( rand() % INT_RANGE) ; 

    uint8_t *first_arr = _generate_array(INITIAL_SIZE);

    uint8_t new_size = INITIAL_SIZE + 1 ; 

    _print_array(first_arr, INITIAL_SIZE) ;
    
    _print_space_btw_ans() ; 

    printf("Inserting %d into index %d \n", insertion_value, insertion_point);
    uint8_t *new_array = question_1__add_elem_to_array(
      insertion_point, insertion_value, first_arr, INITIAL_SIZE
    );

    _print_array(new_array, new_size) ; 

    _print_space_btw_ans() ; 

    printf("Removing %d from index %d \n", insertion_value, insertion_point);
    question_1__rm_elem_from_array(new_array, new_size, insertion_point );

    _print_array(new_array, new_size);

    _print_space_btw_ans();

    // A function to find the length of a String.  
    
    char my_string[] = "Hello world";

    int string_len = question_1__get_string_len(my_string); 

    printf("Here is my string '%s' of length %d \n", my_string, string_len);
    
    _print_space_btw_ans() ; 

    // A function to reverse an array and a String.   
    
    printf("Here is the same array in reverse order: ");

    new_array = question_1__reverse_array(new_array, new_size);
    
    _print_array(new_array, new_size) ; 

    _print_space_btw_ans() ; 


    printf("Here is the same string in reverse order: ");

    question_1__reverse_string(my_string, string_len) ; 

    printf("%s \n", my_string) ; 
  
    _print_space_btw_ans() ; 
  
    return 0; 

}




