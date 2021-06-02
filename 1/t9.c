#include <stdio.h>
#include <math.h>

int main ()
{
    int x;
    int z;
    int h;
    int j;
    int i;
    int n;
    scanf("%d", &x);
	scanf("%d", &z);
	scanf("%d", &h);
    
    for (j=h-1;j>=0;j--)
    {
        int left = floor( j * (x/(2.0*h)) );
        for (i=0;i<x;i++)
        {
            if (j==0)
            {
                if (i<left)
                {
                    printf(" ");
                }
                else if (i>x-left-1)
                {
                    printf("");
                }
                else
                {
                    printf("#");
                }
            }
            else if (j>0 && j<h-1)
            {
                if (i<left)
                {
                    printf(" ");
                }
                else if (i>x-left-1)
                {
                    printf("");
                }
                else if (i == left)
                {
                    printf("#");
                }
                else if (i == x-left-1)
                {
                    printf("#");
                }
                else
                {
                    printf(".");
                }
            }
            else if (j==h-1)
            {
                if (i<left)
                {
                    printf(" ");
                }
                else if (i>x-left-1)
                {
                    printf("");
                }
                else
                {
                    printf("#");
                }
            }
        }
        printf("\n");
    }
    return 0;
}