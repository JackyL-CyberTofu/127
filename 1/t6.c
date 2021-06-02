#include <stdio.h>
#include <math.h>

int main ()
{
    float i;
    float min;
    float max;
    float count;
    float avg;
    float total;

    scanf("%f",&i);
    min = i;
    max = i;
    count = 1;
    total = i;
    while (scanf("%f",&i) != EOF)
    {
        if (i < min)
        {
            min = i;
        }
        else if (i > max)
        {
            max = i;
        }
        count ++;
        total = total + i;
    }
    avg = total/count;
    printf("%.2f %.2f %.2f\n", min, max, avg);
}