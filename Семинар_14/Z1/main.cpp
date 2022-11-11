#include <stdio.h>
#include <stdlib.h>
#include "include/list.h"
#include "include/dump.h"

/*
gcc -g -Wextra -Wall -Wpedantic -fsanitize=address -c main.cpp src/list.cpp src/dot.cpp src/dump.cpp
gcc -g -Wextra -Wall -Wpedantic -fsanitize=address -o a main.o list.o dot.o dump.o
*/

int main()
{
    list lst = {};
    list_ctor(&lst);
    int num = 41, step = 3;

    for(int i = 1; i <= num; i++)
        list_insert_head(&lst, i);
    list_dump(&lst);

    while(lst.size > 1)
    {
        list_delete_tail(&lst);

        for(int j = 0; j < step - 1; j++)
        {
            lst.tail = (lst.tail)->next;
        }
    }
    list_dump(&lst);
    list_dtor(&lst);
    return 0;
}