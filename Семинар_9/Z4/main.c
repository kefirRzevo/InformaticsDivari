#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];

    scanf("%s%*c%s%*c", s1, s2);
    if(strncmp (s1, s2, 3))
        printf("False\n");
    else
    printf("True\n");
    return 0;
}