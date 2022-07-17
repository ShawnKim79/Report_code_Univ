#include<stdio.h>

void main()
{
	int value_1,value_2,value_3;
	int count;
	value_1=value_2=value_3=0;

	// 1부터 100까지의 합.
	for(count=0 ; count<=100 ; count++)
		value_1=value_1+count;

	printf("1부터 100까지의 합 : %d \n", value_1);
		
	// 1부터 100까지 홀수들의 합.
	count=1;
	while(count<=100)
	{
		value_2=value_2+count;
		count+=2;
	}
	printf("1부터 100까지 홀수들의 합 : %d \n", value_2);

	// 1부터 100까지 짝수들의 합.
	count=0;
	do
	{
		count+=2;
		value_3=value_3+count;
	}while(count<=100);
	printf("1부터 100까지 짝수들의 합 : %d \n", value_3);
	
}