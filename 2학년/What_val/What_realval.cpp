#include<stdio.h>

/*
C++ ������ �������� ũ�� ������(int)�� �Ǽ���(float)���� ������.
*/

void main()
{
	/* �Ǽ��� ���� */
	float float_1;
	double float_2=12345.8960;
	
	printf("���� float_1 �� ���� �Է��Ͻÿ�: ");
	scanf("%f", &float_1);
	printf("���� float_1 �� ��(f�� ���) = %f \n", float_1);
	printf("���� float_2 �� ��(f�� ���) = %f \n", float_2);

	printf("���� float_2 �� ���� �Է��Ͻÿ�: ");
	scanf("%f", &float_2);
	printf("���� float_2 �� ��(f�� ���) = %f \n", float_2);

	printf("���� float_1 �� ��(e�� ���) = %e \n", float_1);
	printf("���� float_2 �� ��(e�� ���) = %e \n", float_2);
	
	
	printf("�Ϲ����� float�� ������ ���� ���� : %d byte \n", sizeof(float));
	printf("double�� ������ ���� ���� : %d byte \n", sizeof(double));

}