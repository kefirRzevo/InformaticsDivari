#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"
#include <time.h>
#include "../Z3/stack/include/stack.h"


/*
    gcc -c  ../Z3/stack/src/stack.c
    gcc -c  main.c
    gcc -o a.exe main.o stack.o 
    ./a.exe 
*/

int main()
{
    srand(time(NULL));
    int n;
    printf("Enter massiv's size \n");
    scanf("%d", &n);

    int* mas = generate (n);
    stack stk = {};
    StackCtor(&stk);
    StackDump(&stk);
    for(int i = n - 1; i >= 0; i--)
    {
        int r = 0;   
        int j = i;
        for(int j = i; j < n; j++)
        {
            if(mas[j] > mas[i])
                break;
            else 
                r++;
        }
        if(r == n - i)
        {
            StackPush(&stk, -1);
            continue;
        }
        StackPush(&stk, r);
    }
    StackDump(&stk);
    int k;
    for(int i = 0; i < n; i++)
    {
        StackPop(&stk, &k);
        printf("%-4d", k);
    }
    printf("\n");
    StackDump(&stk);
    StackDtor(&stk);
    return 0;
}