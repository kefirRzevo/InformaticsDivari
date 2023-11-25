#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    FILE *fp = fopen ("input.txt", "r");
    FILE *fq1 = fopen ("output1.txt", "w+");
    FILE *fq2 = fopen ("output2.txt", "w+");

    for(int i = 0; i < 20; i++)
    {
        for(int i = 0; i < 5; i++)
        {
            int a = rand() % 1000 - 500;
            fprintf(fp, "%4d    ", a);
        }
        fprintf(fp, "\n");
    }
    fseek(fp, 0L, SEEK_SET);

    for(int i = 0; i < 20; i++)
    {
        int a = 0, b = 0;
        fscanf(fp, "%*d%*d%d%*d%d", &a, &b);
        fprintf(fq1, "%4d    %4d\n", a, b);
    } 
    fseek(fp, 0L, SEEK_SET);  

    int l1 = 12;
    int l2 = 17;
    fscanf(fp, "%*d%*d");
    for(int i = 0; i < 20; i++)
    {
        int a = 0, b = 0;
        fscanf(fp, "%d", &a);
        fprintf(fq2, "%4d    ", a);
        fseek(fp, l1, SEEK_CUR);
        fscanf(fp, "%d", &a);
        fprintf(fq2, "%4d\n", a);
        fseek(fp, l2, SEEK_CUR);
    } 
    return 0;
}