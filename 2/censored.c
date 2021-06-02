#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int j, i=0;
	char word[256];
	int found = 0;
    char ch = getc(stdin);
    while (ch != -1)
	{
		if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch == '\''))
		{	
			word[i] = ch;  //getc adds each letter to form a word
			word[i+1] = 0;
			i++;
		}
		else
		{
			if (i > 0)
			{	
				found = 0;
				for (j = 1; j < argc; j++)
				{
					if (strcmp(argv[j], word) == 0)
					{
						found = 1;
						printf("CENSORED");
					}
				}
				if (found == 0)
					{
					printf("%s", word);
					}                 
				//word[0] = 0;
				i = 0;
			}
			putc(ch, stdout);  //prints nonwords
		}
		ch = getc(stdin);
    }
    return(0);
}