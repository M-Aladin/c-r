#include <RcppArmadillo.h>
using namespace Rcpp;
using namespace RcppArmadillo;
using namespace arma;
//[[Rcpp::depends(RcppArmadillo)]]

//[[Rcpp::export]]
cube up_C(mat a){
    int m = a.n_rows;    // get rows from matrix a
    int n = a.n_cols;    // get cols from matrix a
    
    cube C = cube(m, n, m, fill::zeros);  // create array and fill w/zeros
    
    C.slice(0) = a;  // output array 1st matrix is matrix a
    
    for (int slices = 1; slices < m; ++slices){   // move through slices
        for (int j = 0; j < n; ++j) {             // move through cols
            for (int i = slices; i < m; ++i) {    // move through rows
                // extract subcubes
                vec S = C.subcube(i - slices, j, 0, i, j, 0);
                // Armadillo product function arma::prod(S)
                C(i, j, slices) = prod(S);
            }
        }
    }
    return(C);
}