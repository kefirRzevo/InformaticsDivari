#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../functions.h"


const double interval1 = 0.2;
const double interval2 = 8.2;


double nonlinear_equation (double *radioactivity, double *time, int N, double precision, double interval1, double interval2)
{
    double x = (interval1 + interval2) / 2;
    while (fabs(model(radioactivity, time, N, x)) > precision)
    {
        if( model(radioactivity, time, N, interval1) * model(radioactivity, time, N, x) < 0)
        {
            interval2 = x;
        }
        else
        {
            interval1 = x;
        }

        x = (interval1 + interval2) / 2;
    }
    return x;
}

double model(double *radioactivity, double *time, int N, double point)
{
    double value_in_point = 0;

    for (int i = 0; i <= N; i++)
        value_in_point += time[i] * exp(- time[i] / point) * (radioactivity[i] - exp(- time[i] / point));

    return value_in_point;
}


double linear_equation (double *radioactivity, double *time, int N)
{
    double numerator_sum = 0;
    double denominator_sum = 0;

    for(int i = 0; i <= N; i++)
    {
        numerator_sum += time[i] * time[i];
        denominator_sum += time[i] * (1 - radioactivity[i]);
    }

    return numerator_sum / denominator_sum;
}