// Listing 2.4

#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
NumericVector convolve1d(NumericVector a, NumericVector b) {
    NumericVector xa(a);
    NumericVector xb(b);
    int n_xa = xa.size(), n_xb = xb.size();
    NumericVector xab(n_xa + n_xb - 1);
    
    for (int i = 0; i < n_xa; i++)
        for (int j = 0; j < n_xb; j++)
            xab[i + j] += xa[i] * xb[j];
 return xab;
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
# simple example that gives this response in Matlab
x = c(3, 4, 5, 0, 0)
y = c(2, 1)
convolve1d(x, y) 
# 6 11 14  5  0  0      as in Matlab

x = c(3, 4, 5)
y = c(2, 1)
convolve1d(x, y) 
# 6 11 14  5    as in Matlab

*/
