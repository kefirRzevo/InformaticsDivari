#include <stdio.h>
#include <string.h>


int main()
{
    unsigned char mas = 0;

    char temp[3] = {};
    for(int i = 0; i < 8; i++)
    {
        scanf("%s", temp);
        if(!strcmp(temp, "ma"))
            mas |= 1 << 0;
        else if(!strcmp(temp, "cl"))
            mas |= 1 << 1;
        else if(!strcmp(temp, "ha"))
            mas |= 1 << 2;
        else if(!strcmp(temp, "tr"))
            mas |= 1 << 3;
        else if(!strcmp(temp, "rd"))
            mas |= 1 << 4;
        else if(!strcmp(temp, "bw"))
            mas |= 1 << 5;
        else if(!strcmp(temp, "bk"))
        {
            mas |= 1 << 4;
            mas |= 1 << 5;
        }
        else if(!strcmp(temp, "ge"))
            mas |= 1 << 6;
        else if(!strcmp(temp, "gy"))
            mas |= 1 << 7;
        else if(!strcmp(temp, "da"))
        {
            mas |= 1 << 6;
            mas |= 1 << 7;
        }
    }
    printf("%x", mas);

    return 0;
}