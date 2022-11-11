#ifndef PARSER_H
#define PARSER_H


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>


struct  coordinates
{   
    int degree;
    int minute;
    int second;
};


struct     position
{   
    struct coordinates latitude;
    struct coordinates longitude;
};


struct      fig
{ 
    struct  position apex1;
    struct  position apex2;
    struct  position apex3;
};

void get_data(char* file_name, int* N, struct position** ship, struct position** port, struct fig** triangle);


//float slopes[50][4]={};
//int  danger[50]={};
#endif