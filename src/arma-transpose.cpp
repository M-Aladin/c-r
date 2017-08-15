#include <RcppArmadillo.h>
using namespace Rcpp;
//[[Rcpp::export]]


arma::mat a18(arma::mat x) {
    return(x.t()) ;
}



/*** R
Z <- matrix(1:6, 2, 3)
Z

a18(Z)

*/

