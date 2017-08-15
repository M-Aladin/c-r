#include <RcppArmadillo.h>
using namespace Rcpp;
using namespace RcppArmadillo;
using namespace arma;

//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]

cube T(cube a){
    int m = a.n_rows;    // get rows from matrix a
    int n = a.n_cols;    // get cols from matrix a
    int p = a.n_slices;    // get cols from matrix a
    
    Rcout << "Rows: "   << m << std::endl ;
    Rcout << "Cols: "   << n << std::endl ;
    Rcout << "Slices: " << p << std::endl ;
    
    cube out(n, m, p);
    out.zeros();
    
    for (int i = 0; i < p; ++i){   // move through slices
        mat mx = a.slice(i);
        out.slice(i) = mx.t();
        // Rcout << "slice #: " << i << std::endl ;
        // Rcout << "matrix: " << "\n" << mx << std::endl ;
        // Rcout << "transposed: " << "\n" << mx.t() << std::endl ;
    }
    return(out);
}


/*** R
# read a matrix and create a cube of m x n x m 
# fill the first slice of the cube with the original matrix
# calculate the product of the rows
arr <- array(1:500, c(4, 5 , 3))
arr

T(arr)
*/