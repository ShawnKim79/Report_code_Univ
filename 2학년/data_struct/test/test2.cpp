
#include <stdio.h>

void main() 
{ 
	int a, b, c; 
	int ch=1;

	while(ch)
	{
		printf("숫자 A 를 입력하세요:"); 
		scanf("%d", &a); 
		printf("숫자 B 를 입력하세요:"); 
		scanf("%d",&b); 
		printf("숫자 C 를 입력하세요:"); 
		scanf("%d",&c); 

		if (a==b && b==c && c==a) 
			printf("중간값 3개 존재\n"); 
		else if (a==b || a==c || b==c) 
			printf("중간값 2개 존재\n"); 
		else if(a > b && a > c) 
			printf("a가 제일 크다 \n"); 
		else if(c > a && c > b) 
			printf(" c가 제일 크다 \n"); 
		else 
			printf("b가 제일 크다 \n"); 

		printf("Input 0 is program end.\n");
		scanf("%d", &ch);
	}
}  
