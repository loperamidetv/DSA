#include <stdlib.h>
#include "../headers/linkedlist.h"


LinkedList* create_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList)); 
    if(list == NULL) list->is_initialized = false; 

    list->head = NULL; 
    list->size = 0; 
    list->is_initialized = true; 

    return list; 
}



