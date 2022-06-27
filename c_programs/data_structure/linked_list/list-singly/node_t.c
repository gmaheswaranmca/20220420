#include<stdlib.h>
#include"node_t.h"

void node_init(node_t* node, double val){
    node->data = val;
    node->next = NULL;
}