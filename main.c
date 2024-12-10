#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structs for Node & LinkedList
typedef struct Node {
    int data; 
    struct Node* next; 
} Node; 

typedef struct LinkedList {
    Node* head; 
    unsigned int size; 
    _Bool is_initialized; 
} LinkedList; 

// Prototypes
LinkedList* create_list(); 

int main(int* argc, char** argv) 
{
    LinkedList* myLinkedList = create_list();  
    if (myLinkedList->is_initialized) {
        printf("Linked list successfuly created!"); 
    } else {
        printf("Failed! "); 
    }
    
    free(myLinkedList); 
    
    return 0; 
}

LinkedList* create_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList)); 
    if (list != NULL){
        list->head = NULL; 
        list->size = 0; 
        list->is_initialized = true; 
    }
    else {
        list->is_initialized = false; 
    }
    return list; 
}