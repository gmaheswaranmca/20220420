#pragma once
struct _node_t{
    double data;
    struct _node_t* next;
};
typedef struct _node_t node_t;

//node 
void node_init(node_t* node, double val);