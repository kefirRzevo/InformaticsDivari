#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare( const void *x1, const void *x2)
{
	return *(double*)x1 - *(double*)x2;
}

int main()
{
    srand(time(NULL));
    FILE *fp = fopen ("file.txt", "w+");
    double mas[100] = {};
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mas[5 * i + j] = (rand() % 10000 - 5000) * 0.01;
            fprintf(fp, "%6.2lf    ", mas[5 * i + j]);
        }
        fprintf(fp, "\n");
    }

    qsort(mas, 100, sizeof(double), compare);

    fprintf(fp, "\n");
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            fprintf(fp, "%6.2lf    ", mas[5 * i + j]);
        }
        fprintf(fp, "\n");
    }
    return 0;
}