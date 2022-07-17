#include<stdio.h>

/*
C++ 에서의 변수형은 크게 정수형(int)과 실수형(float)으로 나뉜다.
*/

void main()
{
	/* 정수형 변수 */
	int integer_1;
	unsigned int integer_2;

	printf("변수 integer_1 의 값을 입력하시오: ");
	scanf("%d", &integer_1);
	printf("변수 integer_1 의 값 = %d \n", integer_1);

	printf("변수 integer_2(단, 부호가 존재하지 않습니다.)의 값을 입력하시오: ");
	scanf("%d", &integer_2);
	printf("변수 integer_2 의 값 = %d \n", integer_2);

	
	printf("일반적인 int가 가지는 값의 범위 : %d byte \n", sizeof(int));
	printf("unsigned int가 가지는 값의 범위 : %d byte \n", sizeof(unsigned int));

	printf("변수 integer_1 의 값을 2147483647로 입력하시오: ");
	scanf("%d", &integer_1);
	printf("변수 integer_1 의 값 = %d \n", integer_1);

	printf("변수 integer_1 의 값을 4294967295로 입력하시오: ");
	scanf("%d", &integer_1);
	printf("변수 integer_1 의 값 = %d \n", integer_1);

	printf("변수 integer_2(부호가 존재하지 않습니다)의 값을 4294967295로 입력하시오: ");
	scanf("%u", &integer_2);
	printf("변수 integer_2 의 값 = %u \n", integer_2);

	printf("변수 integer_2(부호가 존재하지 않습니다)의 값을 4294967300로 입력하시오: ");
	scanf("%u", &integer_2);
	printf("변수 integer_2 의 값 = %u \n", integer_2);

}