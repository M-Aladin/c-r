// http://gallery.rcpp.org/articles/first-steps-with-C++11/

#include <RcppArmadillo.h>

// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
// C++11 only examples

using namespace arma;

mat A = ones(4,5);

// add 123 to each element
A.for_each( [](mat::elem_type& val) { val += 123.0; } );  // NOTE: the '&' is crucial!


field<mat> F(2,3);

// set the size of all matrices in field F
F.for_each( [](mat& X) { X.zeros(4,5); } );  // NOTE: the '&' is crucial!

/*** R
simpleProd(1:5)
*/
