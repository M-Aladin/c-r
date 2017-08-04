// http://www.songho.ca/dsp/convolution/convolution.html
#include <Rcpp.h> 
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector convolve1D(NumericVector input, NumericVector kernel) {
  
    int i, j, k;
    int dataSize = input.size(), kernelSize = kernel.size();
    int nab = dataSize + kernelSize - 1;
    
    NumericVector out(nab);

    // check validity of params
    // if(!in || !out || !kernel) return false;
    if(dataSize <=0 || kernelSize <= 0) return 0;

    // start convolution from out[kernelSize-1] to out[dataSize-1] (last)
    for(i = kernelSize-1; i <= dataSize; ++i)
    {
        out[i] = 0;                             // init to 0 before accumulate
        for(j = i, k = 0; k < kernelSize; --j, ++k)
            out[i] += input[j] * kernel[k];
    }

    // convolution from out[0] to out[kernelSize-2]
    for(i = 0; i < kernelSize - 1; ++i)
    {
        out[i] = 0;                             // init to 0 before sum

        for(j = i, k = 0; j >= 0; --j, ++k)
            out[i] += input[j] * kernel[k];
    }

    return out;
}
