#include <RcppArmadillo.h>
using namespace Rcpp;
using namespace RcppArmadillo;
using namespace arma;
//[[Rcpp::depends(RcppArmadillo)]]

//[[Rcpp::export]]
double inner (arma::vec x,
               arma::vec y
) {
    arma::mat ip = x.t() * y ;
    return(ip(0)) ;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
mx = matrix(1:18, nrow=6, ncol =3)
my = matrix(19:36, nrow=6, ncol =3)
inner(mx, my)
*/
