#include <stdio.h>

int Loop_comp(int); // �Ѱ��� ���� �Ǻ���ġ �Լ�
int Loop_comp_minor(int , int); // �� ���� ������ �Ǻ���ġ �Լ�


void main()
{
	int up_number, down_number; // ����, �и� -> �Է� ��. 
	int up_piv, down_piv, up_down_piv; // �� �Ǻ���ġ �Լ��� �����Ų ���� ����.

	float total_value; // ���װ�� ��

	printf("input up number : ");
	scanf("%d", &up_number);
	printf("input down number : ");
	scanf("%d", &down_number);

	up_piv = Loop_comp(up_number);
	down_piv = Loop_comp(down_number);
	up_down_piv = Loop_comp_minor(up_number, down_number);

	total_value = (float)up_piv / (float)(down_piv-up_down_piv);

	printf("Binomial coefficient - up : %d \n", up_piv);
	printf("Binomial coefficient -down : %d \n", down_piv);
	printf("Binomial coefficient : %f \n", total_value);
}

int Loop_comp(int n)
{
	int i, count;
	i=1;

	for (count=1 ; count <=n ; count++){
		i=i*count;
	}

	return i;
}

int Loop_comp_minor(int n, int m)
{
	int i, count;
	i=1;

	for (count=1 ; count<=(n-m) ; count++){
		i=i*count;
	}

	return i;
}




