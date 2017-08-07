void arrplus1(double *x, int *dim)
{
    for (int i = 0; i < dim[0]; ++i)
        for (int j = 0; j < dim[1]; ++j)
            for (int k = 0; k < dim[2]; ++k) {
                x[ k + dim[2]*(j+ i*dim[1]) ] += 1;
            }
}

// Ref: http://eli.thegreenplace.net/2015/memory-layout-of-multi-dimensional-arrays/