#include <Rmath.h>
#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma; 

//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]

RcppExport SEXP FHUBNB2 (SEXP m1_, SEXP m2_, SEXP od1_, SEXP od2_){
    
    double m1 = as<double>(m1_);
    double m2 = as<double>(m2_);
    double od1 = as<double>(od1_);
    double od2 = as<double>(od2_);
    
    int N1 = 0; int N2 = 0; int i; int j; double corr;
    double SZ1 = 1/od1; double PB1 = SZ1/(SZ1+m1);
    double SZ2 = 1/od2; double PB2 = SZ2/(SZ2+m2);
    while(R::pnbinom(N1, SZ1, PB1, 1, 0) < 1)   N1 += 1;
    while(R::pnbinom(N2, SZ2, PB2, 1, 0) < 1)   N2 += 1;
    if(N1 > 9000) return(wrap(100));
    if(N2 > 9000) return(wrap(100));
    arma::mat Exytmp(N1, N2);
    for (i=0; i<N1; i++){
        for (j=0; j<N2; j++){
            Exytmp(i,j) = 1-R::fmax2(R::pnbinom(i, SZ1, PB1, 1, 0), 
                   R::pnbinom(j, SZ2, PB2, 1, 0));
        }
    }
    corr = (arma::accu(Exytmp)-m1*m2)/(sqrt(m1*m2*(1+od1*m1)*(1+od2*m2)));
    return wrap(corr);
}

/*** R
FHUBNB2(4,6,9,11)   # any numbers. it is just for testing the function
*/
