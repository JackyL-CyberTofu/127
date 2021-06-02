#include <stdio.h>

void reverse(int arr[], unsigned int len)
{
  int orig1, orig2;
  
  if (len%2 == 0)
  {
    for (int i=0; i<len/2; i++)
    {
      orig1 = arr[i];
      orig2 = arr[len-1-i];
      arr[i] = orig2;
      arr[len-1-i] = orig1;
    }
  }

  else
  {
    for (int i=0; i<(len-1)/2; i++)
    {
      orig1 = arr[i];
      orig2 = arr[len-1-i];
      arr[i] = orig2;
      arr[len-1-i] = orig1;
    }
  }
}
