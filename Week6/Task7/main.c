#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

int main()
{
    int n;
    printf("Enter massiv's size \n");
    scanf("%d", &n);
    printf("Enter elements\n");

    int mas[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &mas[i]);
    } 
    print(mas, n);


    if(check(mas, n))
        printf("Massiv is ordered, p = %d\n", mult_differ(mas, n));
    else
        printf("Massiv isn't ordered, p = %d\n", violation_order(mas, n));
    return 0;
}