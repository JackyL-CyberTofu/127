#include <stdio.h>
#include <string.h>

int main()
{
	char i;
	int sum = 0;
	char abc [26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char ABC [26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int total [26] = {0};
	char letter;
	float freq;
	
	while ((i = getchar()) != EOF)
    {
        for (int k = 0; k<26; k++)
        {
            if (i == abc[k])
            {
                total[k] += 1;
            }
            else if (i == ABC[k])
            {
                total[k] += 1;
            }
        }       
	}
	for ( i=0; i<=25; i++)
    {
        sum += total[i];
    }
	for ( i=0; i<=25; i++)
    {
        if (total[i] != 0)
        {
            printf("%c %.4f\n", abc[i], (double)total[i]/(double)sum);
            //Double to store variables
        }
    }
}
			
