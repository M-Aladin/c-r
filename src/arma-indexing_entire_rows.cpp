#include <RcppArmadillo.h>
using namespace Rcpp;

//[[Rcpp::export]]

arma::mat a11 (arma::mat x, int i) {
    return(x.row(i)) ;
}





/*** R
Z <- matrix(rnorm(6), 2, 3)
Z

a11(Z, 1)

*/

