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

    remove_at(list, 5); 
    display(list); 
    remove_at(list, 0); 
    display(list); 
    remove_at(list, 8); 
    display(list); 
    printf("List size is now %d\n", list->size); 
    return 0; 
}