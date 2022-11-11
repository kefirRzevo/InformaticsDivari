#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max 110

typedef struct _num
{
    char dig[max];
    unsigned int size;
} num;

int comparator (const void * a, const void * b)
{
    if( ((num*)a)->dig[0] != '-' && ((num*)b)->dig[0]=='-' )
        return 1;

    else if(  ((num*)a)->dig[0]=='-' && ((num*)b)->dig[0] !='-' )
        return -1;

    else if(  ((num*)a)->dig[0]!='-' && ((num*)b)->dig[0] != '-')
    {
        if(   ((num*)a)->size > ((num*)b)->size )
            return 1;
        else if(   ((num*)a)->size < ((num*)b)->size )
            return -1; 
        else
            return strcmp( ((num*)a)->dig, ((num*)b)->dig);
    }  

    else if(  ((num*)a)->dig[0]=='-' && ((num*)b)->dig[0] == '-')
    {
        if(   ((num*)a)->size > ((num*)b)->size )
            return -1;
        else if(   ((num*)a)->size < ((num*)b)->size )
            return 1;
        else
            return strcmp(((num*)b)->dig, ((num*)a)->dig);
    }
    else
        return 0;
}


int main() 
{
    unsigned int n;
    scanf("%d", &n);

    num* mas = (num *)calloc(n, sizeof(num));
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%s", mas[i].dig);
        mas[i].size = strlen(mas[i].dig);
        mas[i].dig[mas[i].size] = '\0';
    }
    qsort(mas, n, sizeof(num), comparator);
    if(n > 1)
    {
        for(i = 0; i < n - 1; i++)
        {
            if(mas[i].dig[0] == '-')
            {
                printf("-");
                for(j = 1; j < strlen(mas[i].dig); j++)
                    printf("%d", (mas[i].dig[j]) - '0');
            }
            else
            {
                for(j = 0; j < strlen(mas[i].dig); j++)
                    printf("%d", (mas[i].dig[j]) - '0');
            }
            printf("\n");
        }
    }

    if(mas[n - 1].dig[0] == '-')
    {
        printf("-");
        for(j = 1; j < strlen(mas[n - 1].dig); j++)
            printf("%d", (mas[n - 1].dig[j]) - '0');
    }
    else
    {
        for(j = 0; j < strlen(mas[n - 1].dig); j++)
            printf("%d", (mas[n - 1].dig[j]) - '0');
    }

    free(mas);
    return 0;
}