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
_Bool insert(LinkedList*, int); 
void read(LinkedList*); 

int main(int* argc, char** argv) 
{
    LinkedList* myLinkedList = create_list();  
    if (myLinkedList->is_initialized) {
        printf("Linked list successfuly created!\n"); 
    } else {
        printf("Failed! "); 
    }

    for(size_t i = 0; i < 10; i++) {
        insert(myLinkedList, rand()%10); 
    }

    printf("list in size %d\n", myLinkedList->size);
    read(myLinkedList); 
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

_Bool insert(LinkedList* list, int elt) {
    Node* new_elt = (Node*) malloc(sizeof(Node));
    if (new_elt == NULL) return false;

    new_elt->data = elt; 
    new_elt->next = NULL;  
     
    if (list->size == 0) {
        list->head = new_elt;
        list->size++; 
        return true; 
    }
   
    Node* ptr_node = list->head; 
    while(ptr_node->next != NULL) {
        ptr_node = ptr_node->next; 
    }
    ptr_node->next = new_elt; 

    list->size++; // if not already been ++ed
    return true; // new element succesfuly added
}

void read(LinkedList* list) {
    printf("[");
    if (list->size>0) {
        Node* ptr_node = list->head;
        while (ptr_node != NULL) {
            printf("%d", ptr_node->data); 
            ptr_node = ptr_node->next; 
            if(ptr_node != NULL) printf(", "); 
        }    
    }
    printf("]"); 
}
