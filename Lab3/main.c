#include "include/parser.h"
#include "include/processing.h"
#include "include/output.h"
#include <unistd.h>

int main(int argc, char * argv[])
{
    char *file_name          = NULL;
    struct position * ship   = NULL;
    struct position * port   = NULL;
    struct fig *  triangle   = NULL;
    int *           danger   = NULL;
    int N = 0;


    if(argc > 1)
        file_name = argv[1];
    else
    {
        printf("Incorrect filename\n");
        return 0;
    }


    get_data(file_name, &N, &ship, &port, &triangle);
    make_danger_array(N, ship, triangle, port, &danger);
    danger_signal(N, danger);


    free(ship);
    free(port);
    free(triangle);
    free(danger);
    return 0;
}
