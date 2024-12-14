#include <stdio.h>
#include "static/headers/linkedlist.h"
 

int main(int argc, int** argv){
    LinkedList* list = create_list(); 
    printf("List created!\n"); 
    
    for(size_t i = 0; i <= 10; i++) {
        _insert_begining(list, i); 
        display(list); 
    }

    return 0; 
}