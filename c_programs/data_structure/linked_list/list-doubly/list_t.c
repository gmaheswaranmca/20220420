#include<stdio.h>
#include<stdlib.h>
#include"list_t.h"
void destroy(node_t **headAddr){
    node_t *head = (*headAddr);
    
    while(head != NULL){
        printf("%.2lf is deleted.\n",front(head));
        pop_front(&head);
    }
    
    (*headAddr) = head;
}