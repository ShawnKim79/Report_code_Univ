#include <stdio.h>

int pivo(int);

void main()
{
	int number;				  // number=피보나치를 구할 수 
	int value1, value2;       // value1=순환, value2=반복

	value2=1;

	printf("Input Number : ");
	scanf("%d", &number);	  // number에 값 입력

	if (number <= 1)
		printf("Value is 1"); // number가 1이거나 1보다 작을때 1 출력.

	if (number > 1)
	{
		value1=number*pivo(number-1);

		for (int i=1 ; i<=number ; i++)
		{
			value2 = value2*i;
		}

	}

	printf("Pivonach Number is Loop function: %d \n", value1);
	printf("Pivonach Number is Repeat function: %d \n", value2);

}

int pivo(int x)
{
	if(x > 1)				// x(즉, number-1)가 1보다 클때
		return x*pivo(x-1); // (number-1)*(number-2)를 return.
	else					// x(즉, number-1)가 1보다 작으면
		return 1;			// 1을 return.
}


