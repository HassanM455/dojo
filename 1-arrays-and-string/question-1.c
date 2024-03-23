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


struct MyUInt8Array {
  uint8_t size;
  uint8_t* array;
  void (*add_elem)(uint8_t, uint8_t, struct MyUInt8Array*);
  void (*rm_elem)(struct MyUInt8Array* , uint8_t ) ;  
  void (*reverse_array)(struct MyUInt8Array*) ; 
} ; 

struct MyString {
  char* string ;
  int length ;
  int (*get_length)(struct MyString*) ;
  void (*reverse_string)(struct MyString*);
} ;

void question_1__add_elem_to_array(
    uint8_t pos, uint8_t elem,
    struct MyUInt8Array* arr_obj
) {
    
    uint8_t size = arr_obj->size ;

    uint8_t new_size = size + 1 ; 

    uint8_t* new_arr = _alloc_uint8_array(new_size);
    
    size_t first_subset_bytes = (pos)*(SIZEOF_UINT8);
    size_t second_subset_bytes = (size - pos)*(SIZEOF_UINT8); 

    uint8_t* arr_last_subset_ptr = arr_obj->array + pos*(SIZEOF_UINT8) ; 
    uint8_t* newarr_last_subset_ptr = new_arr + (pos + 1)*(SIZEOF_UINT8);

    memcpy(
      new_arr, 
      arr_obj->array, 
      first_subset_bytes
    );

    *(new_arr + pos*(SIZEOF_UINT8)) = elem ; 

    memcpy(
      newarr_last_subset_ptr, 
      arr_last_subset_ptr, 
      second_subset_bytes
    );

    arr_obj->size = new_size ;

    if (arr_obj->array != NULL){
      free(arr_obj->array);
    }
    arr_obj->array = new_arr ; 


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

}

int question_1__get_string_len(struct MyString *str_obj) {
    
    int str_len = 0 ; 
    char character = *(str_obj->string) ;  

    while(character != '\0') {
      str_len++ ;
      character = *(str_obj->string + str_len) ; 
    }
    
    str_obj->length = str_len; 

    return str_len; 
}

void question_1__rm_elem_from_array(
  struct MyUInt8Array* arr_obj, uint8_t pos
) {
  
  uint8_t size = arr_obj->size ;
  uint8_t* arr = arr_obj->array ; 

  memcpy(
      arr + (pos)*SIZEOF_UINT8, 
      arr + (pos + 1)*SIZEOF_UINT8,
      (size - (pos + 1))*SIZEOF_UINT8
  );

  *(arr + (size - 1)*SIZEOF_UINT8) = 0;
}

void question_1__reverse_array(struct MyUInt8Array *arr_obj) {
   
    uint8_t size = arr_obj->size ; 
    uint8_t *new_array = _alloc_uint8_array(size) ; 
    
    for(int i = 0; i < size; i++) {
      *(new_array + (size - i - 1)) = *(arr_obj->array + i) ; 
    }

    free(arr_obj->array);
    arr_obj->array = new_array ; 

}
 
void question_1__reverse_string(struct MyString *str_obj) {

    int str_len = str_obj->get_length(str_obj);
    char* temp = _alloc_char_array((uint8_t)str_len);


    char curr_char = *(str_obj->string) ;
    char* end_of_revstr_addr = temp + (str_len - 1)*sizeof(char);
    int i = 0 ;

    while(curr_char != '\0'){
      *(end_of_revstr_addr - i*sizeof(char)) = curr_char ; 
      curr_char = *(str_obj->string + (i+1)*sizeof(char)); // next character
      i++ ; 
    }

    *(temp + str_len*sizeof(char)) = '\0' ; 

    /*
    for(int i = 0 ; i <= str_len  ; i++) {
      *(temp + i) = *(str_obj->string + str_len - 1 - i);
    }
    */
    if (str_obj->string != NULL) {
        free(str_obj->string);
    }

    str_obj->string = (char* )temp ;   
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

    struct MyUInt8Array uint8_arr ; 
    uint8_arr.size = INITIAL_SIZE ;
    uint8_arr.array = _generate_array(INITIAL_SIZE); 
    uint8_arr.add_elem = question_1__add_elem_to_array ; 
    uint8_arr.rm_elem = question_1__rm_elem_from_array ; 
    uint8_arr.reverse_array = question_1__reverse_array ; 

    char* textline = _alloc_char_array((uint8_t)20);
    strcpy(textline, "Hello World, I am a string");
    struct MyString my_str ; 
    my_str.string = textline ;
    my_str.get_length = question_1__get_string_len ; 
    my_str.reverse_string = question_1__reverse_string ;
    my_str.get_length(&my_str); 

    //  An operation to add and remove elements from an array.   
    uint8_t insertion_point = 6;
    uint8_t insertion_value = (uint8_t) ( rand() % INT_RANGE) ; 

    _print_array(uint8_arr.array, INITIAL_SIZE) ;
    
    _print_space_btw_ans() ; 

    printf("Inserting %d into index %d \n", insertion_value, insertion_point);
    uint8_arr.add_elem(
      insertion_point, insertion_value, 
      &uint8_arr
    );

    _print_array(uint8_arr.array, uint8_arr.size) ; 

    _print_space_btw_ans() ; 

    printf("Removing %d from index %d \n", insertion_value, insertion_point);
    uint8_arr.rm_elem(&uint8_arr, insertion_point );

    _print_array(uint8_arr.array, uint8_arr.size);

    _print_space_btw_ans();

    // A function to reverse an array.   
    
    printf("Here is the same array in reverse order: ");

    uint8_arr.reverse_array(&uint8_arr) ; 

    _print_array(uint8_arr.array, uint8_arr.size) ; 

    _print_space_btw_ans() ;

    // A function to find the length of a String.  

    int string_len = my_str.get_length(&my_str);

    printf("Here is my string '%s' of length %d \n", my_str.string, string_len);

    _print_space_btw_ans() ;
   
    // A function to reverse a string.
    
    printf("Here is the same string in reverse order: ");

    my_str.reverse_string(&my_str) ; 

    printf("%s \n", my_str.string) ; 
  
    _print_space_btw_ans() ; 
 
    return 0; 

}




