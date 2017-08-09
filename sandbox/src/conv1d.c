#include <stddef.h>
#include <stdio.h>

#define max(x, y) (((x) > (y)) ? (x) : (y))

void conv1d(const double v1[], int n1, const double v2[], int n2, double r[])
{
    for (int n = 0; n < n1 + n2 - 1; n++)
        for (int k = 0; k < max(n1, n2); k++)
            r[n] += (k < n1 ? v1[k] : 0) * (n - k < n2 ? v2[n - k] : 0);
}