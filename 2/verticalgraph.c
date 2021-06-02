#include <stdio.h>
int main()

{
	int i=0;
    int j=0;
    int x=0;
    int max=0;
    int input;  
    int a[80]={-2};
    while (scanf("%d", &input) != EOF)
    {
      a[i]=input;
      i++;
      x++;
    }  
	for (i=0;i<=x-1;i++)
	{
		if (a[i]>max)
		{
			max = a[i];
		}
	}
	for (i=0;i<=x-1;i++)
	{
		a[i]=max-a[i];
	}
	for (i=0;i<=max-1;i++)
	{ 		
 		for (j=0;j<=x-1;j++)
 		{
 			if (a[j]>0)
	 		{
	 			printf(" ");
	 		}
	 		else if (a[j]<=0)
	 		{
	 			printf("#");
	 		}	 		
 		}
 		printf("\n");
 		for (j=0;j<=x-1;j++)
		{
			a[j]=a[j]-1;
		}
	}
	return 0;
}