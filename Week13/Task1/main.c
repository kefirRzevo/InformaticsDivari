#include "include/tree.h"
/*
gcc -g -Wextra -Wall -Wpedantic -fsanitize=address -c main.c src/tree.c
gcc -g -Wextra -Wall -Wpedantic -fsanitize=address -o a main.o tree.o  
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
    tree_add(&p_tree, 0);
    tree_add(&p_tree, 10);
    tree_add(&p_tree, 3.5);
    tree_add(&p_tree, 1.5);
    tree_add(&p_tree, 2.5);
    tree_add(&p_tree, 2.25);
    tree_add(&p_tree, 2.75);
    tree_add(&p_tree, 4.5);
    tree_add(&p_tree, 5.5);
    tree_add(&p_tree, 6.5);
    tree_add(&p_tree, 8.5);
    tree_add(&p_tree, 7.5);
    tree_add(&p_tree, 8.25);
    tree_add(&p_tree, 8.75);
    tree_add(&p_tree, 7.25);
    tree_add(&p_tree, 7.75);
    tree_add(&p_tree, 10.5);
    tree_add(&p_tree, 9.5);
    tree_add(&p_tree, 10.25);
    tree_add(&p_tree, 10.75);
    tree_add(&p_tree, 9.25);
    tree_add(&p_tree, 9.75);

    tree_dump(&p_tree, "tree1.dot");

    tree_delete_node(&p_tree, 4);

    tree_dump(&p_tree, "tree2.dot");

    tree_delete_node(&p_tree, 3);

    size_t depth = tree_depth(&p_tree);
    printf("\n%zu\n", depth);
    
    tree_dump(&p_tree, "tree3.dot");
    tree_destroy(&p_tree);
    //printf("\n%p\n", p_tree);
    return 0;
}
