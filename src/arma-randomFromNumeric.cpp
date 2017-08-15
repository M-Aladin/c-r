// https://stackoverflow.com/questions/26384959/rcpp-r-sample-equivalent-from-a-numericvector

#include <RcppArmadilloExtensions/sample.h>
// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;
using namespace arma;
using namespace std;

// [[Rcpp::export]]
int simulateNextStepC(double currentAmount, double lastPaid, 
                      int currentStatus, int currentMaturity, 
                      NumericMatrix amountLinkMatrix, 
                      NumericMatrix statusMatrix, 
                      double percentile4Capping=1, 
                      bool verbose=false)
{
    int nrow = amountLinkMatrix.nrow(), outsize;
    
    bool check;
    LogicalVector positionsToSample(nrow); 
    
    for(int i=0; i<nrow; i++) {
        check = false;
        check = ((statusMatrix(i,currentMaturity)==currentStatus) &&
            (is_finite(statusMatrix(i,currentMaturity+1))));
        positionsToSample[i] = check;
    }
    
    outsize = sum(positionsToSample);
    
    IntegerVector historicalStatus(max(outsize,1));
    int out;
    if( outsize==0 ) {
        out=currentStatus; 
    } else { 
        for(int i=0, j=0; i<nrow; i++) {
            if( positionsToSample[i] ) {
                historicalStatus[j]=statusMatrix(i,currentMaturity+1);
                j++;
            }
        }
        out=as<int>(Rcpp::RcppArmadillo::sample(historicalStatus,1,false));
    }
    return out;
}

/*** R
simulateNextStepC(1000, 700, 500, 300, 
                  matrix(999, 3, 3), matrix(500, 3, 3))
*/
