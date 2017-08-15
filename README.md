# README





## C to R programming
Examples of C, C++ functions that can be called from R.   
Mainly oriented to the use of C++ Armadillo.

## Libraries used and required
* inline
* Rcpp
* RcppArmadillo
* rbenchmark
* compiler


## Methods

* Use notebooks to:
    * call `C++` code with `sourceCpp`
    * show and run `C` code with `inline`
    * write directly C++ code in R chunks using `engine='Rcpp'`
    * run inline `C++` code with the `cxxfunction` function
    
    
* Use C, C++ files:
    * when these codes will be called from a notebook
    * the C++ files can have R calls 
    

* C++ code located under `./src` folder contain `R` that run the functions in the same script

* `R` code cannot be run from within the `C` file. It must be compiled first and called from a notebook or from an `R` script

> Example: to run the function `bessel`:


```r
system("R CMD SHLIB ../src/bessel.c")                             # compile

dyn.load(paste("../src/bessel", .Platform$dynlib.ext, sep = ""))  # load
```



## Comparison of R vs C++
There is a notebook, `Kalman.Rmd`, that compares different implementations of R code vs a single C++ program. The example uses C++ classes.

Other examples will have a description `benchmark` when performing a comparison between R functions and C++ functions.



## Findings

* `RcppArmadillo` is easier to understand and program than pure C++. It contains a types abstracton that makes it similar to Matlab/Octave.

* `Rcpp` can achieve the same results but would take mode development time than `RcppArmadillo`

* `RcppArmadillo` has a 3D type called `cube` which is a tensor of the third-level. Not all the matrix functions are implemented for the `cube` type.

* `RcppArmadillo` allows to write variables directly to files. It is also easy to print to the console using `cout <<` notation

* It is better to code the algorithm first in `R` and the translate it to C++

* `Rcpp` and `RcppArmadillo` types can be mixed but some do not carry over exactly well



## Observations

* Keep always in mind the array/matrix/vector indices; in C and C++ the index starts at `0`

* C code is called with the function .C()


## Benchmarks

* `arma-classes-simple-array.Rmd`
* `arma-cxxfunction-classes-kalman.Rmd`
* `arma-engine-pass_by_ref_by_value.Rmd`
* `arma-engine-pass_by_ref_by_value.Rmd`
* `arma-engine-simulate_multivariate.Rmd`



## Other

C++ 11 being used as well in couple of examples.
