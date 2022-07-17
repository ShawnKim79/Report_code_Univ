#include<stdio.h>

int x=10; // Global_Val;

void Glo_x();

void main()
{


	for(int x=30 ; x<40 ; x++)
		printf("In for literary is x-value : %d \n", x);

	printf("Out for literary is x-value : %d \n", x);

	Glo_x();

}

void Glo_x()
{
	printf("In function literary is x-value : %d \n", x);
}