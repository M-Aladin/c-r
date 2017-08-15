/*
 * Getting started with Armadillo a C++ Linear Algebra Library on Windows, Mac and Linux
 * https://solarianprogrammer.com/2017/03/24/getting-started-armadillo-cpp-linear-algebra-windows-mac-linux/
 */
#include <RcppArmadillo.h>
using namespace Rcpp; 
using namespace RcppArmadillo;
using namespace arma;


//[[Rcpp::depends(RcppArmadillo)]]
//[[Rcpp::export]]
 
 int run() {
    // Initialize the random generator
    //arma::arma_rng::set_seed_random();
    
    // Create a 4x4 random matrix and print it on the screen
    arma::Mat<double> A = arma::randu(4,4); 
    std::cout << "A:\n" << A << "\n";

     // Multiply A with his transpose:
     std::cout << "A * A.t() =\n"; 
     std::cout << A * A.t() << "\n";

     // Access/Modify rows and columns from the array:
     A.row(0) = A.row(1) + A.row(3);
     A.col(3).zeros();
     std::cout << "add rows 1 and 3, store result in row 0, also fill 4th"
         "column with zeros:\n";
     std::cout << "A:\n" << A << "\n";

     // Create a new diagonal matrix using the main diagonal of A:
     arma::Mat<double>B = arma::diagmat(A);
     std::cout << "B:\n" << B << "\n";

     // Save matrices A and B:
     A.save("A_mat.txt", arma::arma_ascii);
     B.save("B_mat.txt", arma::arma_ascii);
     
     return 0;
    }

/*** R
set.seed(123)
run()
*/
