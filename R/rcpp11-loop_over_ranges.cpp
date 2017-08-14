// http://gallery.rcpp.org/articles/first-steps-with-C++11/

#include <Rcpp.h>

// Enable C++11 via this plugin (Rcpp 0.10.3 or later)
// [[Rcpp::plugins(cpp11)]]

// [[Rcpp::export]]
int simpleProd(std::vector<int> vec) {
    int prod = 1;
    for (int &x : vec) {       // loop over all values of vec
        prod *= x;              // access each elem., comp. product
    }
    return prod;
}

/*** R
simpleProd(1:5)
*/
