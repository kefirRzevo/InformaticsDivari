#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"


int main()
{
    int n1, n2;
    printf("Enter massiv's sizes \n");
    scanf("%d %d", &n1, &n2);

    int* mas1 = generate (n1);
    int* mas2 = generate (n2);
    int* mas3 = (int *) calloc(n1 + n2, sizeof(int));

    for(int i = 0, j = 0, k = 0; k < n1 + n2; )
    {
        if((i < n1) && (j < n2))
        {
            if(mas2[j] <= mas1[i])
            {
                // printf("\n 2>1 %d %d \n", mas2[j], mas1[i]);
                mas3[k] = mas2[j];
                j++;
                k++;
                continue;
            }
            else
            {
                // printf("\n 1<2 %d %d \n", mas1[i], mas2[j]);
                mas3[k] = mas1[i];
                i++;
                k++;
                continue;
            }
        }
        if((i >= n1) && (j < n2))
        {
            mas3[k] = mas2[j];
            j++;
            k++;
            continue;
        }
        if((j >= n2) && (i < n1))
        {
            mas3[k] = mas1[i];
            i++;
            k++;
            continue;
        }
    }
    print(mas3, n1 + n2);
    free(mas1);
    free(mas2);
    free(mas3);
    return 0;
}