#include<stdio.h>

/*
C++ ������ �������� ũ�� ������(int)�� �Ǽ���(float)���� ������.
*/

void main()
{
	/* ������ ���� */
	int integer_1;
	unsigned int integer_2;

	printf("���� integer_1 �� ���� �Է��Ͻÿ�: ");
	scanf("%d", &integer_1);
	printf("���� integer_1 �� �� = %d \n", integer_1);

	printf("���� integer_2(��, ��ȣ�� �������� �ʽ��ϴ�.)�� ���� �Է��Ͻÿ�: ");
	scanf("%d", &integer_2);
	printf("���� integer_2 �� �� = %d \n", integer_2);

	
	printf("�Ϲ����� int�� ������ ���� ���� : %d byte \n", sizeof(int));
	printf("unsigned int�� ������ ���� ���� : %d byte \n", sizeof(unsigned int));

	printf("���� integer_1 �� ���� 2147483647�� �Է��Ͻÿ�: ");
	scanf("%d", &integer_1);
	printf("���� integer_1 �� �� = %d \n", integer_1);

	printf("���� integer_1 �� ���� 4294967295�� �Է��Ͻÿ�: ");
	scanf("%d", &integer_1);
	printf("���� integer_1 �� �� = %d \n", integer_1);

	printf("���� integer_2(��ȣ�� �������� �ʽ��ϴ�)�� ���� 4294967295�� �Է��Ͻÿ�: ");
	scanf("%u", &integer_2);
	printf("���� integer_2 �� �� = %u \n", integer_2);

	printf("���� integer_2(��ȣ�� �������� �ʽ��ϴ�)�� ���� 4294967300�� �Է��Ͻÿ�: ");
	scanf("%u", &integer_2);
	printf("���� integer_2 �� �� = %u \n", integer_2);

}