#include "../Z1/include/tree.h"
#include "math.h"


void tree_balanced(Node** p_tree, bool* status)
{
    if(*p_tree == NULL)
    {
        *status = true;
        return ;
    }

    if(abs( tree_depth(&(*p_tree)->left) - tree_depth(&(*p_tree)->right) ) <= 1)
    {
        *status = true;
    }
    else
    {
        *status = false;
        return ;
    }

    tree_balanced( &( (*p_tree)->left ), status );
    tree_balanced( &( (*p_tree)->right), status );
}


int main()
{
    Node* p_tree = NULL;
    tree_add(&p_tree, 7);
    tree_add(&p_tree, 6);
    tree_add(&p_tree, 9);
    tree_add(&p_tree, 2);
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
    tree_dump(&p_tree, "tree1.dot");
    tree_delete_node(&p_tree, 3);
    tree_dump(&p_tree, "tree2.dot");

    bool is_balanced = true;
    tree_balanced(&p_tree, &is_balanced);
    printf("%d\n", is_balanced);

    return 0;
}