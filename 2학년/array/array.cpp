#include <stdio.h>
#include <string.h>


void output(int []);

void main()
{
	int array[10];
	for(int i=0 ; i<10 ; i++){
		printf("input %d th number : ", i);
		scanf("%d", &array[i]);
	}
	output(array);
}

void output(int array[])
{
	for(int j=0 ; j<10 ; j++){
		printf("input %dth number : %d \n", j, array[j]);
		
	}
}