/* Compile with gcc -o expfun1 expfun1 .c */
#include <stdio.h>
#include <math.h>

int main () {
  char str [8];
  double x , ans =1.0;
  
  printf(" --- expfun1 ---\n" );
  printf(" enter x: " );
  fgets( str , sizeof( str ), stdin );
  sscanf( str , "%lf " , &x );
  
   double term =1.0 , eps =1e-16;
   int n =0;
   while ( fabs ( term )> eps ){
   n ++;
   term = term * x / n;
   ans = ans + term ;
   }
  
   double expx = exp (x );
   double rerr = ( ans - expx )/ expx ;
   printf (" input =% f ans =% f expx =% f rerr =% f\n" , x , ans , expx , rerr );
  }