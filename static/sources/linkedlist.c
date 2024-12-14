#include <stdlib.h>
#include <stdio.h>
#include "../headers/linkedlist.h"


LinkedList* create_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList)); 
    if(list == NULL) list->is_initialized = false; 

    list->head = NULL; 
    list->size = 0; 
    list->is_initialized = true; 

    return list; 
}

void display(LinkedList* list) {
    printf("["); 
    Node* ptr = list->head; 
    while(ptr != NULL) {
        printf("%d", ptr->data); 
        if(ptr->next != NULL) printf(", "); 
        ptr = ptr->next; 
    }
    printf("]\n"); 
}

void _insert_begining(LinkedList* list, int elt) {
    Node* ptr = list->head; 

    Node* new_element = (Node*) malloc(sizeof(Node)); 
    if(new_element == NULL) return; 

    new_element->data = elt; 
    new_element->next = ptr; 

    list->head = new_element; 
}



