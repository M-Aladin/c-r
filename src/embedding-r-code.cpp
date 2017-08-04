#include <Rcpp.h>


// [[Rcpp::export]]

int fibonacci(const int x) {
  if (x < 2)
    return x;
  else
    return (fibonacci(x -1) + fibonacci(x-2));
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
fibonacci(10)
*/
