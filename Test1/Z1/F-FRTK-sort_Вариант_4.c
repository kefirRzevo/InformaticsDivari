#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max 100

typedef struct _num
{
    char dig[max];
    unsigned int size;
} num;

int comparator (const void * a, const void * b)
{
    if(((num*)a)->size > ((num*)b)->size)
        return 1;
    else
        return strcmp(((num*)b)->dig, ((num*)a)->dig);
}

int main(void) 
{
    unsigned int n;
    scanf("%d", &n);

    num* mas = (num *)calloc(n, sizeof(num));
    for(int i = 0; i < n; i++)
    {
        scanf("%s", mas[i].dig);
        mas[i].size = strlen(mas[i].dig);
        mas[i].dig[mas[i].size] = '\0';
    }
    qsort(mas, n, sizeof(num), comparator);
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < mas[i].size; j++)
            printf("%d", mas[i].dig[j] - '0');
        printf("\n");
    }
    free(mas);
    return 0;
}