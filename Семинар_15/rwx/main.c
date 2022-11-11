#include <stdio.h>

size_t st(size_t i, size_t j)
{
    if(i == 0)
    {
        return 1;
    }
    else 
    {
        i = j * st(i - 1, j);
        return i;
    }
}

int main()
{
    size_t a = 0;
    scanf("%zu", &a);
    size_t i = 0;

    for(i = 0; i < 3; i++)
    {
        size_t x = (a / st(2 - i, 10) ) % 10 ;

        size_t y1 = x / st(2, 2);
        switch(y1)
        {
            case 1: 
                printf("r");
                break;
            case 0: 
                printf("-");
                break;
        }
        x = x - y1 * st(2, 2);

        size_t y2 = x / st(1, 2);
        switch(y2)
        {
            case 1: 
                printf("w");
                break;
            case 0: 
                printf("-");
                break;
        }
        x = x - y2 * st(1, 2);
   
        size_t y3 = x / st(0, 2);
        switch(y3)
        {
            case 1: 
                printf("x");
                break;
            case 0: 
                printf("-");
                break;
        }
    }

    return 0;
}