#include <RcppArmadillo.h>
using namespace Rcpp;
//[[Rcpp::export]]



arma::mat a16(arma::mat x) {
    return(x % x) ;
}



/*** R
Z <- matrix(rnorm(6), 2, 3)
Z

a16(Z)

*/

