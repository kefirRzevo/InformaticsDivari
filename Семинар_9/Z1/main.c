#include <stdio.h>


int main()
{
    //indent -kr --no-tab a.c
    char c = 'a';

    printf("_________________\n");
    while(c <= 'z')
    {
        printf("|%c\t|%d\t|\n", c, c);
        c++;
    }
    printf("|_______|_______|");
    return 0;
}