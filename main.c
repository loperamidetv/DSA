#include <stdio.h>
#include "static/headers/dblinkedlist.h"
 

int main(int argc, int** argv){
    DbLinkedList* list = create_db_linkedlist(); 
    printf("List is %p\n", list); 
    return 0; 
}