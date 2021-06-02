#include <stdio.h>
#include <stdlib.h>

int* a_getStudentNumber(int digits){
	//initialize output array
	int *studentNumber = malloc(digits);
	if(!studentNumber)return NULL;

	int a = 0;
	while(a < digits){
		scanf("%d", &studentNumber[a]);
		a++;		
	}
	return studentNumber;
}

int* getStudentNumber(int digits)
{
int* arr = malloc(digits);
for (int i =0; i<digits; i++)
	scanf("%d", &arr[i]);
return arr;
}


int main( void )
{
	int numOfDigits = 10;
	int sum = 0;
	int* theNumber = getStudentNumber( numOfDigits );

	for (int i = 0; i < numOfDigits; i++){
		printf("input %d is %d\n", i, theNumber[i]);
        sum += theNumber[i];
	}

    printf("%d\n", sum);
	if(sum % 2 == 0){
		printf("Valid\n");
	}
	else{
		printf("Invalid\n");
	}

	free( theNumber );
	return 0;
}