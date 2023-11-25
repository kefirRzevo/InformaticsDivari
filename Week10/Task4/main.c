#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen ("file.txt", "w+");

    char s[] = "1 2 3 4 5 6 7 8 9 0";
    fprintf(fp, "%s", s);
    fseek(fp, 0L, SEEK_SET);
    char s1[100] = "";
    scanf("%*d");
    fgets(s1, 100, fp);
    printf("%s", s1);      
    return 0;
}