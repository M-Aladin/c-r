// How to initialize a vector

#include <RcppArmadillo.h>
using namespace Rcpp; 
using namespace arma;

//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]


arma::vec showVector() {
    int nCol = 3;
    int nRow = 4;
    
    arma::vec Vtmp(5);
    Vtmp.zeros();
    
    Vtmp[0] = 1; Vtmp[1] = 2; Vtmp[2] = nCol; Vtmp[3] = nRow; Vtmp[4] = 5; 
    return(Vtmp);
}

/*** R
showVector()
*/
