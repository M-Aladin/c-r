/* File : matprod3 .c */
# include < R.h >
# include < R_ext/BLAS.h >

void matprod3 ( double *X , int * dimX , double *Y , int * dimY , double * ans ){

    int nrX = dimX [0] , ncX = dimX [1] , nrY = dimY [0] , ncY = dimY [1];
    
    char * transa = "N" , * transb = "N";
    double one = 1.0 , zero = 0.0;
    F77_CALL(dgemm)( transa , transb , & nrX , & ncY , & ncX , & one ,
     X , & nrX , Y , & nrY , & zero , ans , & nrX );
 }