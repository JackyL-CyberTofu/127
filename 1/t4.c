#include <stdio.h>
#include <math.h>

int main()
{
    double i = -1;
    scanf("%lf", &i);
    if (i == -1)
    {
        printf("scanf error: (0)\n");
    } else {
        printf("%.0f %.0f %.0f\n", floor(i), round(i), ceil(i));
    }
    return 0;
}