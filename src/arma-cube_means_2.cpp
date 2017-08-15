/*
 * Uses Rcpp types. NumericVector instead of arma::cube
 * IntegerVector instead of arma::vec
 */

#include <RcppArmadillo.h>
using namespace Rcpp; 
using namespace arma;

//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]

arma::mat cube_means(Rcpp::NumericVector vx) {
    
    Rcpp::IntegerVector x_dims = vx.attr("dim");
    arma::cube x(vx.begin(), x_dims[0], x_dims[1], x_dims[2], false);
    arma::mat result(x.n_cols, x.n_slices);
    
    for (unsigned int i = 0; i < x.n_slices; i++) {
        result.col(i) = arma::conv_to<arma::colvec>::from(arma::mean(x.slice(i)));  
    }
    
    return result;
}

/*** R
xl <- array(1:500, c(10, 10, 5))
cube_means(xl)
*/
