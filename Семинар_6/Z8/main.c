#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int n;
    printf("Enter massiv's size \n");
    scanf ("%d", &n);
    bool* bool_mas = (bool *) calloc(10000, sizeof(bool));

    for (int i = 0; i < n; i++)
    {
        int a = rand() % 10000;
        printf("%d ", a);
        bool_mas[a] = 1;
    }

    printf("\n");

    for(int i = 0; i < 10000; i++)
    {
        if(bool_mas[i] == 1)
            printf("%d ", i);
    }
    return 0;
}