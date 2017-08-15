// Hello world v. 1.0
// Apr. 18 2011
// (your name)
// This program tests the C++ environment


#include <iostream>
#include <windows.h>
#include <Rcpp.h>

using namespace std;

// [[Rcpp::export]]
int main ( ) {
    cout << "Hello World" << endl;
    //Sleep(4000);
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
main()
*/
