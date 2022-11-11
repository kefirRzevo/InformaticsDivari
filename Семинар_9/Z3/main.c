#include <stdio.h>
#include <string.h>

struct _str
{
    char s[70];
    int  a;
    char t;
};
typedef struct _str str;

int main()
{
    str mas[2];

    for(int i = 0; i < 2; i++)
    {
        scanf("%s%*c%d%*c%c", mas[i].s, &mas[i].a, &mas[i].t);
    }

    for(int i = 0; i < 2; i++)
    {
        printf("\n");
        puts(mas[i].s);
        printf("%d\n", mas[i].a);
        printf("%c\n", mas[i].t);
    }

    return 0;
}