#ifndef TREE_H 
#define TREE_H


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


typedef float item_t;
#define SPEC "lg"


typedef struct Node Node;
struct Node
{
    item_t value;      
    Node*  left;    
    Node*  right;   
};



void tree_print_direct(Node** p_tree);

void tree_print_symmetric(Node** p_tree);

void tree_print_back(Node** p_tree);

Node* tree_add(Node** p_tree, item_t element);

Node* tree_delete_node(Node** p_tree, item_t element);

bool tree_check(Node** p_tree);

void tree_destroy(Node** p_tree);

size_t tree_depth(Node** p_tree);

void tree_dump(Node** p_tree, char* filename);


#endif
