#include <stdio.h>
#include "../headers/dblinkedlist.h"

DbLinkedList* create_db_linkedlist() {
    DbLinkedList* list = (DbLinkedList*) malloc(sizeof(DbLinkedList)); 
    if(list == NULL) {
        list->head = NULL; 
        list->size = 0; 
        list->is_initialized = false; 
        return list; 
    } 

    list->head = NULL; 
    list->size = 0; 
    list->is_initialized = true; 

    return list; 
}