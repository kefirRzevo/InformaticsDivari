#ifndef LIST_H
#define LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <cstddef>
#include <assert.h>
#include <string.h>
#include <time.h>


typedef int item_t;
#define SPECIFICATOR "d"


struct node
{
    item_t  data;
    node*   next;
    node*   prev;
};


struct list
{
    node*   head;
    node*   tail;
    size_t  size;
};


void    list_ctor(list *const p_list);

void    list_dtor(list *const p_list);

void    list_insert_tail(list* const p_list, const item_t item);

void    list_insert_head(list* const p_list, const item_t item);

item_t  list_delete_tail(list* const p_list);

item_t  list_delete_head(list* const p_list);


#endif