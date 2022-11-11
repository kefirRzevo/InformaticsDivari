#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(void* a, void* b, int size)
{
    void* temp = malloc(size);
    memcpy(temp, a,    size);
    memcpy(a,    b,    size);
    memcpy(b,    temp, size);
    free(temp);
}

int main()
{
    int a1 = 0, b1 = 1;
    printf("a1, b1:%4d%4d\n", a1, b1);
    swap(&a1, &b1, sizeof(int));
    printf("a1, b1:%4d%4d\n", a1, b1);

    double a2 = 0.1, b2 = 1.1;
    printf("a2, b2:%4.1lf%4.1lf\n", a2, b2);
    swap(&a2, &b2, sizeof(double));
    printf("a2, b2:%4.1lf%4.1lf\n", a2, b2);

    char a3 = 'a', b3 = 'b';
    printf("a3, b3:%4c%4c\n", a3, b3);
    swap(&a3, &b3, sizeof(char));
    printf("a3, b3:%4c%4c\n", a3, b3);
    return 0;
}