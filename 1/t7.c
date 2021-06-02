#include <stdio.h>
#include <string.h>

int main()
{
    int i=0;
    int a=0;
    
    while (scanf("%d",&i) != EOF)
    {
        for (a=0;a<i;a++)
        {
            printf("#");
        }
        printf("\n");
    }
}