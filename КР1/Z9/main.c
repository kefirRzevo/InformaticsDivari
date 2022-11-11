#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE* fp = fopen("edist.dat", "r");
    FILE* fq = fopen("edist.ans", "w");
    int n1   = 0, n2 = 0, n3 = 0, n4 = 0, n5 = 0;

    fscanf(fp, "%d", &n1);
    int* mas1 = (int *)calloc(n1, sizeof(int));
    for(int i = 0; i < n1; i++)
        fscanf(fp, "%d", &mas1[i]);

    fscanf(fp, "%d", &n2);
    int* mas2 = (int *)calloc(n2, sizeof(int));
    for(int i = 0; i < n2; i++)
        fscanf(fp, "%d", &mas2[i]);

    int* mas5 = NULL;
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n2; j++)
        {
            if(mas1[i] == mas2[j])
            {
                n5++;
                mas5         = (int *)realloc(mas5, n5 * sizeof(int));
                mas5[n5 - 1] = mas2[j];
                break;
            }
        }

    int* mas3 = NULL;
    for(int i = 0; i < n1; i++)
        for(int j = 0; j < n5; j++)
        {
            if(mas1[i] == mas5[j])
            {
                n3++;
                mas3         = (int *)realloc(mas3, n3 * sizeof(int));
                mas3[n3 - 1] = mas1[i];
                break;
            }
        }

    int* mas4 = NULL;
    for(int i = 0; i < n2; i++)
        for(int j = 0; j < n5; j++)
        {
            if(mas2[i] == mas5[j])
            {
                n4++;
                mas4         = (int *)realloc(mas4, n4 * sizeof(int));
                mas4[n4 - 1] = mas5[j];
                break;
            }
        }

    printf("\n1: ");
    for(int i = 0; i < n1; i++)
        printf("%d ", mas1[i]);
    printf("\n2: ");
    for(int i = 0; i < n2; i++)
        printf("%d ", mas2[i]);
    printf("\n3: ");
    for(int i = 0; i < n3; i++)
        printf("%d ", mas3[i]);
    printf("\n4: ");
    for(int i = 0; i < n4; i++)
        printf("%d ", mas4[i]);
    printf("\n5: ");
    for(int i = 0; i < n5; i++)
        printf("%d ", mas5[i]);
    printf("\n");
    
    int sum = 0;
    if(n4 > n3)
        for(int i = 0, j = 0; i < n4 || j < n3;)
        {
            if(mas4[i] == mas3[j])
            {
                sum+=mas4[i];
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
    else
        for(int j = 0, i = 0; j < n4 || i < n3;)
        {
            if(mas3[j] == mas4[i])
            {
                sum+=mas3[j];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
    fprintf(fq, "%d", sum);

    fclose(fp);
    fclose(fq);
    free(mas1);
    free(mas2);
    free(mas3);
    free(mas4);
    free(mas5);
    return 0;
}