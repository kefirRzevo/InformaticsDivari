#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];
    scanf("%s%*c%s%*c", s1, s2);
    strncpy(s1 + 4, s2 + 1, 3);
    printf("%s\n%s\n", s1, s2);
    return 0;
}