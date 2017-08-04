#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
bool convolve2DSlow(unsigned char* in, unsigned char* out, int dataSizeX, int dataSizeY,
                    float* kernel, int kernelSizeX, int kernelSizeY)
{
  int i, j, m, n, mm, nn;
  int kCenterX, kCenterY;                         // center index of kernel
  float sum;                                      // temp accumulation buffer
  int rowIndex, colIndex;
  
  // check validity of params
  if(!in || !out || !kernel) return false;
  if(dataSizeX <= 0 || kernelSizeX <= 0) return false;
  
  // find center position of kernel (half of kernel size)
  kCenterX = kernelSizeX / 2;
  kCenterY = kernelSizeY / 2;
  
  for(i=0; i < dataSizeY; ++i)                // rows
  {
    for(j=0; j < dataSizeX; ++j)            // columns
    {
      sum = 0;                            // init to 0 before sum
      for(m=0; m < kernelSizeY; ++m)      // kernel rows
      {
        mm = kernelSizeY - 1 - m;       // row index of flipped kernel
        
        for(n=0; n < kernelSizeX; ++n)  // kernel columns
        {
          nn = kernelSizeX - 1 - n;   // column index of flipped kernel
          
          // index of input signal, used for checking boundary
          rowIndex = i + m - kCenterY;
          colIndex = j + n - kCenterX;
          
          // ignore input samples which are out of bound
          if(rowIndex >= 0 && rowIndex < dataSizeY && colIndex >= 0 && colIndex < dataSizeX)
            sum += in[dataSizeX * rowIndex + colIndex] * kernel[kernelSizeX * mm + nn];
        }
      }
      out[dataSizeX * i + j] = (unsigned char)((float)fabs(sum) + 0.5f);
    }
  }
  
  return true;
}