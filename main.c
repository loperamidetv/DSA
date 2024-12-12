#include <stdio.h>
#include <stdlib.h>

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
void delete_at(LinkedList*, int); 
void delete_all(LinkedList*); 

int main(int* argc, char** argv) 
{
    LinkedList* myLinkedList = create_list();  
    // if malloc fails, exit the program.
    if (myLinkedList == NULL) return -1; 

    // puts 10 random values range 0-10 into the linked list. Just for test purposes. 
    for(size_t i = 0; i < 10; i++) {
        
        insert(myLinkedList, rand()%10 + 1); 
    }

    read(myLinkedList); 
    delete_all(myLinkedList); 
    read(myLinkedList); 
    
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

void delete_at(LinkedList* list, int index) {
    /* The idea is to point to the first element, get the next Node and point to it. 
    We have to do this until we reach the place juste before the node that we want to delete 
    We get the "next Node" next pointer, save it somewhere
    Then, delete the node at index and put the "after" Node into the "Before" node*/

    if(index > list->size - 1) {
        printf("ERROR: Cannot reach index %d. List size is %d\n", index, list->size); 
        return; // exit the delete_at function preventing further execution
    }
    Node* ptr_to_before = list->head; 
    Node* ptr_to_index = NULL; 
    Node* ptr_to_after = NULL; 
    if(list->size > 1) {
        // if list is size 0, list->head is pointing to NULL... segfaulting if we dereference. 
        for(size_t i = 0; i < index - 1; i++){
            ptr_to_before = ptr_to_before->next; 
        }
        ptr_to_index = ptr_to_before->next; 
        ptr_to_after = ptr_to_index->next; 

        free(ptr_to_index); 

        ptr_to_before->next = ptr_to_after; 
    } else {
        free(list->head); 
        list->head = NULL; 
    }
    list->size--; 
}

void delete_all(LinkedList* list) {
    /* The main idea is to go at the end of the list where the last element is and free() it 
    Do it again until there is no elements anymore */

    Node* ptr = list->head; 
    if(ptr == NULL) return; // No need to delete elements if the link list is empty...
    while(list->size > 0) { 
        delete_at(list, (list->size)-1); 
        // no need to update the list->size thing, because delete_at() already does it. 
    }
    // pretty hacky way to do it, but 

    // for now, we keep the LinkedList* up and running, it makes my life (and debugging) lest tedious. 
}