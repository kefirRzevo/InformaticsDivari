#include "../Z1/include/tree.h"
#include "math.h"


void visitor(Node** p_tree, int lvl, int n)
{
    if(*p_tree == NULL)
        return;

    n++;
    
    visitor(&((*p_tree)->left),  lvl, n);
    visitor(&((*p_tree)->right), lvl, n);

    if(lvl == n)
        printf("%-4" SPEC "", (*p_tree)->value);
}

void tree_lvl_items(Node** p_tree, int lvl)
{
    visitor(p_tree, lvl + 1, 0);
    printf("\n");
}
/*
gcc -g -c main.c ../Z1/src/tree.c
gcc -g -o a main.o tree.o  
*/
int main()
{
    Node* p_tree = NULL;
    tree_add(&p_tree, 7);
    tree_add(&p_tree, 3);
    tree_add(&p_tree, 2);
    tree_add(&p_tree, 1);
    tree_add(&p_tree, 9);
    tree_add(&p_tree, 5);
    tree_add(&p_tree, 4);
    tree_add(&p_tree, 6);
    tree_add(&p_tree, 8);
    tree_add(&p_tree, 1);
    tree_add(&p_tree, 9);
    tree_add(&p_tree, 5);
    tree_add(&p_tree, 4);
    tree_add(&p_tree, 7);
    tree_add(&p_tree, 6);
    tree_add(&p_tree, 8);
    tree_add(&p_tree, 7);
    tree_add(&p_tree, 3);
    tree_add(&p_tree, 2);
    tree_add(&p_tree, 1);
    tree_add(&p_tree, 9);
    tree_add(&p_tree, 8);
    tree_add(&p_tree, 5);
    tree_add(&p_tree, 4);
    tree_add(&p_tree, 6);
    tree_dump(&p_tree, "tree3.dot");
    tree_lvl_items(&p_tree, 5);
    return 0;
}
