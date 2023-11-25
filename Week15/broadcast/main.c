#include <stdio.h>

int main()
{
    unsigned char mas1[4] = {}, mas2[4] = {}, mas3[4] = {};
    scanf("%hhu.%hhu.%hhu.%hhu", &mas1[0], &mas1[1], &mas1[2], &mas1[3]);
    scanf("%hhu.%hhu.%hhu.%hhu", &mas2[0], &mas2[1], &mas2[2], &mas2[3]);

    unsigned int x = 0, y = 0, z = 0;
    x = mas1[0];
    x = x << 8;
    x = x | mas1[1];
    x = x << 8;
    x = x | mas1[2];
    x = x << 8;
    x = x | mas1[3];
  
    y = mas2[0];
    y = y << 8;
    y = y | mas2[1];
    y = y << 8;
    y = y | mas2[2];
    y = y << 8;
    y = y | mas2[3];
         
    z = (x & y) |  ~y;

    mas3[0] = z;
    mas3[1] = (z >> 8);
    mas3[2] = (z >> 16);
    mas3[3] = (z >> 24);
    printf("%hhu.%hhu.%hhu.%hhu", mas3[3], mas3[2], mas3[1], mas3[0]);

    return 0;
}