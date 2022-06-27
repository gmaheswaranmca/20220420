#include<stdio.h>
#include<stdlib.h>
#include"list_traversal.h" 


void traversal(node_t *head){
    node_t* node = head;
    printf("The salaries are:\n");
    while(node != NULL){
        printf("%.2lf ",node->data);
        node = node->next;
    }
    printf("\n");
}
