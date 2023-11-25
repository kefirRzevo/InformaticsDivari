#include "../include/tree.h" 


static size_t max (size_t x, size_t y) 
{
   return x > y ? x : y;
}


static void print_node(FILE* fp, Node** p_tree)
{
    if (*p_tree == NULL)
	    return; 

    print_node(fp, &((*p_tree)->left));
    if( ((*p_tree)->left) != NULL)
        fprintf(fp, "\tNode%p [label = %-4" SPEC "]"
                    "\tNode%p [label = %-4" SPEC "]"
                    "\tNode%p -> Node%p;         \n", *p_tree, (*p_tree)->value, (*p_tree)->left, ((*p_tree)->left)->value, *p_tree, (*p_tree)->left);
    print_node(fp, &((*p_tree)->right));
    if( ((*p_tree)->right) != NULL)
        fprintf(fp, "\tNode%p [label = %-4" SPEC "]"
                    "\tNode%p [label = %-4" SPEC "]"
                    "\tNode%p -> Node%p;         \n", *p_tree, (*p_tree)->value, (*p_tree)->right, ((*p_tree)->right)->value, *p_tree, (*p_tree)->right);
}


static Node* tree_min(Node** p_tree)
{
    if((*p_tree)->left == NULL)
        return *p_tree;
    
    return((*p_tree)->left);
}


Node* tree_add(Node** p_tree, item_t element)
{
    if (*p_tree == NULL) 
    {
        *p_tree             = (Node *) malloc(sizeof(Node));
        assert(p_tree);
        (*p_tree)->value    = element;
        (*p_tree)->left     = NULL;
        (*p_tree)->right    = NULL;
    } 
    else if (element < (*p_tree)->value) 
    {
	    (*p_tree)->left     = tree_add(&((*p_tree)->left), element);
    }
    else if (element > (*p_tree)->value) 
    {
	    (*p_tree)->right   = tree_add(&(*p_tree)->right, element);
    }
    else
    {
        Node* new_tree      = (Node *) malloc(sizeof(Node));
        assert(*p_tree);

        new_tree->value     = (*p_tree)->value;
        new_tree->left      = (*p_tree)->left;
        new_tree->right     = (*p_tree)->right;
        (*p_tree)->left     = new_tree;
        (*p_tree)->right    = NULL;
    }

    return *p_tree;
}


Node* tree_delete_node(Node** p_tree, item_t element)
{
    if(*p_tree == NULL)
    {
        return *p_tree;
    }

    if(element < (*p_tree)->value)
    {
        (*p_tree)->left = tree_delete_node(&(*p_tree)->left, element);
    }
    else if (element > (*p_tree)->value)
    {
        (*p_tree)->right = tree_delete_node(&(*p_tree)->right, element);
    }
    else if ((*p_tree)->left != NULL && (*p_tree)->right != NULL)
    {
        (*p_tree)->value = tree_min(&(*p_tree)->right)->value;
        (*p_tree)->right = tree_delete_node(&(*p_tree)->right, (*p_tree)->value);
    }
    else
    {
        if((*p_tree)->left != NULL)
        {
            *p_tree = (*p_tree)->left;
        }
        else if ((*p_tree)->right != NULL)
        {
            *p_tree = (*p_tree)->right;
        }
        else
        {
            *p_tree = NULL;
        }
    }

    return *p_tree;
}


void tree_print_direct(Node** p_tree)
{
    if(*p_tree == NULL)
        return;

    printf("%-4" SPEC "", ((*p_tree)->value));

    tree_print_direct( &( (*p_tree)->left ) );
    tree_print_direct( &( (*p_tree)->right) );
}


void tree_print_symmetric(Node** p_tree)
{
    if (*p_tree == NULL)
	    return;                         

    tree_print_symmetric( &((*p_tree)->left));

    printf("%-4" SPEC "", ((*p_tree)->value));

    tree_print_symmetric( &((*p_tree)->right));
}


void tree_print_back(Node** p_tree)
{
    if(*p_tree == NULL)
        return;

    tree_print_back( &( (*p_tree)->left ) );
    tree_print_back( &( (*p_tree)->right) );

    printf("%-4" SPEC "", ((*p_tree)->value));
}


void tree_dump(Node** p_tree, char* filename)
{
    FILE* fp = fopen(filename, "w");

    fprintf(fp, "digraph G \n{\n"
                "bgcolor  = \"#FFFFFF\"\n"                                                                     
                "compound = true\n"                                                                              
                "newrank  = true\n"                                                                              
                "graph[dpi = 250, splines = polyline, nodesep = 0.3, ranksep = 1]\n"               
                "node[shape = box, style = \"filled\", penwidth = 2, color = \"#333333\", margin = 0.04,\n"      
                "fontcolor = \"green\", fontsize = 8, fillcolor = \"#666666\", fontname = \"Consolas\"]\n"       
                "edge[arrowsize = 0.7, style = solid, penwidth = 1.1]\n");   

    print_node(fp, p_tree); 
    fprintf(fp, "}\n");

    char dotfile[64] = "";
    char cmd_string[64] = "";
    char img_string[64] = "";
    char rm_dot[64] = "";
    sprintf(rm_dot, "rm %s",   filename);

    sprintf(dotfile, "%s", filename);
    int i = 0;
    while(dotfile[i]!='.')
    {
        img_string[i] = dotfile[i];
        i++;
    }
    img_string[i] = '\0';
    sprintf(cmd_string, "dot %s -Tpng -o %s.png",   filename, img_string);

    fclose(fp);
    system(cmd_string);
    system(rm_dot);
}


void tree_destroy(Node** p_tree)
{
    if(*p_tree != NULL)
    {
        tree_destroy( &( (*p_tree)->left ) );
        tree_destroy( &( (*p_tree)->right) );
        free(*p_tree);
        *p_tree = NULL;
    }
}


size_t tree_depth(Node** p_tree)
{
    if (*p_tree == NULL)
	    return 0;                         

    size_t n_left  = tree_depth( &((*p_tree)->left ));
    size_t n_right = tree_depth( &((*p_tree)->right));
    size_t depth   = max(n_left, n_right);

    return depth + 1;
}


bool tree_check(Node** p_tree)
{
    if((*p_tree)->left == NULL && (*p_tree)->right == NULL)
        return false;

    return true;
}