#include <stdio.h>
#include <string.h>

int main()
{
    printf("Enter strings: \n");
    char s1[100], s2[100];
    scanf("%s%*c%s%*c", s1, s2);

    char* p = strpbrk(s1, s2);   
    if(!p)
        printf("Symbal isn't found!\n");
    else
    {
        *(char*)p = '*';
        printf("New string: \n");
        printf("%s\n", s1);
    }
    return 0;
}