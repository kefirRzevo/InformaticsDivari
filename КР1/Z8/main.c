#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int t = n - 1;
    while(k > n && t >=0)
    {
        if(k <= ((int)pow(2, t + 1) + n - t - 2) && k >= ((int)pow(2, t) + n - t))
        {
            k = k - (int)pow(2, t) + 1;
        }
        else
        {
            t--;
        }
    }
    k = n - k;
    printf("%c", k + 'a');
    return 0;
}