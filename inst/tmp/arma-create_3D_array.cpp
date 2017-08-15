#include <RcppArmadillo.h>
using namespace Rcpp; 
using namespace RcppArmadillo;
using namespace arma;

//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]

cube arrayArma(vec input, uvec dim) { 
        input.set_size(dim[0], dim[1], dim[2]);
        cout << "dim \n" << dim[0]  << endl;
    return input;
}

/*** R
x = 1:8
arrayArma(x, c(2,2,2))
*/
