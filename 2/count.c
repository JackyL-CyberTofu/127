#include <stdio.h>

int main ()
{
    unsigned long int charcount = 0, wordcount = 0, linecount = 0;
    char input;
    int x = 0;

    while ((input = getchar()) != EOF)
    {
        charcount++;
        
        if (input == 10) {
            linecount++;
            x = 0;
        }
        
    else if ( (input >= 65 && input <= 90) || (input >= 97 && input <= 122) || (input == 39)) {
        if (x == 0) //Checks if the last input was also a letter
        {
            wordcount ++;
        }
        x = 1; //Stays letter
    }
        
    else {
        x = 0; //Not a letter
    }   
    }
    printf("%lu %lu %lu\n", charcount, wordcount, linecount);
}