#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen ("file.txt", "w+");

    char s[] = "1 2 3 4 5 6 700.7 80 9 0";
    fprintf(fp, "%s", s);
    fseek(fp, 0L, SEEK_SET);

    printf("Numbers: ");
    for(int i = 0; i < 10; i++)
    {
        double a = 0;
        fscanf(fp, "%lf", &a);
        printf("%g ", a);
    }

    fseek(fp, 0L, SEEK_END);
    int sum = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    printf("\nNumber of bights: %d\n", sum);

    printf("Numbers without first 3: ");
    fscanf(fp, "%*d%*d%*d");
    for(int i = 0; i < 7; i++)
    {
        double a = 0;
        fscanf(fp, "%lf", &a);
        printf("%g ", a);
    }
    printf("\n");
    
    return 0;
}