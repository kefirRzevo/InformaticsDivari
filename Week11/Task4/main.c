#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>


int compare( const void *x1, const void *x2)
{
    return *(char*)x1 - *(char*)x2;
}

int main()
{
    FILE *fp = fopen ("output.txt", "w+");
    
    char mas[1000] = {};
    unsigned int i = 0;
    while(mas[i] != '.')
    {
        i++;
        scanf("%c", &mas[i]);
    }

    qsort(mas, i - 1, sizeof(char), compare);
    mas[i] = '.';

    for(int j = 1; j <= i; j++)
    {
        fprintf(fp, "%c", mas[j]);
    }
    return 0;
}