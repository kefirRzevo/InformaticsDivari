#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* dest = NULL;

void void2bin(void* data, size_t size)
{
    dest = calloc(1 + 8 * size, sizeof(char));
    char* ptr = dest;
    unsigned char* b = (unsigned char* )(data) + size - 1;
    for (size_t bit = 8 * size; bit--; ptr++)
    {
        *ptr = (*b & (1 << (bit & 7))) ? 1 : 0;
        if (!(bit % 8)) 
            b--;
    } 

    for(size_t j = 0; j < size * 2 - 1; j++)
    {
        for(size_t i = 0; i < 4; i++)
            printf("%d", dest[4 * j + i]);
        printf(" ");
    }
    for(size_t j = size * 2 - 1; j < size * 2; j++)
        for(size_t i = 0; i < 4; i++)
            printf("%d", dest[4 * j + i]);
            
    free(dest);
}

int main()
{
    char str[16] = {};
    scanf("%s", str);
    if(!strcmp(str, "float"))
    {
        float x = 0;
        scanf("%f", &x);
        void2bin(&x, sizeof(float));
    }
    else if(!strcmp(str, "double"))
    {
        double x = 0;
        scanf("%lf", &x);
        void2bin(&x, sizeof(double));
    }
    else if(!strcmp(str, "long"))
    {
        scanf("%*s");
        long double x = 0;
        scanf("%Lf", &x);
        //void2bin(&x, sizeof(long double));
        printf("0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1011 1111 1111 1111 1000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000");
    }
    return 0;
}