#include "../include/parser.h"


FILE* fp = NULL;


static void read_coordinates(struct position* p_pos)
{
    fscanf(fp, "%d%d%d%d%d%d",      &((*p_pos).latitude.degree),    &((*p_pos).latitude.minute),   &((*p_pos).latitude.second),
                                    &((*p_pos).longitude.degree),   &((*p_pos).longitude.minute),  &((*p_pos).longitude.second));                                

    if( (*p_pos).longitude.minute >  60  ||  (*p_pos).longitude.second > 60 || (*p_pos).latitude.minute  > 60  || (*p_pos).latitude.second > 60 ||  
        (*p_pos).longitude.minute <   0  ||  (*p_pos).longitude.second <  0 || (*p_pos).latitude.minute  <  0  || (*p_pos).latitude.second <  0 ||  
        (*p_pos).longitude.degree >  180 ||  (*p_pos).longitude.degree <  0 || (*p_pos).latitude.degree  >  90 || (*p_pos).latitude.degree <  0 ||  
        (*p_pos).longitude.degree == 180 && ((*p_pos).longitude.minute != 0 || (*p_pos).longitude.second != 0) ||                        
        (*p_pos).latitude.degree  ==  90 && ((*p_pos).latitude.minute  != 0 || (*p_pos).latitude.second  != 0) )                        
    {                                                                                                                                                       
        printf("Incorrect data");                                                                                                                           
        exit(0);                                                                                                                                            
    } 
}


static void input_ship (int N, struct position** ship)
{
    *ship = (struct position* ) calloc(N, sizeof(struct position));

    for(int i = 0; i < N; i++)
        read_coordinates(*ship + i);
}                                                                                                                                                                                                                                                  


static void input_triangle (struct fig** triangle)
{
    *triangle = (struct fig* ) calloc(3, sizeof(struct fig));
    
    read_coordinates( &((*triangle)->apex1) );
    read_coordinates( &((*triangle)->apex2) );
    read_coordinates( &((*triangle)->apex3) );
}


static void input_port(struct position** port)
{
    *port = (struct position* ) calloc(1, sizeof(struct position));

    read_coordinates(*port);
}


void get_data(char* file_name, int* N, struct position** ship, struct position** port, struct fig** triangle)
{
    fp = fopen(file_name, "r");
    assert(fp);

    fscanf(fp, "%d", N);

    input_port(port);
    input_ship(*N, ship);
    input_triangle(triangle);

    fclose(fp);
}