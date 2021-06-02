#include <stdio.h>
#include <math.h>

int main( void)
{
	float i;
	while ( scanf("%f", &i)!= EOF)
	{
        printf( "%.0f %.0f %.0f\n", floor(i), round(i), ceil(i));  
	}
	printf("Done.\n");

	return 0;
}