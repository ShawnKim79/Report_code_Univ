#include<stdio.h>

/*
C++ 에서의 변수형은 문자형이란 것도 있다.
*/

void main()
{
	/* 문자형 변수 */
	char char_1;
	
	printf("변수 char_1 의 값을 문자로 입력하시오: ");
	scanf("%c", &char_1);
	printf("변수 char_1 의 값 = %c \n", char_1);

	printf("변수 char_1의 값을 정수형으로 입력하시오: ");
	scanf("%d", &char_1);
	printf("변수 char_1 의 값 = %c \n", char_1);

	
	printf("char가 가지는 값의 범위 : %d byte \n", sizeof(char));
}