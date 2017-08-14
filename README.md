# README





## C to R programming
Examples of C, C++ code that can be called from R.

## Libraries used and required
* inline
* Rcpp
* RcppArmadillo


## Methods

* Use notebooks to call C++ code with `sourceCpp`

* Use notebook to show and run inline code

* C++ code located under `./src` folder contain `R` that run the functions in the same script

* C code cannot be run from within the C script. It msu be compiled first. 
Example: to run the function `bessel`:

`system("R CMD SHLIB ../src/bessel.c")` # compile

`dyn.load(paste("../src/bessel", .Platform$dynlib.ext, sep = ""))` # load
