#include <stdio.h>
#include <string.h>

int main()
{
    char s[100];
    printf("Enter string: ");
    scanf("%s%*c", s);
    char c;
    printf("Enter symbal: ");
    scanf("%c", &c);

    char* p = strchr(s, c);   
    if(!p)
        printf("Symbol not found!");
    else
    {
        *(char*) p = '*';
        p = strrchr(s, c);
        *(char*) p = '*';
    }
    printf("%s\n", s);
    return 0;
}