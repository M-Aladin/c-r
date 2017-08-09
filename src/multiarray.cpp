// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

// We can now use the BH package
// [[Rcpp::depends(BH)]]

#include <Rcpp.h>
#include "boost/multi_array.hpp"
#include <cassert>

using namespace Rcpp;
using namespace boost;

typedef boost::multi_array<double, 3> array_type;
typedef array_type::index index;

// [[Rcpp::export]]
array_type
    multiarray () {
        // Create a 3D array that is 3 x 4 x 2
        // typedef boost::multi_array<double, 3> array_type;
        // typedef array_type::index index;
        
        array_type A(boost::extents[3][4][2]);
        
        // Assign values to the elements
        int values = 0;
        for(index i = 0; i != 3; ++i) 
            for(index j = 0; j != 4; ++j)
                for(index k = 0; k != 2; ++k)
                    A[i][j][k] = values++;
        
        // Verify values
        int verify = 0;
        for(index i = 0; i != 3; ++i) 
            for(index j = 0; j != 4; ++j)
                for(index k = 0; k != 2; ++k)
                    assert(A[i][j][k] == verify++);
        
        return(wrap(A));
    }

/*** R
# timesTwo(42)
multiarray()
*/
