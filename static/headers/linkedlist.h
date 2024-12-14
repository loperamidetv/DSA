#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include <stdbool.h>

typedef struct {
    int data; 
    struct Node* next;
} Node; 

typedef struct {
    Node* head; 
    unsigned int size; 
    _Bool is_initialized; 
} LinkedList;

LinkedList* create_list(); 

#endif 