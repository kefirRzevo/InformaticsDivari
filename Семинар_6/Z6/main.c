#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
    char* mas = (char *) calloc(n, sizeof(char)); 

    for (int i = 2; i*i <= n; i++)
        if(mas[i] == 0)
            for(int j = i*i; j <= n; j+=i)
                mas[j] = 1;

    for(int i = 2; i < n; i++)
        if(mas[i] == 0)
            printf("%d ", i);

    free(mas);
    return 0;
}