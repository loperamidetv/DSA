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
    list->size++; 
}

void insert_at(LinkedList* list, int index, int elt) {
    if(index > list->size -1) return; 

    if(index == 0) {
        _insert_begining(list, elt); // the function handles the Node* creation internally
        return; 
    }
    // New node creation and initialization
    Node* new_elt = (Node*) malloc(sizeof(Node)); 
    if(new_elt == NULL) return; 
    new_elt->data = elt; 
    new_elt->next = NULL;

    // ptr creation used to go through the list
    Node* ptr = list->head; 

    for(size_t i = 0; i < index - 1; i++) {
        ptr = ptr->next; 
    }
    new_elt->next = ptr->next; 
    ptr->next = new_elt; 

    list->size++; 
} 

void insert(LinkedList* list, int elt) {
    // Insert at the end of the list
    Node* ptr = list->head; 

    if(ptr == NULL) {
        _insert_begining(list, elt); // no malloc creation here, insert begining handles it
        return ; 
    }
    // else... basically if list is not empty, go through it
    Node* new_elt = (Node*) malloc(sizeof(Node)); 
    if(new_elt == NULL) return; 
    
    new_elt->data = elt; 
    new_elt->next = NULL;

    while(ptr->next != NULL) {
        ptr = ptr->next; 
    }
    ptr->next = new_elt;  
    list->size++; 
}

void _remove_begining(LinkedList* list) {
    if(list->size == 0) return; // if no elements to remove

    Node* ptr = list->head; 
    list->head = ptr->next; 

    free(ptr); 
    list->size--; 
}

void _remove_end(LinkedList* list) {
    if(list->size == 0) return; // nothing to delete...

    Node* ptr = list->head; 
    while(ptr->next->next != NULL) { // it works, but... what about readability?
        ptr = ptr->next; 
    }
    printf("Data is %d\n", ptr->data); 
    free(ptr->next); 
    ptr->next = NULL; 
    
    list->size--; 
} 

void remove_at(LinkedList* list, int index) {
    
}