#include <stdio.h>
#include <time.h>
#include <math.h>

double wish_move(int);

void main()
{
	int wish_number;
	double move_count;	 // 원반의 갯수, 움직인 횟수
	long start, stop, total_time;    // 시간 변수.

	printf("Input Wish Number : ");
	scanf("%d", &wish_number);

	time(&start);

	if (wish_number < 1){
		printf("Wish is NOT EXIST\n");
		move_count=0;
	}
	else
		move_count=pow((double)2, (double)(wish_number-1)) + wish_move(wish_number-1);

	time(&stop);
	total_time=stop-start;

	printf("Wish Move count is : %f \n", move_count);
	printf("Wish Move Time is : %d \n", total_time);

}

double wish_move(int x)
{
	if(x>0)
		return pow((double)2,(double)(x-1))+wish_move(x-1);
	else
		return 0;
}
