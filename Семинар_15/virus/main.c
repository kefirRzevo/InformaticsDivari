#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sum   = 0;
int max   = 0;
int n     = 0;
char* mas = NULL;

void deep(int x, int prev)
{
    if(x > max)
        return;

    int a = x;
    int b = prev;

    while(x < max)
    {
        char temp = *(mas + sizeof(char)*( (int)( x/8) ));

        if((temp & (1 << (7 - (x%8) ) ) ) )
        {
            break;
        }

        temp |= (1 << (7 - (x % 8) ) );
        *(mas + sizeof(char)*( (int)( x / 8) )) = temp;
        sum++;
        int h = x;
        x = 2 * x - prev + 1;
        prev = h;
    }

    deep(2 * a - b + 1, a);
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &max);

    mas = (char* )calloc( (int)(max / 8) + 1, sizeof(char));
    for(int i = 0; i < n; i++)
    {
        int d = 0;
        scanf("%d", &d);
        deep(d, 1);
    }
    printf("%d", sum);
    free(mas);
    return 0;
}