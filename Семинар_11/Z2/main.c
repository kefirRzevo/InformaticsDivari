#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare( const void *x1, const void *x2)
{
	return *(int*)x1 - *(int*)x2;
}

int main()
{
    srand(time(NULL));
    FILE *fp = fopen ("file.txt", "w+");
    int mas[100] = {};
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            mas[5 * i + j] = rand() % 1000 - 500;
            fprintf(fp, "%4d    ", mas[5 * i + j]);
        }
        fprintf(fp, "\n");
    }

    qsort(mas, 100, sizeof(int), compare);

    fprintf(fp, "\n");
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            fprintf(fp, "%4d    ", mas[5 * i + j]);
        }
        fprintf(fp, "\n");
    }
    return 0;
}