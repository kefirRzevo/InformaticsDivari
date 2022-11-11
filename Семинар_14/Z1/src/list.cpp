#include "../include/list.h"


void list_ctor(list *const p_list)
{
    assert(p_list);

    p_list->size = 0;
    p_list->head = nullptr;
    p_list->tail = nullptr;
} 


void list_dtor(list *const p_list)
{
    assert(p_list);   

    node* p_node = p_list->tail;
    for(size_t i = 0; i < p_list->size; i++)
    {
        node* new_node = p_node;
        p_node = p_node->next;
        free(new_node);
    }

    p_list->size = 0;
    p_list->tail = nullptr;
    p_list->head = nullptr;
}


void list_insert_tail(list* const p_list, const item_t item)
{
    assert(p_list);

    node* elem = (node* ) calloc(1, sizeof(node) );
    assert(elem);

    elem->data = item;

    if(p_list->tail != nullptr && p_list->head != nullptr)
    {
        elem->prev = p_list->head;
        elem->next = p_list->tail;
        p_list->tail->prev = elem;
        p_list->head->next = elem;
    }
    else
    {
        elem->prev = elem;
        elem->next = elem;
        p_list->head = elem; 
        p_list->tail = elem;
    }

    p_list->tail = elem;
    p_list->size++;
}


void list_insert_head(list* const p_list, const item_t item)
{
    assert(p_list);

    node* elem = (node* ) calloc(1, sizeof(node) );
    assert(elem);

    elem->data = item;

    if(p_list->tail != nullptr && p_list->head != nullptr)
    {
        elem->prev = p_list->head;
        elem->next = p_list->tail;
        p_list->tail->prev = elem;
        p_list->head->next = elem;
    }
    else
    {
        elem->prev = elem;
        elem->next = elem;
        p_list->head = elem; 
        p_list->tail = elem;
    }

    p_list->head = elem;
    p_list->size++;
}


item_t list_delete_tail(list* const p_list)
{
    assert(p_list);

    if(p_list->size == 0)
    {
        printf("List is empty. Be careful.\n");
        return 0;
    }

    node*  elem      = p_list->tail;
    item_t elem_data = p_list->tail->data;

    if(p_list->size > 1)
    {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        p_list->tail     = elem->next;
    }
    else
    {
        p_list->head = nullptr;
        p_list->tail = nullptr;
    }

    free(elem);
    p_list->size--;
    return elem_data;
}


item_t list_delete_head(list* const p_list)
{
    assert(p_list);

    if(p_list->size == 0)
    {
        printf("List is empty. Be careful.\n");
        return 0;
    }

    node*  elem      = p_list->head;
    item_t elem_data = p_list->head->data;

    if(p_list->size > 1)
    {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        p_list->head     = elem->next;
    }
    else
    {
        p_list->head = nullptr;
        p_list->tail = nullptr;
    }

    free(elem);
    p_list->size--;
    return elem_data;
}
