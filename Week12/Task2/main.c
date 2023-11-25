#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"


int main()
{
    int n, b;
    printf("Enter massiv's size \n");
    scanf("%d", &n);

    printf("Enter number \n");
    scanf("%d", &b);

    int* mas = generate(n);
    int i = search(b, mas, n);
    printf("Index is: %d\n", i);
    free(mas);
    return 0;
}