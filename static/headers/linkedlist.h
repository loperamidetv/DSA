#ifndef LINKEDLIST_H
#define LINKEDLIST_H


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

LinkedList* create_list(); 
void display(LinkedList*); 
void _insert_begining(LinkedList*, int); 
void insert(LinkedList*, int); 

#endif 