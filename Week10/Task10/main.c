#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


unsigned int SymToNum(char c)
{
    if(c == 'I')
        return 1;
    else if(c == 'V')
        return 5;
    else if(c == 'X')
        return 10;
    else if(c == 'L')
        return 50;
    else if(c == 'C')
        return 100;
    else if(c == 'D')
        return 500;
    else if(c == 'M')
        return 1000;
    return 0;
}


void RimToInt (int* x, char* rim)
{
    int sum = 0;
    unsigned int len = strlen(rim) - 1;
    for(int i = 0; i < len; i++)
    {
        unsigned int num1 = SymToNum(rim[i]);
        unsigned int num2 = SymToNum(rim[i+1]);
        unsigned int num3 = SymToNum(rim[i+2]);
        unsigned int num4 = SymToNum(rim[i+3]);

        if(num1 == num2 && num2 == num3 && num3 == num4)
            *x = -2;

        if(num1 == 0 || num2 == 0)
            *x = -1;

        if(num2 <= num1)
            sum += num1;
        else
            sum -= num1;
    }
    sum += SymToNum(rim[len]);
    *x = sum;
}


char* IntToSym(unsigned int x)
{
    if(x == 1)
        return "I";
    else if(x == 5)
        return "V";
    else if(x == 10)
        return "X";
    else if(x == 50)
        return "L";
    else if(x == 100)
        return "C";
    else if(x == 500)
        return "D";
    else if(x == 1000)
        return "M";
    return "";
}


void digit(int dig, int por, char *s)
{  
    switch(dig)
    {
        case 0:
            break;
        case 1:
            strcat(s, IntToSym(1*por));
            break;
        case 2:
            strcat(s, IntToSym(1*por));
            strcat(s, IntToSym(1*por));
            break;
        case 3:
            strcat(s, IntToSym(1*por));
            strcat(s, IntToSym(1*por));
            strcat(s, IntToSym(1*por));
            break;
        case 4:
            strcat(s, IntToSym(1*por));
            strcat(s, IntToSym(5*por));
            break;
        case 5:
            strcat(s, IntToSym(5*por));
            break;
        case 6:
            strcat(s, IntToSym(5*por));
            strcat(s, IntToSym(1*por));
            break;
        case 7:
            strcat(s, IntToSym(5*por));
            strcat(s, IntToSym(1*por));
            strcat(s, IntToSym(1*por));
            break;
        case 8:
            strcat(s, IntToSym(5*por));
            strcat(s, IntToSym(1*por));
            strcat(s, IntToSym(1*por));
            strcat(s, IntToSym(1*por));
            break;
        case 9:
            strcat(s, IntToSym(1*por));
            strcat(s, IntToSym(10*por));
            break;
    }
}


void IntToRim(unsigned int x, char* rim)
{
    unsigned int a = x;
    int num = 1;
    int por = 1;

    while(a > 9) 
    {
        a/=10;
        num++;
        por*=10;
    }

    for(int i = 0; i < num; i++)
    {
        int dig = x/por;
        char  s[4] = "";
        digit(dig, por, s);
        strcat(rim, s);

        x = x % por; 
        por /= 10;
    }
}


int main()
{
    /*char s[] = "LXV";
    int x = RimToInt(s);
    printf("%d\n", x);

    unsigned int y = 118;
    char str[10] = "";
    IntToRim(y, str);
    printf("%s\n", str);*/

    FILE *fp = fopen ("input.txt", "r");
    FILE *fq = fopen ("output.txt", "w+");
    fseek(fp, 0L, SEEK_SET);
    fprintf(fq, "______________________________________________________________________\n");
    fprintf(fq, "|scanfed_num    |result_str     |scanfed_str    |result_num     |ok? |\n");
    fprintf(fq, "|_______________|_______________|_______________|_______________|____|\n");
    while(!feof(fp))
    {
        int x = 0;
        char str_x[20] = "";

        int y = 0;
        char str_y[20] = "";

        fscanf(fp, "%d%s", &x, str_y);
        IntToRim(x, str_x);
        RimToInt(&y, str_y);
        char ch = '-';
        if(x == y)
            ch = '+';
        fprintf(fq, "|%15d|%15s|%15d|%15s|%4c|\n", x, str_x, y, str_y, ch);
    } 
    return 0;
}