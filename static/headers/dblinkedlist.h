#ifndef DBLINKEDLIST_H
#define DBLINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int data; 
    struct Node* prev; 
    struct Node* next; 
} Node; 

typedef struct DbLinkedList {
    Node* head; 
    int size; 
    _Bool is_initialized; 
} DbLinkedList; 

DbLinkedList* create_db_linkedlist(); 
#endif