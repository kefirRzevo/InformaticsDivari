#include <stdio.h>


int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        printf("Error with filename\n");
        return 0;
    }
    
    char c = 0;
    const char* ch = argv[1];
    sscanf(ch, "%*c%c", &c);
    if(c == '0')
        printf("fe");
    if(c == '1')
        printf("ma");
    if(c == '2')
        printf("fe");
    if(c == '3')
        printf("ma");
    if(c == '4')
        printf("fe");
    if(c == '5')
        printf("ma");
    if(c == '6')
        printf("fe");
    if(c == '7')
        printf("ma");
    if(c == '8')
        printf("fe");
    if(c == '9')
        printf("ma");
    if(c == 'a' || c == 'A')
        printf("fe");
    if(c == 'b' || c == 'B')
        printf("ma");
    if(c == 'c' || c == 'C')
        printf("fe");
    if(c == 'd' || c == 'D')
        printf("ma");
    if(c == 'e' || c == 'E')
        printf("fe");
    if(c == 'f' || c == 'F')
        printf("ma");
    return 0;
}