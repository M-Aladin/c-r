/* File : matprod1 .c: Calculate the product of matrices X and Y */
void matprod1 ( double *X , int *dimX , double *Y , int *dimY , double *ans ){
  double sum ;
  int ii , jj , kk ;
  
  // calculate the number of rows and columns of the matrices
  int nrX = dimX[0], ncX = dimX[1], nrY = dimY[0], ncY = dimY[1];
  
  for ( ii = 0; ii < nrX ; ii ++) {
    for ( jj = 0; jj < ncY ; jj ++) {
      sum = 0;
       for ( kk = 0; kk < ncX ; kk ++) {
          sum = sum + X[ ii + nrX * kk ] * Y[ kk + nrY * jj ];
       }
       ans [ ii + nrX * jj ] = sum ;
     }
   }
}