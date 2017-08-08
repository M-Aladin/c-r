#include <stdio.h>
#include <R.h>
#include <R_ext/BLAS.h>

void fooblas(int *dimension, double *vect1, double *vect2)
{
    const int dim = dimension[0];
    const int incxy = 1;

    //swaps two vectors
    F77_NAME(dswap)(&dim,vect1,&incxy,vect2,&incxy);
}
