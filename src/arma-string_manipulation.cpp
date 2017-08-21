#include <RcppArmadillo.h>
#include <progress.hpp>                             // add for progressBar

using namespace Rcpp; 
using namespace arma;
                                                   // add for progressBar
// [[Rcpp::depends(RcppArmadillo,RcppProgress)]]    
//[[Rcpp::export]]


List pass_list(const Rcpp::List & control) {
    double a         = Rcpp::as<double>(control["a"]);          
    std::string b    = Rcpp::as<std::string> (control["b"]); // string coercion      
    rowvec v         = Rcpp::as<rowvec>(control["v"]);  
    
    a = a + 77;
    b = b + " alfonso!";                                     // string addition
    v.resize(4);
    v[3] = 99;
    
    cout << "string char:" << b.substr(5, 8) << endl;
    
    return Rcpp::List::create(Rcpp::Named("aL") = a,
                              Rcpp::Named("bL") = b,
                              Rcpp::Named("vL") = v
                                  );
}
/*** R
myList <- list(a=100, b = "Hello", v = c(1,2,3))
pass_list(myList)
*/
