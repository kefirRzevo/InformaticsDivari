#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int sum = 0;
    char s[50];
    gets(s);
    char *prev_space = &s[0] - 1;
    char *next_space = &s[0];
    int num_dig = 0;
    s[strlen(s)] = ' ';
    for(int i = 0; i <= strlen(s); i++)
    {
        if(isdigit(s[i]))
        {
            num_dig++;
            continue;
        }
        if(isspace(s[i]))
        {
            next_space = &s[i];
            if(next_space - prev_space - 1 == num_dig)
            {
                sum += (int) atoi(prev_space);
            }
            prev_space = &s[i];
            num_dig = 0;
        }
    }
    printf("The sum is %d\n", sum);
    return 0;
}