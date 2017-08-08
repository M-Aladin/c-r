#include<Rcpp.h>

// [[Rcpp::export]]
void implicit_ref(Rcpp::NumericVector X){
X = X + 1.0;
}

// [[Rcpp::export]]
void explicit_ref(Rcpp::NumericVector& X){
X = X + 1.0;
}