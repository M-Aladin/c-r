#include <RcppArmadillo.h>
using namespace Rcpp;

//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]

arma::mat a5 (arma::mat x) {
    // print dimension of matrix and return it
    int R = x.n_rows ;
    int C = x.n_cols ;
    
    Rcout << "Rows: " << R << std::endl ;
    Rcout << "Cols: " << C << std::endl ;
    
    return(x) ;
}

/*** R
a5(matrix(0, nrow = 2, ncol = 3))
*/
