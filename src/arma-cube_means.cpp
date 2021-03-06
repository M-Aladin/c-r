#include <RcppArmadillo.h>
#include <progress.hpp>

using namespace Rcpp; 
using namespace arma;

// [[Rcpp::depends(RcppArmadillo,RcppProgress)]]
//[[Rcpp::export]]


mat cubeMeans(arma::cube X) {
    int nSlice = X.n_slices;
    int nCol = X.n_cols;
    int nRow = X.n_rows;
    
    arma::vec Vtmp(nCol);
    arma::mat Mtmp(nRow, nCol);
    arma::mat Means(nCol, nSlice);
    
    // Initiate Progress Bar
    Progress prog(niter, display_progress);
    
        // update Progress Bar
        prog.increment(); 
        
    
    for (int i = 0; i < nSlice; i++){
        Mtmp = X.slice(i);
        for(int j = 0; j < nCol; j++){
            Vtmp(j) = sum(Mtmp.col(j)) / nRow; 
        }
        Means.col(i) = Vtmp;
    }
    return(Means);
}
/*** R
xl <- array(1:100, c(5, 10, 2))
xl
cubeMeans(xl)
*/
