#include <RcppArmadillo.h>
using namespace Rcpp;

//[[Rcpp::export]]
arma::mat uninitMatrix (int n, int r) {
    arma::mat x(n, r) ;
    x.print("") ;
    return(x) ;
}


arma::mat initMatrix (int n, int r) {
    arma::mat x(n, r) ;
    x.zeros();
    x.print("") ;
    return(x) ;
}



/*** R
uninitMatrix(2, 3)

*/


/*** R
    
    initMatrix(2, 3)
    */