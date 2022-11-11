#include <stdio.h>
#include <stdlib.h>


int main (int argc, char * argv[])
{
    int sum = 0;
    printf("Argument 0: %s\n", argv[0]);

    for(int i = 1; i < argc; i++) 
    {
        printf("Argument %d: %s\n", i, argv[i]);
        sum+=atoi(argv[i]);
    }
    printf("The sum is: %d\n", sum);
    return 0;
 }