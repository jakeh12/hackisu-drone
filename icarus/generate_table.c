#include <stdio.h>
#include <math.h>

int main()
{
  int i = 0;
  double res = 0;
  long int_res = 0;

  for (i = -720; i <= 720; i++)
  {
    res = floor(0.00000107167*i*i*i+1100);
    int_res = (long) res;
    printf("%ld,\n", int_res);
  }
  return 0;
}
