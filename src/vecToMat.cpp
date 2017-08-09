#include <Rcpp.h> 
using namespace Rcpp;

//[[Rcpp::export]]
NumericMatrix vecToMat(NumericVector x, double y) {

    NumericVector xx = x;
    double yy = y;
    int n_xx = xx.size();
    
    NumericMatrix ans(n_xx, n_xx);      //  return matrix
    
    for(int i = 0; i < n_xx; i++) {
        for(int j = 0; j < n_xx; j++){
            if ((xx[i] - xx[j] < 10e-7) && (xx[i] - xx[j] > -10e-7)){
                ans(i,j) = exp(xx[j] * yy) * yy;
            } else {
                ans(i,j) = (exp(xx[i] * yy) - exp(xx[j] * yy))/(xx[i] - xx[j]);
            }
        }
    }
    
    return (ans);
}