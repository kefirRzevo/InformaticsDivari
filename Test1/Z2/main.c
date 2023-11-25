#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


void normalize_path(char* path)
{
    char* temp = strdup(path);
    int n = strlen(temp);
    char* iterator = path;

    for(int i = 0; i < n; i++)
    {
        char ch;
        bool check = false;
    
        if(temp[i] == '/' && temp[i + 1] == '/' && i < n - 1)
        {
            for(int j = i; j < n - 1; j++)
                temp[j] = temp[j+1];
            n--;
            temp[n] = '\0';
            i--;
        }
        if(temp[i] == '.' && temp[i + 1] == '.' && temp[i + 2] =='/' && i < n - 2)
        {
            for(int j = i; j < n - 3; j++)
                temp[j] = temp[j + 3];
            n-=3;
            temp[n] = '\0';
            i-=1;
            if(temp[i] == '/')
            {
                //printf("===\n");
                i--;
                int step = 1;
                while(temp[i]!='/')
                {
                    i--;
                    step++;
                }
                for(int j = i; j < n - step; j++)
                    temp[j] = temp[j+step];
                n-=step;
                temp[n] = '\0';
                i--;
            }
        }
        if(temp[i] == '.' && temp[i + 1] == '/' && temp[i-1] != '.' && i < n - 1)
        {
            for(int j = i; j < n - 2; j++)
                temp[j] = temp[j+2];
            n-=2;
            temp[n] = '\0';
            i-=1;
        }
    }

    for(int i = 0; i <= n; i++)
    {
        *iterator = temp[i];
        iterator++;
    }
        //printf("%s\n", temp);
    free(temp);
}

int main()
{
    char str[100] = "abra///abc";
    normalize_path(str);
    printf("%s\n", str);
    return 0;
}