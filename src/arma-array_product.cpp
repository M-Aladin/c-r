#include <RcppArmadillo.h>
using namespace Rcpp;
using namespace RcppArmadillo;
using namespace arma;

//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]

cube product (cube x, cube y) {
    
    arma::cube r = x %  y; // %	array product: element-wise multiplication of two objects
    
    return( r );
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
a = array(1:18, dim = c(3, 6, 1))
b = array(1:18, dim = c(3, 6, 1))
product(a, b)

# [,1] [,2] [,3] [,4] [,5] [,6]
# [1,]    1   16   49  100  169  256
# [2,]    4   25   64  121  196  289
# [3,]    9   36   81  144  225  324
*/
