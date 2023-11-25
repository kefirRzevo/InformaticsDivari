
#include <stdio.h>
#include <stdlib.h>

typedef struct fraction
{
	int num;
	int denom;
} fraction;

enum arith_oper {Add, Sub, Mul, Div};

void what_to_do (char ch, enum arith_oper* oper)
{
    if(ch == '+')
        *oper = Add;
    else if(ch == '-')
        *oper = Sub;
    else if(ch == '*')
        *oper = Mul;
    else if(ch == '/')
        *oper = Div;
}

void cut(fraction* z)
{
    int min = z->num;
    if(z->denom < min)
        min = z->denom;
    for(int i = 2; i <= min; i++)
        if(z->denom % i == 0 && z->num % i == 0)
            {
                z->num/=i;
                z->denom/=i;
                i--;
            }
    if(z->num == 0 && z->denom != 0)
        z->denom = 1;
}

fraction add(fraction x, fraction y)
{
    fraction z = {};
    z.num = x.num * y.denom + y.num * x.denom;
    z.denom = x.denom * y.denom;
    cut(&z);
    return z;
}

fraction sub(fraction x, fraction y)
{
    fraction z = {};
    z.num = x.num * y.denom - y.num * x.denom;
    z.denom = x.denom * y.denom;
    cut(&z);
    return z;
}

fraction mul(fraction x, fraction y)
{
    fraction z = {};
    z.num = x.num * y.num;
    z.denom = x.denom * y.denom;
    cut(&z);
    return z;
}

fraction div_(fraction x, fraction y)
{
    fraction z = {};
    z.num = x.num * y.denom;
    z.denom = x.denom * y.num;
    cut(&z);
    return z;
}

int main()                
{ 
    fraction x, y;
    printf("Enter fractions\n");
    scanf("%d/%d", &x.num, &x.denom);
    char ch = 0;
    scanf("%c", &ch);
    while(ch == ' ')
        scanf("%c", &ch);   
    scanf("%d/%d", &y.num, &y.denom);
    enum arith_oper oper;
    what_to_do(ch, &oper);

    fraction z = {};
    switch (oper)
    {
        case Add:
            z = add(x, y);
            break;
        case Sub:
            z = sub(x, y);
            break;
        case Mul:
            z = mul(x, y);
            break;
        case Div:
            z = div_(x, y);
            break;
        default:
            break;
    }

    printf("Result: %d/%d\n", z.num, z.denom);    
	return 0;
}