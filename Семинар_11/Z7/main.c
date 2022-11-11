#include <stdio.h>
#include <stdlib.h>

void read(FILE* fp)
{
    fseek(fp, 0L, SEEK_END);
    int size_of_file = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    char *text = (char*) calloc(size_of_file + 1, sizeof(char));
    int text_size = fread (text, sizeof(char), size_of_file, fp);
    for(int i = 0; i < text_size; i++)
        printf("%c", text[i]);
    free(text);
}

int main(int argc, char * argv[])
{
    char* file_name = NULL;
    if(argc > 1)
        file_name = argv[1];
    else
        return 0;
    FILE *fp = fopen (file_name, "r");
    read(fp);
    return 0;
}