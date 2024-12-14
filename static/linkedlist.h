#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#endif 

#include <stdbool.h>

typedef struct Node {
    int data; 
    struct Node* next;
} Node; 

typedef struct LinkedList {
    Node* head; 
    unsigned int size; 
    _Bool is_initialized; 
} LinkedList;
