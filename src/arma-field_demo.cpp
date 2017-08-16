// a field is a class for storing arbitrary objects in matrix-like or 
// cube-like layouts. They can have different size.


#include <RcppArmadillo.h>
using namespace Rcpp; 
using namespace RcppArmadillo;
using namespace arma;

//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]

int fieldDemo() {
    mat A = randn(2,3);     // generate random matrices
    mat B = randn(4,5);
    mat C = randn(9,7);
    mat D = randn(3,8);
    
    field<mat> F(2,2);     // create a field F of matrix type
    F(0,0) = A;
    F(1,0) = B; 
    F(0,1) = C;
    F(1,1) = D;
    
    F.print("F:");
    
    F.save("mat_field");
    return 0;
}

/*** R
fieldDemo()
*/
