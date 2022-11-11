#include <stdio.h>
#include <ctype.h>


#define N 100
struct _Decimal 
{
    char a[N];       // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n;  // наибольшая степень десяти
};
typedef struct _Decimal Decimal;

void half(Decimal *res, Decimal *in)
{
    res->n = in->n;
    char cur = 0;
    for(unsigned int i = 0; i <= in->n; i++)
    {
        char t = in->a[i] - '0';
        cur += t;
        if(cur % 2 == 0)
        {
            res->a[i] = '0' + (int) cur / 2;
            cur = 0;
        }
        else if(cur == 1)
        {
            res->a[i] = '0';
            cur *=10;
        }
        else if(cur % 2 == 1)
        {
            res->a[i] = '0' + (int) cur / 2;
            cur -= 2 * ((int) cur / 2);
            cur *=10;
        }
    }
    while(res->a[0] == '0')
    {
        for(int i = 0; i <= res->n - 1; i++)
        {
            res->a[i] = res->a[i + 1];
        }
        res->n--;
    }
}

//Decimal zero = {{0}, 0};    // представление 0 в виде структуры
//Реализуйте функцию деления на 2 большого числа (с отбрасыванием остатка).

int main()
{
    Decimal num1 = {{"1000"}, 3};
    Decimal num2 = {{}, 0};
    half(&num2, &num1);
    printf("%d ", num2.n);
    for(int i = 0; i <= num2.n; i++)
        printf("%c", num2.a[i]);
    return 0;
}