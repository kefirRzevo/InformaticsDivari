#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp = fopen ("file.txt", "w+");

    char s[] = "abc def ghi jkl mno pqr stu vwxy z";
    fprintf(fp, "%s", s);
    fseek(fp, 0L, SEEK_SET);
    char s1[100] = "";
    scanf("%*d");
    fgets(s1, 100, fp);
    printf("%s", s1);      
    return 0;
}