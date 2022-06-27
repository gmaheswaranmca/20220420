#include<stdio.h>
#include<stdlib.h>
#include"list_operations.h" 
void push_front(node_t **headAddr, double val){
    node_t *head = (*headAddr);
    
    node_t* node = (node_t*)malloc(1*sizeof(node_t));
    node_init(node,val);//{50,x}
    //adjust
    if(head == NULL){
        //empty list 
        head = node;
    }else{
        //list of atleast one node 
        node->next = head;
        head = node;
    }
    
    (*headAddr) = head;
}
void pop_front(node_t **headAddr){
    node_t *head = (*headAddr);
    
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    
    node_t* node = head;
    //adjust
    if(node->next == NULL){
        head = NULL;
    }else{
        head = node->next;
    }
    
    //deallocator
    node->next = NULL;
    free(node);
    node = NULL;
    
    (*headAddr) = head;
}
double front(node_t *head){
    if(head == NULL){
        printf("List is empty.\n");
        return -1.0;
    }
    return head->data;
}