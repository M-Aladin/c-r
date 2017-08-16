#include <RcppArmadillo.h>
#include <progress.hpp>                             // add for progressBar

using namespace Rcpp; 
using namespace arma;
                                                   // add for progressBar
// [[Rcpp::depends(RcppArmadillo,RcppProgress)]]    
//[[Rcpp::export]]


List pass_list(const Rcpp::List & control) {
    double a           = Rcpp::as<double>(control["a"]);          
    char b             = Rcpp::as<char>(control["b"]);          
    rowvec v           = Rcpp::as<rowvec>(control["v"]);  
    
    a = a + 77;
    //b[0] = "A";
    v.resize(4);
    v[3] = 99;
    
    return Rcpp::List::create(Rcpp::Named("aL") = a,
                              Rcpp::Named("bL") = b,
                              Rcpp::Named("vL") = v
                                  );
}
/*** R
# how do we manipulate string in Rcpp??

myList <- list(a=100, b = "H", v = c(1,2,3))
pass_list(myList)
*/
