#include <stdio.h>
#include <string.h>

int main()
{
    char c1, c2;
    char s1[100], s2[100];

    scanf("%s%*c", s1);
    printf("%s\n", s1);

    c1 = getchar();
    putchar(c1);
    printf("\n");
    fflush(stdin);
 
    fgets(s2, 100, stdin);
    fflush(stdin);
    c2 = getchar();
    puts(s2);
    putchar(c2);
    return 0;
}