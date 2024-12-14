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
void insert_at(LinkedList*, int, int); 
void insert(LinkedList*, int); 
void _remove_begining(LinkedList*); 
void _remove_end(LinkedList*); 
void remove_at(LinkedList*, int); 

#endif 