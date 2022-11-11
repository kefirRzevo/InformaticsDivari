#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


struct _Decimal 
{
    char *a;        // number is a[0]*10^0 + a[1]*10^1 + ..+ a[n]*10^n
    unsigned int n; 
    unsigned int size;          // наибольшая степень десяти
};
typedef struct _Decimal Decimal;


Decimal * mult(const Decimal * a, unsigned int k)
{   
    unsigned int j = k;
    unsigned int i = 0;

    char num_dig   = 1;
    while(j > 9)
    {
        j/=10;
        num_dig++;
    }
    printf("|%d|", num_dig);
    Decimal* output = (Decimal *)calloc(1, sizeof(Decimal));
    output->a       = (char    *)calloc(num_dig + a->n + 1, sizeof(char));
    output->n       = 0;
    int s = num_dig + a->n + 1;

    unsigned int add = 0;
    for(i = 0; i <= s; i++)
    {
        output->n++;
        unsigned int current_digit = 0;

        if(i > a->n)
            current_digit = 0;
        else
            current_digit = a->a[i];
        
        output->a[i] = (add + current_digit * k) % 10;
        add          = (unsigned int) ((add + current_digit * k) / 10);
        if(i > a->n && output->a[i] == 0 && add == 0)
            break;
    }

    j = output->n;
    while(output->a[j] == 0 && j > 0)
    {
        output->n--;
        j--;
    }
    printf("|%d|", output->n);
    return output;
}

void elong_free(Decimal *p_decimal)
{
   free(p_decimal->a);
   free(p_decimal);
}

static Decimal* set_int(const size_t number)
{
   unsigned int power = 0;
   size_t       temp  = number;
   
    while(temp > 9)
    {
        temp/=10;
        power++;
    }
   
   unsigned char array = (unsigned char *)calloc(power + 1, sizeof(unsigned char));
   
   size_t i = 0;
   temp = number;
   
   while (1)
   {
      array[i++] = temp % 10;
      temp /= 10;
      
      if (temp == 0)
         break;
   }
   
   Decimal *const p_decimal = (Decimal *)calloc(1, sizeof(Decimal));

   p_decimal->a = array;
   p_decimal->n = power;
   
   return p_decimal;
}


int main()
{
    Decimal * a;
    Decimal * res;

    a = set_int(246);
    res = mult(a, 5);

    //printf("%s", res->a);
    //printf("\n");

    //elong_free(res);
    return 0;
}
