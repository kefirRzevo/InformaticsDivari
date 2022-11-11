#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../functions.h"


double dev_exp(double *radioactivity, double *time, int M, double decay_time)
{
    double sum_residuals = 0.;
    for (int i = 0; i <= M; i++)
        sum_residuals += ((radioactivity[i] - exp(- time[i] / decay_time)) * (radioactivity[i] - exp(- time[i] / decay_time)));
    
    return (sqrt(sum_residuals) / M);
}


double dev_linear(double *radioactivity, double *time, int M, double decay_rate)
{
    double sum_residuals = 0.;
    for (int i = 0; i <= M; i++)
        sum_residuals += ((radioactivity[i] - (1 - time[i] / decay_rate)) * (radioactivity[i] - (1 - time[i] / decay_rate)));
    
    return (sqrt(sum_residuals) / M);
}


double precision_analysis (double *radioactivity, double *time, int N, double precision, double interval1, double interval2)
{
    double time_differences = 0;

    int M = 10;
    double decay_time = nonlinear_equation(radioactivity, time, M, precision, interval1, interval2), 
           decay_rate = linear_equation(radioactivity, time, M);
    while(4 * dev_exp(radioactivity, time, M, decay_time) > dev_linear(radioactivity, time, M, decay_rate))
    {
        M++;
        decay_time = nonlinear_equation(radioactivity, time, M, precision, interval1, interval2); 
        decay_rate = linear_equation(radioactivity, time, M);
    }

    time_differences = time[M - 1];
    return time_differences;
}