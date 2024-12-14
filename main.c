#include <stdio.h>
#include "static/headers/linkedlist.h"
 

int main(int argc, int** argv){
    LinkedList* list = create_list(); 
    printf("List created!\n"); 

    printf("List size is now %d\n", list->size); 
    for(size_t i = 0; i <= 10; i++) {
        insert(list, i); 
        display(list); 
        printf("List size is now %d\n", list->size); 
    }

    if(is_in(list, 5)) printf("Found it!\n"); 
    if(is_in(list, 0)) printf("Found it!\n"); 
    if(is_in(list, 10)) printf("Found it!\n"); 
    return 0; 
}