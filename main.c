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
    get_elt(list, 0); 
    printf("element 0's data is %d\n", get_elt(list, 0)->data); 
    get_elt(list, 5);
    printf("element 5's data is %d\n", get_elt(list, 5)->data); 
    get_elt(list, 10);
    printf("element 10's data is %d\n", get_elt(list, 10)->data);
    return 0; 
}