#include <stdio.h>

int pivo(int);

void main()
{
	int number;				  // number=�Ǻ���ġ�� ���� �� 
	int value1, value2;       // value1=��ȯ, value2=�ݺ�

	value2=1;

	printf("Input Number : ");
	scanf("%d", &number);	  // number�� �� �Է�

	if (number <= 1)
		printf("Value is 1"); // number�� 1�̰ų� 1���� ������ 1 ���.

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
	if(x > 1)				// x(��, number-1)�� 1���� Ŭ��
		return x*pivo(x-1); // (number-1)*(number-2)�� return.
	else					// x(��, number-1)�� 1���� ������
		return 1;			// 1�� return.
}


