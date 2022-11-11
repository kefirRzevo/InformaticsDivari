#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main()
{
    srand(time(NULL));
    FILE *fp = fopen ("file.txt", "w+");

    for(int i = 0; i < 10; i++)
    {
        double a = rand() % 1000 - 500;
        a/=17;
        fprintf(fp, "%.2lf ", a);
    }

    scanf("%*d");
    fseek(fp, 0L, SEEK_SET);

    for(int i = 0; i < 10; i++)
    {
        double a = 0;
        fscanf(fp, "%lf", &a);
        printf("%.2lf ", a);
    }
        
    return 0;
}