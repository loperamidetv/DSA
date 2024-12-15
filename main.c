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
    display(list);
    change(list, 0, 42); 
    display(list); 
    change(list, 5, 42);
    display(list); 
    change(list, 10, 42);
    display(list); 
    return 0; 
}