
#include <stdio.h>

void main() 
{ 
	int a, b, c; 
	int ch=1;

	while(ch)
	{
		printf("���� A �� �Է��ϼ���:"); 
		scanf("%d", &a); 
		printf("���� B �� �Է��ϼ���:"); 
		scanf("%d",&b); 
		printf("���� C �� �Է��ϼ���:"); 
		scanf("%d",&c); 

		if (a==b && b==c && c==a) 
			printf("�߰��� 3�� ����\n"); 
		else if (a==b || a==c || b==c) 
			printf("�߰��� 2�� ����\n"); 
		else if(a > b && a > c) 
			printf("a�� ���� ũ�� \n"); 
		else if(c > a && c > b) 
			printf(" c�� ���� ũ�� \n"); 
		else 
			printf("b�� ���� ũ�� \n"); 

		printf("Input 0 is program end.\n");
		scanf("%d", &ch);
	}
}  
