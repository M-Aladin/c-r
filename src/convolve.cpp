// called by rcpp-sourceCpp_convolveCpp.Rmd

#include <Rcpp.h> 
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector convolveCpp(NumericVector a, NumericVector b) {
  int na = a.size(), nb = b.size();       // size of the vectors
  int nab = na + nb - 1;                  // size of the new vector
  NumericVector xab(nab);                 // output vector
  
  for (int i = 0; i < na; i++)
    for (int j = 0; j < nb; j++)
      xab[i + j] += a[i] * b[j];
  return xab;
}





