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
Node* get(LinkedList*, int); 
void delete_at(LinkedList*, int); 
void delete_all(LinkedList*); 
void delete_elt(LinkedList*, int); 
_Bool exists(LinkedList*, int); 


int main(int argc, char** argv) 
{
    LinkedList* myLinkedList = create_list();  
    // if malloc fails, exit the program.
    if (myLinkedList == NULL) return -1; 

    insert(myLinkedList, 42); 

    // puts 10 random values range 0-10 into the linked list. Just for test purposes. 
    for(size_t i = 0; i < 10; i++) {
        
        insert(myLinkedList, rand()%10 + 1); 
    }
    insert(myLinkedList, 42); 
    insert(myLinkedList, 42); 
    

    read(myLinkedList); 
    delete_elt(myLinkedList, 42); 
    read(myLinkedList); 
    delete_elt(myLinkedList, 42);
    read(myLinkedList); 
    delete_elt(myLinkedList, 42);
    read(myLinkedList);
    delete_elt(myLinkedList, 42);
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
    printf("]\n"); 
}

Node* get(LinkedList* list, int index) {
    /*
    The only purpose of this function is to get the pointer to Node at the index I choose.
    I had at several occasions the unpleasant surprise of discovering that I needed the element at a certain index AND the element 
    before it. It sucked, I raged and I decided to make a function only to do that. 
    I don't care that I need to go through another loop, it's basically O(n)*2 which basically means O(n) and it makes my life easier.
    Plus, I need to get a particular element basically EVERYTIME so... DRY I guess.
    Cheers!
    */
    Node* ptr = list->head; 
    
    // Code refactoring incoming... this loop appears everywhere...
    for(size_t i = 0; i < list->size; i++) {
        if(index == i) return ptr; 
        ptr = ptr->next; 
    }
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
    if(list->size == 0) return; // if it has nothing to delete...
    
    // We initialize...
    Node* ptr_before = NULL; 
    Node* ptr = NULL; 
    Node* ptr_after = NULL;
    // a little overkill, but greatly help to read the code. 

    // I have to have a particular attention to the extremal cases to avoid segfaulting
    if(index == 0) { // if we are at the first element
        ptr_after = get(list, 1); // we point to the 2nd element
        free(list->head); 
        list->head = ptr_after; 
        list->size--; 
        return; 
    }
    if(index == list->size - 1) { // if we are at the end of the list...
        ptr_before = get(list, index - 1); 
        free(ptr_before->next); 
        ptr_before->next = NULL; 
        list->size--; 
        return; 
    }

    // Else...
    ptr_before = get(list, index - 1); 
    ptr = get(list, index); 
    ptr_after = get(list, index + 1); // we could point to NULL, but it doesn't mind
    free(ptr); 
    ptr_before->next = ptr_after; 
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

    // for now, we keep the LinkedList* up and running, it makes my life (and debugging) lest tedious. 
}

_Bool exists(LinkedList* list, int elt) {
    if(list->size == 0) return false; 
    if(list->size == 1) {
        if(list->head->data == elt) return true; 
        if(list->head->data != elt) return false;
    }
    // this way we eliminate the "pathological cases" of dereferencing a NULL ptr and makes the following code more natural
    
    Node* ptr = list->head; 
    while(ptr->next != NULL) { 
        if(ptr->data == elt) return true; // if elt is found inside the data section of the *ptr break the loop, quit the current function now...
        ptr = ptr->next; 
    }
    return false; // otherwise... 

}

void delete_elt(LinkedList* list, int elt) {
    // Get the index of the elt to delete and use delete_at() function

    if(list->size == 0) return; // if the list is empty, there is no elt to delete. 
    
    // we gonna use our delete_at() function to get the id of the first occurence of the element; 
    Node* ptr = list->head; 
    for(size_t index = 0; index < list->size; index++) {
        if(elt == ptr->data) {
            delete_at(list, index); 
            return; 
        }
        ptr = ptr->next;  
    }
}