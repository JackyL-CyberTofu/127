#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char *argv[] )
{
    char *answer;
    char *first = argv[1];
    char *second = argv[2];    
    answer = strstr(first, second);
    
    if (answer != NULL)
    {
    	printf("true\n");
    }
    
    else 
    {
    	printf("false\n");
    }
}