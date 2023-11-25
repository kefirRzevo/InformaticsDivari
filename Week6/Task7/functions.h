#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void print(int a[], int size);
int mult_differ (int mas[], int n);
int violation_order (int mas[], int n);
bool check (int mas[], int n);


void print(int a[], int size)
{
    for(int i = 0; i < size; i++)
    printf("%d ", a[i]);
    printf("\n");
}


int mult_differ (int mas[], int n)
{
    int p = 1;
    if(n > 1)
    {
        for(int i = 0; i < n - 1; i++)
            p*= mas[i+1] - mas[i]; 
        return p;
    }
    else
        return mas[0];
}

int violation_order (int mas[], int n)
{
    int p = 0;
    for(int i = 0; i < n - 1; i++)
        if(mas[i+1] < mas[i])
            p++;
    return p;
}

bool check (int mas[], int n)
{
    for(int i = 0; i < n - 1; i++)
        if(mas[i+1] <= mas[i])
                return false;
    return true;
}