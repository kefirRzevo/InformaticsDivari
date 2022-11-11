#include "../include/output.h"
#include <time.h>
#include <unistd.h>


void danger_signal (int N, int *danger )
{
    assert(danger);

    const char OK[] = "YES";
    const char NO[] = "NO";

    for(int i = 0; i < N; i++)
    {
        bool check_danger = danger[i] == 1;
        printf("%d\t%s\n", i + 1, check_danger ? OK : NO);

        if(!check_danger)
            printf("\a");

        sleep(1);
    }

}