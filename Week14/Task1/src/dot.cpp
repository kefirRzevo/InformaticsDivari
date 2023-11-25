#include "../include/list.h"
#include "../include/dot.h"


FILE* open_dot_txt(const char* const dot_path)
{
    assert(dot_path);

    FILE* dotfile   = nullptr;
    dotfile         = fopen(dot_path, "w");
    
    fprintf(dotfile,    "digraph G \n{\n"
                        "\tgraph[rankdir = LR]\n"
                        "\tnode[shape = box, fontsize = 8]\n\n");
    return dotfile;
}


void close_dot_txt(FILE* const dotfile)
{
    assert(dotfile);

    fprintf(dotfile, "}");
    fclose(dotfile);
}


static void print_node(node* node, FILE* const dotfile)
{
    fprintf(dotfile,    "\tsubgraph cluster%p\n\t{\n"
                        "\t\tmargin = 0\n"
                        "\t\tfontsize = 8\n"
                        "\t\tlabel  = Node%p\n"
                        "\t\tNode%p[shape = record, label = \"item: %" SPECIFICATOR " | <n>next: %p | <p>prev: %p\"]\n"
                        "\t}\n", node, node, node, node->data, node->next, node->prev);
    fprintf(dotfile,    "\t\tNode%p:n -> Node%p:n[color = \"red\"]\n\n", node, node->next);
}


void print_nodes(const list* const p_list, FILE* const dotfile)
{
    assert(dotfile);
    assert(p_list);

    node* node = p_list->tail;
    for(size_t i = 0; i < p_list->size; i++)
    {
        print_node(node, dotfile);
        node = node->next;
    }
    fprintf(dotfile, "\n");
}