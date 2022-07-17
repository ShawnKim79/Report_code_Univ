#include<stdio.h>

/*
C++ 에서의 변수형은 크게 정수형(int)과 실수형(float)으로 나뉜다.
*/

void main()
{
	/* 실수형 변수 */
	float float_1;
	double float_2=12345.8960;
	
	printf("변수 float_1 의 값을 입력하시오: ");
	scanf("%f", &float_1);
	printf("변수 float_1 의 값(f로 출력) = %f \n", float_1);
	printf("변수 float_2 의 값(f로 출력) = %f \n", float_2);

	printf("변수 float_2 의 값을 입력하시오: ");
	scanf("%f", &float_2);
	printf("변수 float_2 의 값(f로 출력) = %f \n", float_2);

	printf("변수 float_1 의 값(e로 출력) = %e \n", float_1);
	printf("변수 float_2 의 값(e로 출력) = %e \n", float_2);
	
	
	printf("일반적인 float가 가지는 값의 범위 : %d byte \n", sizeof(float));
	printf("double가 가지는 값의 범위 : %d byte \n", sizeof(double));

}