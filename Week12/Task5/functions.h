#include <stdio.h>
#include <stdlib.h>


void print(int a[], int size);
int* generate(int n);


void print(int a[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%-4d", a[i]);
    printf("\n");
}

int* generate(int n)
{
    int* mas = (int *) calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        mas[i] = rand() % 30 + 10;
    }
    print(mas, n);
    return mas;
}