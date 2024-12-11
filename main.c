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
    unsigned int size;  // Very convenient because we are not forced to loop through the DS to get the size. Plus, makes the code mode readable.
} LinkedList; 

// Prototypes
LinkedList* create_list(); 
void insert(LinkedList*, int); 
void read(LinkedList*); 

int main(int* argc, char** argv) 
{
    LinkedList* myLinkedList = create_list();  
    // if malloc fails, exit the program.
    if (myLinkedList == NULL) return -1; 

    // puts 10 random values into the linked list. Just for test purposes. 
    for(size_t i = 0; i < 10; i++) {
        
        insert(myLinkedList, rand()%10 + 1); 
    }

    read(myLinkedList); 
    free(myLinkedList); 
    
    return 0; 
}

LinkedList* create_list() {
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList)); 
    if (list != NULL){
        list->head = NULL; 
        list->size = 0; 
    }
    return list; 
}

void insert(LinkedList* list, int elt) {
    Node* new_elt = (Node*) malloc(sizeof(Node));
    if (new_elt == NULL) return; // abort execution if malloc failed...

    // Basic initialization of the Node
    new_elt->data = elt; 
    new_elt->next = NULL;  
     
    if (list->size == 0) {
        list->head = new_elt;
        list->size++; 
        return; // if successful, exit the function to prevent further execution
    }
   
    Node* ptr_node = list->head; 
    while(ptr_node->next != NULL) {
        ptr_node = ptr_node->next; 
    }
    ptr_node->next = new_elt; 

    list->size++; // if not already been ++ed
}

void read(LinkedList* list) {
    printf("[");
    if (list->size>0) {
        // Indeed, if the list is empty, we don't need to go through all that suffering... 
        Node* ptr_node = list->head; 
        while (ptr_node != NULL) {
            // Each iteration, we read the next adress and make that address the address of our pointer. 
            // Of course, iif our pointer points to somewhere... We are not gonna dereference a NULL pointer...
            printf("%d", ptr_node->data); 
            ptr_node = ptr_node->next; 
            if(ptr_node != NULL) printf(", "); // ... this line is here for formating purposes... 
        }    
    }
    printf("]"); 
}
