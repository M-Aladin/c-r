///////////////////////////////////////////////////////////////////////////////
// Simplest 2D convolution routine. It is easy to understand how convolution
// works, but is very slow, because of no optimization.
///////////////////////////////////////////////////////////////////////////////
// http://www.songho.ca/dsp/convolution/convolution.html
#include <Rcpp.h> 
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector convolve2D(NumericMatrix input, NumericMatrix kernel) {

    int dataSizeX   = input.ncol();
    int dataSizeY   = input.nrow();
    int kernelSizeX = kernel.ncol();
    int kernelSizeY = kernel.nrow();
    
    int nab = dataSizeX * kernelSizeX;
    
    NumericVector out(2*dataSizeX-1 + 2*dataSizeY-1);
  
    int i, j, m, n, mm, nn;
    int kCenterX, kCenterY;                         // center index of kernel
    float sum;                                      // temp accumulation buffer
    int rowIndex, colIndex;

    // check validity of params
    // if(!input || !out || !kernel) return false;
    if(dataSizeX <= 0 || kernelSizeX <= 0) return 0;

    // find center position of kernel (half of kernel size)
    kCenterX = kernelSizeX / 2;    // cols
    kCenterY = kernelSizeY / 2;    // rows

    for(i = 0; i < dataSizeY; ++i)                // rows
    {
        for(j = 0; j < dataSizeX; ++j)            // columns
        {
            sum = 0;                            // init to 0 before sum
            for(m = 0; m < kernelSizeY; ++m)      // kernel rows
            {
                mm = kernelSizeY - 1 - m;       // row index of flipped kernel

                for(n = 0; n < kernelSizeX; ++n)  // kernel columns
                {
                    nn = kernelSizeX - 1 - n;   // column index of flipped kernel

                    // index of input signal, used for checking boundary
                    rowIndex = i + m - kCenterY;
                    colIndex = j + n - kCenterX;

                    // ignore input samples which are out of bound
                    if (rowIndex >= 0 && rowIndex < dataSizeY && colIndex >= 0 && colIndex < dataSizeX)
                        // out(i, j) += input(rowIndex, colIndex) * kernel(mm, nn);
                        sum += input[dataSizeX * rowIndex + colIndex] * kernel[kernelSizeX * mm + nn];
                        //sum += input(dataSizeX*rowIndex, colIndex) * kernel(kernelSizeX*mm, nn);
                }
            }
            // out[dataSizeX * i + j] = (unsigned char)((float)fabs(sum) + 0.5f);
            // out[dataSizeX * i + j] = (int)((float)fabs(sum) + 0.5f);
            //out(dataSizeX * i, j) = (int)((float)fabs(sum) + 0.5f);
            // out(i, j) += input(rowIndex, colIndex) * kernel(mm, nn);
            out[dataSizeX * i + j] = sum;
        }
    }

    return out;
}
