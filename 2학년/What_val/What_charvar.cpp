#include<stdio.h>

/*
C++ ������ �������� �������̶� �͵� �ִ�.
*/

void main()
{
	/* ������ ���� */
	char char_1;
	
	printf("���� char_1 �� ���� ���ڷ� �Է��Ͻÿ�: ");
	scanf("%c", &char_1);
	printf("���� char_1 �� �� = %c \n", char_1);

	printf("���� char_1�� ���� ���������� �Է��Ͻÿ�: ");
	scanf("%d", &char_1);
	printf("���� char_1 �� �� = %c \n", char_1);

	
	printf("char�� ������ ���� ���� : %d byte \n", sizeof(char));
}