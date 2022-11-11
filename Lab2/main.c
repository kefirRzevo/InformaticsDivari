#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//Голубович Тимур
//Давид Согомонян
//Цыблиенко Никита

int main()
{
    double radioactivity[100] = {};
    double time[100]          = {};

    double start_time    = 0.0;
    double end_time      = 9.9;
    double step          = 0.1;
    double precision     = 0.001;
    double const betta[] = {3.0, 4.0, 4.5, 3.7, 5.0, 5.3};
    double interval1     = 0.2;
    double interval2     = 8.2;

    FILE *FILE;
    FILE = fopen ("output.txt", "w");

    for(int i = 0; i < 6; i++)
    {
    int N = experiment(radioactivity, time, start_time, end_time, step, betta[i]);
    add_noise(radioactivity, N);


    double decay_time       = nonlinear_equation(radioactivity, time, N, precision, interval1, interval2);
    double decay_rate       = linear_equation(radioactivity, time, N);
    double time_differences = precision_analysis(radioactivity, time, N, precision, interval1, interval2);


    fprintf  (FILE, "betta:            %8.1lf\n",       betta[i]);
    fprintf  (FILE, "decay_time:       %8.3lf\n",       decay_time);
    fprintf  (FILE, "decay_rate:       %8.3lf\n",       decay_rate);
    fprintf  (FILE, "time_differences: %8.1lf\n\n",     time_differences);
    }

    return 0;
}
