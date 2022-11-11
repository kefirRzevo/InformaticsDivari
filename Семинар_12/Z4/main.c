#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define SPECIFICATOR "c"


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


FILE *LOG_FILE = NULL;
const int INITIAL_CAPACITY = 1;
bool STATUS_OPEN_LOG_FILE  = false;


#define open_log_file                               \
    if(STATUS_OPEN_LOG_FILE == false)               \
        LOG_FILE = fopen ("log_file.txt", "w");     \
                                                    \
    if(!LOG_FILE)                                   \
    {                                               \
        printf("OPEN_LOG_FILE_ERROR");              \
        return OPEN_LOG_FILE_ERROR;                 \
    }                                               \
    STATUS_OPEN_LOG_FILE = true            



#define SUCCESS                         fprintf(LOG_FILE, "STACK ADDRESS: %8p %-9s SUCCESS                     \n", p_stack, __func__); \
return      SUCCESS

#define ERROR_STACK_IS_EMPTY            fprintf(LOG_FILE, "STACK ADDRESS: %8p %-9s ERROR_STACK_IS_EMPTY        \n", p_stack, __func__); \
return      ERROR_STACK_IS_EMPTY

#define ERROR_STACK_UNITIALIZED         fprintf(LOG_FILE, "STACK ADDRESS: %8p %-9s ERROR_STACK_UNITIALIZED     \n", p_stack, __func__); \
return      ERROR_STACK_UNITIALIZED

#define ERROR_STACK_REINITIALIZATION    fprintf(LOG_FILE, "STACK ADDRESS: %8p %-9s ERROR_STACK_REINITIALIZATION\n", p_stack, __func__); \
return      ERROR_STACK_REINITIALIZATION

#define ERROR_UNALLOCATED_MEMORY        fprintf(LOG_FILE, "STACK ADDRESS: %8p %-9s ERROR_UNALLOCATED_MEMORY    \n", p_stack, __func__); \
return      ERROR_UNALLOCATED_MEMORY


bool  realloc_stack(struct stack *const p_stack, int capacity);



enum Check StackCtor(struct stack *const p_stack)
{
    open_log_file;
    
    assert(p_stack);

    if(p_stack->size     != 0  ||
       p_stack->capacity != 0  ||    
       p_stack->data != NULL) 
    {
        ERROR_STACK_REINITIALIZATION;
    }

    item_t *data = NULL;
    data = (item_t *) calloc(INITIAL_CAPACITY, sizeof(item_t));
    
    if(data == NULL)
    {
        ERROR_UNALLOCATED_MEMORY;
    }


    p_stack->size      = 0;
    p_stack->capacity  = INITIAL_CAPACITY;
    p_stack->data      = data;
    SUCCESS;
} 


enum Check StackDtor(struct stack *const p_stack)
{
    open_log_file;

    assert(p_stack);
    
    if(p_stack->data == NULL)
    {
        ERROR_STACK_UNITIALIZED;
    }


    free((void *)p_stack->data);
    p_stack->size        = 0;
    p_stack->capacity    = 0;
    p_stack->data        = NULL;

    SUCCESS;
}


enum Check StackPush(struct stack *const p_stack, const item_t element)
{
    open_log_file;

    assert(p_stack);

    if(p_stack->data == NULL)
    {
        ERROR_STACK_UNITIALIZED;
    }

    if(p_stack->size == p_stack->capacity)
    {
        int new_capacity = p_stack->capacity * 2;
        if(realloc_stack(p_stack, new_capacity) == false)
        {
            ERROR_UNALLOCATED_MEMORY;
        }
        p_stack->capacity = new_capacity;
    }


    item_t *data = p_stack->data;
    
    data[p_stack->size] = element;
    p_stack->size++;

    SUCCESS;
}


enum Check StackPop(struct stack *const p_stack, item_t *const p_element)
{
    open_log_file;

    assert(p_stack);
    assert(p_element);
    if(p_stack->data == NULL)
    {
        ERROR_STACK_UNITIALIZED;
    }

    if(p_stack->size == 0)
    {
        ERROR_STACK_IS_EMPTY;
    }

    item_t *data = p_stack->data;
    *p_element = data[p_stack->size - 1];
    p_stack->size--;
    if(p_stack->capacity == 2 * p_stack->size)
    {
        int new_capacity = p_stack->capacity / 2;
        if(realloc_stack(p_stack, new_capacity) == false)
        {
            ERROR_UNALLOCATED_MEMORY;
        }
        p_stack->capacity = new_capacity;
    }
    SUCCESS;
}


enum Check StackGet(struct stack *const p_stack, item_t *const p_element)
{
    open_log_file;

    assert(p_stack);
    assert(p_element);

    if(p_stack->data == NULL)
    {
        ERROR_STACK_UNITIALIZED;
    }

    if(p_stack->size == 0)
    {
        ERROR_STACK_IS_EMPTY;
    }

    item_t *data = p_stack->data;

    *p_element = data[p_stack->size - 1];

    SUCCESS;
}


enum Check StackDump(const struct stack *const p_stack)
{
    open_log_file;

    assert(p_stack);

    if(p_stack->data == NULL)
    {
        ERROR_STACK_UNITIALIZED;
    }

    const char OK[]  = "OK";
    const char BAD[] = "BAD";

    bool check_size     = p_stack->size     <= p_stack->capacity  && p_stack->size >= 0;
    bool check_capacity = p_stack->capacity >= p_stack->size      && p_stack->capacity > 0;
    bool check_adress   = p_stack       != NULL;
    bool check_data     = p_stack->data != NULL;

    
    item_t *data = p_stack->data;
    
    fprintf (LOG_FILE, "\n| Stack information:                  |\n"
               "| address:           %-14p%3s|\n"
               "| size:              %-14d%3s|\n"
               "| capacity:          %-14d%3s|\n"
               "| data:              %-14p%3s|\n"

        
,
        p_stack,                  check_adress            ? OK : BAD,
        p_stack->size,            check_size              ? OK : BAD,
        p_stack->capacity,        check_capacity          ? OK : BAD,
        p_stack->data,            check_data              ? OK : BAD
);


    for(int i = 1; i <= p_stack->size; i++)
        fprintf(LOG_FILE, "| *%d:\t%10" SPECIFICATOR " |\n", i, data[i - 1]);

    for(int i = p_stack->size + 1; i <= p_stack->capacity; i++)
        fprintf(LOG_FILE, "|  %d:\t%10" SPECIFICATOR " |\n", i, data[i - 1]);
    
    fprintf(LOG_FILE, "\n");

    SUCCESS;
}


bool realloc_stack(struct stack *const p_stack, int new_capacity)
{
    assert(p_stack);

    const item_t *const data = (item_t *)p_stack->data;

    item_t *p_new_elements = (item_t *) realloc ((void *)data, new_capacity * sizeof(item_t));
    

    if(p_new_elements == NULL)
        return false;

    p_stack->data = p_new_elements;

    return true;
}


bool StackEmpty(struct stack *const p_stack)
{
    return(p_stack->size == 0);
}


int
main()
{
   FILE*  fp   = fopen("input.txt", "r");
   stack  stk  = {};
   item_t item = 0;
   
   StackCtor(&stk);
   
   fseek(fp, 0L, SEEK_END);
   int size = ftell(fp);
   fseek(fp, 0L, SEEK_SET);

   char *text = (char*)calloc(size, sizeof(char));
   int n = fread(text, sizeof(char), size, fp);
   int i = 0;
   
   for (i = 0; i < n; i++)
   {
      if (text[i] == '(' || text[i] == '[' || text[i] == '{' || text[i] == '<')
         StackPush(&stk, text[i]);
      else if (text[i] == ')' || text[i] == ']' || text[i] == '}' || text[i] == '>')
      {
         StackPop(&stk, &item);
   
         switch (text[i])
         {
            case ')':
            {
               if (item != '(')
               {
                  printf("Bad expression.\n");
                  StackDtor(&stk);
                  abort();
               }
               
               break;
            }
   
            case ']':
            {
               if (item != '[')
               {
                  printf("Bad expression.\n");
                  StackDtor(&stk);
                  abort();
               }
   
               break;
            }
   
            case '}':
            {
               if (item != '{')
               {
                  printf("Bad expression.\n");
                  StackDtor(&stk);
                  abort();
               }
   
               break;
            }
   
            case '>':
            {
               if (item != '<')
               {
                  printf("Bad expression.\n");
                  StackDtor(&stk);
                  abort();
               }
   
               break;
            }
         }
      }
   }

   if (StackEmpty(&stk))
      printf("Good expression.\n");
   else
   {
      printf("Bad expression.\n");
      abort();
   }
   
   StackDtor(&stk);
   fclose(fp);
   
   return 0;
}