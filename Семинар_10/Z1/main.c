#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen ("input.txt", "r");
    FILE *fq = fopen ("output.txt", "w");
    int mas[10];

    for(int i = 0; i < 10; i++)
        fscanf(fp, "%d", &mas[i]);
    for(int i = 0; i < 10; i++)
        fprintf(fq, "%d ", mas[i]);
        
    return 0;
}