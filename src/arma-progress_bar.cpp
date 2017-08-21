#include <RcppArmadillo.h>
#include <progress.hpp>                             // add for progressBar

using namespace Rcpp; 
using namespace arma;
                                                   // add for progressBar
// [[Rcpp::depends(RcppArmadillo,RcppProgress)]]    
//[[Rcpp::export]]


mat cubeMeans(arma::cube X) {
    int nSlice = X.n_slices;
    int nCol = X.n_cols;
    int nRow = X.n_rows;
    bool display_progress = true;
    int niter = 10;
    
    arma::vec Vtmp(nCol);
    arma::mat Mtmp(nRow, nCol);
    arma::mat Means(nCol, nSlice);
    
    // Initiate Progress Bar
    Progress prog(niter, display_progress);          // add for progressBar
    
    for (int i = 0; i < nSlice; i++){
        // update Progress Bar
        prog.increment();                            // add for progressBar
        
        Mtmp = X.slice(i);
        for(int j = 0; j < nCol; j++){
            Vtmp(j) = sum(Mtmp.col(j)) / nRow; 
        }
        Means.col(i) = Vtmp;
    }
    return(Means);
}
/*** R
xl <- array(0, c(5, 10, 5000))
apply(xl, c(1,2,3), function(x) sample(c(0,1),1)) 

xl
cubeMeans(xl)
*/
