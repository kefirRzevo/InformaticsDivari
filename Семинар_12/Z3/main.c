#include <stdio.h>
#include <stdlib.h>
#include "stack/include/stack.h"


int main() 
{
   struct stack stk = {};
   struct stack stk1 = {};
   StackCtor(&stk);
   StackPush(&stk, 11);
   StackPush(&stk, 13);
   StackPush(&stk, 17);
   StackPush(&stk, 23);
   StackCtor(&stk1);
   StackPush(&stk, 29);
   StackCtor(&stk1);
   int a = 0;
   StackPush(&stk, 31);
   StackPop(&stk, &a);
   printf("%d", a);
   StackGet(&stk, &a);
   printf("%d", a);
   StackDump(&stk);
   StackDtor(&stk);
   StackCtor(&stk1);
   return 0;
   ///сначала     gcc -c  stack/src/stack.c
   ///потом       gcc -o a.exe main.o stack.o 
   ///еще потом   ./a.exe 
}