void cconv2 (int *l, int *m, double *x, int *n, double *s)
{
double *y, *z, *u;
int i;
for (i = 0; i < *m; i++)
{
y = x + (*n - l[i]);
z = x + l[i];
u = x;
s[i] = 0.0;
while (u < y)
   s[i] += *u++ * *z++;
}
}
