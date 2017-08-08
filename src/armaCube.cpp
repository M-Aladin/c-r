// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

using namespace Rcpp;

// [[Rcpp::export]]
SEXP f(SEXP A_, SEXP A2_){  
    NumericVector A(A_);
    NumericVector A2(A2_);
    
    // read dimension attribute of R arrays
    IntegerVector d1 = A.attr("dim");
    IntegerVector d2 = A2.attr("dim");
    
    // create 2 cubes B and B2
    // supply contents of dim vectors manually
    arma::cube B(A.begin(), d1[0], d1[1], d1[2], false);
    arma::cube B2(A2.begin(),  d2[0], d2[1], d2[2], false);
    
    // do some arithmethic
    arma::cube C(d1[0], d1[1], d1[2]);
    C = B + B2;
    
    // copy the result back to B (which is a view of A, i.e. will contain the same data)
    B = C;
    
    // return array
    return wrap(A);
} 

