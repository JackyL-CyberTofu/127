#include <stdio.h>

int main()
{
    int i;
    int x;
    int y;
    int z;
    int horizontal;
    int vertical;

    scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
    
    for (vertical=0;vertical<y;vertical++)
    {
        if (x==0)
        {
            break;
        }
        if (y==0)
        {
            break;
        }
        if (vertical==0)
        {
            for (i=0;i<x;i++)
                {
                    printf("#");
                }

            printf("\n");
        }
        if (vertical == y-1 && y != 1)
        {
            for (i=0;i<x;i++)
                {
                    printf("#");
                }
            printf("\n");
        }
        if (vertical > 0 && vertical < y-1)
        {
            printf("#");
            for (i=0; i<x-2 ; i++)
                {
                    printf(".");
                }
            printf("#\n");
        }
    }
    return 0;
}