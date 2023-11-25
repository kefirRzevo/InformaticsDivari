#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXLINE 4096
#define IFNAME "input.txt"
#define OFNAME "output.txt"
 
int comparator(const void *p1, const void *p2)
{
    const char *s1, *s2;
 
    s1 = * (char **) p1;
    s2 = * (char **) p2;
    return strcmp(s1, s2);
}
 
int main()
{
    FILE *ifp, *ofp;
    char *lineptr[MAXLINE];
    char s[MAXLINE];
    int i, nl;
 
    ifp = fopen(IFNAME, "r");
    if(ifp == NULL || (ofp = fopen(OFNAME, "w")) == NULL)
    {
        perror("fopen");
        return -1;
    }
 
    for(i = 0; i < MAXLINE; ) 
    {
        if(fgets(s, sizeof(s), ifp) == NULL)
            break;
        if(*s != '\n')
            lineptr[i++] = strdup(s);
    }
 
    nl = i;
    qsort(lineptr, nl, sizeof(char *), comparator);
 
    for(i = 0; i < nl; i++) 
    {
        fprintf(ofp, "%s", lineptr[i]);
        free(lineptr[i]);
    }
    fclose(ifp);
    fclose(ofp);
    return 0;
}