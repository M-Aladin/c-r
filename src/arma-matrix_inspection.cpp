#include <RcppArmadillo.h>
using namespace Rcpp;

//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]

int a7 (arma::mat x) {
    // More useful than Rcout. No need to loop through elements.
    x.print() ;
    x.print("Note") ;
    return(0) ;
}



/*** R
a7(matrix(0, nrow = 2, ncol = 3))

a7(diag(2))

*/
