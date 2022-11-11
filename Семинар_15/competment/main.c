#include <stdio.h>

int main()
{
    char c = 0;
    scanf("%hhd", &c);
    for(int i = 0; i < 8; i++)
        printf("%d", (c >> (7 - i) ) & 1);
    return 0;
}