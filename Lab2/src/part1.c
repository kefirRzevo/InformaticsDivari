#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../functions.h"


int experiment (double* radioactivity, double* time, double start_time, double end_time, double step, const double betta)
{
    int N = (int)((end_time - start_time) / step);

    for(int i = 0; i <= N; i++)
    {
        time[i] = start_time + i * step;
        radioactivity[i] = exp(- time[i] / betta);
    }

    return N;
}


void add_noise (double *radioactivity, int N)
{
    srand(time(NULL));
    for(int i = 0; i <= N; i++)
    {
        double noise = ((rand() % 10000) - 5000) * 0.05 / 10000;
        radioactivity[i] += noise;
    }
}

