/* File : matprod4 .c */
#include <R.h>
#include <Rinternals.h>
//#include <Rdefines.h>
//#include <R_ext/BLAS.h>

SEXP matprod4 ( SEXP X , SEXP Y) {
    int nprot =0;
    PROTECT (X = AS_NUMERIC (X )); nprot ++;
    PROTECT (Y = AS_NUMERIC (Y )); nprot ++;
    double * xptr ; xptr = REAL (X );
    double * yptr ; yptr = REAL (Y );
    int * dimX ; dimX = INTEGER ( GET_DIM (X ));
    int * dimY ; dimY = INTEGER ( GET_DIM (Y ));
    
    SEXP ans ; PROTECT ( ans = allocMatrix ( REALSXP , dimX [0] , dimY [1])); nprot ++;
    double * ansptr ; ansptr = REAL ( ans );
    
     char * transa = "N" , * transb = "N";
     double one = 1.0 , zero = 0.0;
     F77_CALL(dgemm)( transa , transb , & dimX [0] , & dimY [1] , & dimX [1] , & one ,
     xptr , & dimX [0] , yptr , & dimY [0] , & zero , ansptr , & dimX [0]);
     UNPROTECT ( nprot );
     return ( ans );
 }
