void cplus1(double *x, int *dim)
{
    for (int j = 0; j < dim[1]; ++j)
        for (int i = 0; i < dim[0]; ++i)
            x[j * dim[0] + i] += 1;
}