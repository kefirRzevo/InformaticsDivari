#include <stdio.h>
#include <string.h>

int main()
{
    char s1[80], s2[80];
    gets (s1);
    gets (s2);
    strcat(s2, s1);
    printf("%s %lu", s2, strlen(s2));
    return 0;
}