#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


#define SPECIFICATOR "d"


typedef char item_t;


typedef struct stack
{
    item_t* data;
    int size;
    int capacity;
}stack;


enum Check
{
    SUCCESS                         = 0,
    ERROR_STACK_UNITIALIZED         = 1,
    ERROR_STACK_REINITIALIZATION    = 2,
    ERROR_STACK_IS_EMPTY            = 3,
    ERROR_UNALLOCATED_MEMORY        = 4,
    STACK_CANARY_BAD                = 5,
    STACK_CANARY_OK                 = 6,
    STACK_CANARY_STACK_UNITIALIZED  = 7,
    OPEN_LOG_FILE_ERROR             = 8
};


enum Check StackCtor(struct stack *const p_stack);

enum Check StackDtor(struct stack *const p_stack);

enum Check StackPush(struct stack *const p_stack, const item_t element);
 
enum Check StackPop(struct stack *const p_stack, item_t *const p_element);

enum Check StackGet(struct stack *const p_stack, item_t *const p_element);

enum Check StackDump(const struct stack *const p_stack);

bool       StackEmpty(struct stack *const p_stack);