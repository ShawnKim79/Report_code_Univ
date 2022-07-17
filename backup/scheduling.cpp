#include "Q.h"
#include <time.h>
#include <math.h>

#ifndef _stdio_h_
#define _stdio_h_
#endif

void main()
{

CPrio_Q CFirst;
CRR_Q CSecond;
CFCFS_Q CThird;


int count=0; 

// 동적으로 프로세스 구조체 생성.
for (count = 0 ; count < 3 ; count++)
{
	Process_blk *p_Newprocess;
	p_Newprocess = new Process_blk;

	printf("=====================================\n");
	printf("===== %d 번째 프로세스 입력==========\n", count+1);

	printf("프로세스 버스트 입력 : ");
	scanf("%d", &p_Newprocess->n_burst);

	printf("프로세스 중요도 입력 (1:중요도 상 ~ 5:중요도 하) : ");
	scanf("%d", &p_Newprocess->n_rank);

	printf("프로세스 등록 시간(프로세스 아이디) : %d \n", count);
	p_Newprocess->n_time = count; // 이게 프로세스 아이디를 대신한다.(입력된 순서 = 프로세스 아이디)
	
	p_Newprocess->n_wait = 0; // 생성되는 프로세스의 대기 타임은 0
	printf("프로세스 대기 시간 : %d \n", p_Newprocess->n_wait);

	CFirst.Prio_in(p_Newprocess);
	CFirst.n_processcount++;
}

while((CFirst.n_processcount + CSecond.n_processcount + CThird.n_processcount))
{
	CFirst.Prio_process();
	CSecond.RR_process();
	CThird.Fcfs_process();
}



}