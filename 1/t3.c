#include <stdio.h>
#include <math.h>

int main( void )
{
  double i = 0;
  scanf("%lf", &i);
  printf( "%.0f %.0f %.0f\n", floor(i), round(i), ceil(i));
  return 0;
}
