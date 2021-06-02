#include <stdio.h>

int scrambled( unsigned int arr1[], unsigned int arr2[], unsigned int len )
{
    int i=0;
    int j=0;
    
    if (len == 0){
        return 1;
    }
    
    for (int i=0; i<len; i++){
        for (j=0; j<len; j++){
            if (arr1[i] == arr2[j]){
                arr1[i] = -2;
                arr2[j] = -2;
            }
        }
    }
    
    i=0;
    j=0;

    for (int i=0; i<len; i++){
        printf("%d\n",arr1[i]);
        if (arr1[i] != -2){
            return 0;
        }

    }
    return 1;
}

