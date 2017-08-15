#include <Rcpp.h>

// [[Rcpp::export]]
Rcpp::NumericVector mypnormCpp(Rcpp::NumericVector x) {
  
  int n = x.size();
  Rcpp::NumericVector y(n);
  
  for (int i=0; i<n; i++) 
    y[i] = R::pnorm(x[i], 0.0, 1.0, 1, 0);
  
  return y;
}


/*** R
mypnormCpp(1:10)

# convert the vector to a matrix for the output
matrix(mypnormCpp(matrix(1:12, nrow=4, ncol=3)), nrow=4, ncol=3)
*/