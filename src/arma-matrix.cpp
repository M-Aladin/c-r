// How to initialize a matrix

#include <RcppArmadillo.h>
using namespace Rcpp; 
using namespace arma;

//[[Rcpp::depends(RcppArmadillo)]]


//[[Rcpp::export]]
arma::mat showMatrix(arma::vec dim) {
    int nCol = dim[0];
    int nRow = dim[1];
    
    arma::mat mx(nRow, nCol);
    mx.zeros();
    
    return(mx);
}

//[[Rcpp::export]]
arma::mat ones(arma::vec dim) {
    int nCol = dim[0];
    int nRow = dim[1];
    
    arma::mat mx(nRow, nCol);
    mx.ones();
    
    return(mx);
}



/*** R
showMatrix(c(5,4))

ones(c(7,5))

*/
