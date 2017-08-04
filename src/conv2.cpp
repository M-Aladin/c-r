// #include <Math.h>
#include <Rcpp.h> 
using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix conv2(NumericMatrix input, NumericMatrix kernel) {

    int r = 2*input.ncol()-1;
    int c = 2*input.nrow()-1;
    
    int m = kernel.nrow();
    int n = kernel.ncol();
      
    int x, y, q, w;
    
    NumericMatrix h(m, n);
    
    int i, j, mm, nn;

    // find center position of kernel (half of kernel size)
    int centerR = m ;
    int centerC = n ;
    int left = centerC - 1;
    int right = n - centerC;
    int top = centerR - 1;
    int bottom = m - centerR;
    
    NumericMatrix Rep(r + top + bottom, c + left + right);
    
    int nrow = m, ncol = n;
    int ii, jj;
    for (i = 0; i < nrow; ++i) 
    {
        ii = nrow - 1 - i;
        for (j = 0; j < ncol; ++j) 
        {
            jj = ncol - 1 - j;
            h(i, j) = kernel(ii, jj);
        }
    }

    for(x = top; x < r + top; ++x)                // rows
    {
        for(y = left; y < c + left; ++y)            // columns
        {
            Rep(x, y) = input(x - top, y - left);
        }
    }
    
    NumericMatrix B(r, c);
    
    for (x = 0; x < r; ++x) 
    {
        for (y = 0; y < c; ++y)
        {
            for (i = 0; i < m; ++i)
            {
                for (j = 0; j < n; ++j)
                {
                    q = x;
                    w = y;
                    B(x, y) = B(x, y) +  (Rep(i + q, j + w) * h(i, j));
                }
            }
        }
    }

    return B;
}