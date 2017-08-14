#include <RcppArmadillo.h>
using namespace arma;
using namespace Rcpp;
//[[Rcpp::export]]


arma::mat T(arma::cube x) {
    
    x.each_slice( [](mat& X){ X.print(); } );     // lambda function with non-const matrix
    return(x) ;
}



/*** R
Z <- matrix(1:6, 2, 3)
Z

T(Z)

*/

