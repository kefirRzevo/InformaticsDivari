#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    FILE *fp = fopen ("file.txt", "a+");
    FILE *fq = fopen ("output.txt", "w");

    char s[] = "1 2 3 4 5 6 7 8 9 end file";
    fprintf(fp, "%s", s);
    fseek(fp, 0L, SEEK_SET);

    fseek(fp, 0L, SEEK_END);
    int sum = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    //printf("%d", sum);
    char *text = (char*) calloc(sum, sizeof(char));
    fseek(fp, 0L, SEEK_SET);
    fread (text, sizeof(char), sum, fp);

    char* p = strstr(text, "end file");
    sum = (char*)p - (char*)text;
    text[sum] = '\0';
    
    //printf(" %d", sum);

    fprintf(fq, "As an integer: ");
    for(int i = 0; i < sum; i++)
        fprintf(fq, "%d", text[i]);

    fprintf(fq, "\nAs a double:   ");
    for(int i = 0; i < sum; i++)
        fprintf(fq, "%lf", (double) text[i]); 

    fprintf(fq, "\nAs a symbol:   ");
    for(int i = 0; i < sum; i++)
        fprintf(fq, "%c", text[i]);  

    fprintf(fq, "\nAs a string:   ");     
    fputs(text, fq);
    
    free(text);
    return 0;
}