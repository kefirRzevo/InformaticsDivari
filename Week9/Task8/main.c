#include <stdio.h>
#include <string.h>

int main()
{
    printf("Enter strings: \n");
    char s1[100], s2[100];
    scanf("%s%*c%s%*c", s1, s2);

    char* p = strstr(s1, s2);   
    if(!p)
        printf("String doesn't get in!\n");
    else
    {
        strncpy(p, &s2[0], strlen(s2));
        s1[strlen(s1) - strlen(s2)] = '\0';
        printf("New string: \n");
        printf("%s\n", s1);
    }
    return 0;
}