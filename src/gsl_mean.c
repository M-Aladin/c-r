#include <stdio.h>
#include <R.h>
#include <math.h>
#include <gsl/gsl_statistics.h>

void gsl(double *x, int *n)
{
    double mean = gsl_stats_mean(x, 1, n);
    Rprintf("mean = %f\n", mean);
}