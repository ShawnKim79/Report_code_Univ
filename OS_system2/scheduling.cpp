#include "Q.h"
#include <time.h>
#include <math.h>
//#include <iostream.h>

#ifndef _stdio_h_
#define _stdio_h_
#endif

void main()
{
list< char> Gant_Prio;
list< char> Gant_RR;
list< char> Gant_Fcfs;

list<char>::iterator gant_head;

//gant_head = Gant_Prio.begin();

C_Q CFirst;

CFirst.n_waitsum = 0;
CFirst.n_processcount = 0;

int count=0; 
int i=0;
int Prio_size;
int RR_size;
int Fcfs_size;

//char gant_mark;


// 동적으로 프로세스 구조체 생성.
for (count = 1 ; count < 4 ; count++)
{
	Process_blk *p_Newprocess;
	p_Newprocess = new Process_blk;

	printf("=====================================\n");
	printf("===== %d 번째 프로세스 입력==========\n", count);

	printf("프로세스 등록 시간(프로세스 아이디) : %d \n", count);
	p_Newprocess->n_time = count; // 이게 프로세스 아이디를 대신한다.(입력된 순서 = 프로세스 아이디)
	
	printf("프로세스 중요도 입력 (1:중요도 상 ~ 5:중요도 하) : ");
	scanf("%d", &p_Newprocess->n_rank);

	printf("프로세스 버스트 입력 : ");
	scanf("%d", &p_Newprocess->n_burst);

	p_Newprocess->n_wait = 0; // 생성되는 프로세스의 대기 타임은 0
	printf("프로세스 대기 시간 : %d \n", p_Newprocess->n_wait);

	CFirst.Prio_in(p_Newprocess);
	CFirst.n_Priocount++;
	CFirst.n_processcount++;
}

CFirst.n_Prioburst = 0;

printf("\n\n");
printf("프로세스 스타트");
printf("\n\n");

while((CFirst.n_Priocount + CFirst.n_Rrcount + CFirst.n_Fcfscount))
{
	printf("\n==================우선순위 큐===========================\n");
	CFirst.Prio_process();

	gant_head = Gant_Prio.begin();
	Gant_Prio.push_back('O');

	gant_head = Gant_RR.begin();
	Gant_RR.push_back('-');

	gant_head = Gant_Fcfs.begin();
	Gant_Fcfs.push_back('-');

	printf("\n==================라운드 로빈 큐===========================\n");
	CFirst.RR_process();

	gant_head = Gant_Prio.begin();
	Gant_Prio.push_back('-');

	gant_head = Gant_RR.begin();
	Gant_RR.push_back('O');

	gant_head = Gant_Fcfs.begin();
	Gant_Fcfs.push_back('-');

	printf("\n==================선입선출 큐===========================\n");
	CFirst.Fcfs_process();
	gant_head = Gant_Prio.begin();
	Gant_Prio.push_back('-');

	gant_head = Gant_RR.begin();
	Gant_RR.push_back('-');

	gant_head = Gant_Fcfs.begin();
	Gant_Fcfs.push_back('O');
//	getch();
}

printf("\n================프로세스 대기시간 결과=======================\n");

CFirst.n_waitave = (float)((float)CFirst.n_waitsum / (float)CFirst.n_processcount);

printf("대기 평균시간 : %f \n", CFirst.n_waitave);

printf("\n================Gant Chart=======================\n");

Prio_size = Gant_Prio.size();
gant_head = Gant_Prio.begin();

printf(" 우선순위 큐 : ");
for(i=0 ; i < Prio_size; i++)
{
	cout << Gant_Prio.front();
	Gant_Prio.pop_front();
}
printf("\n");

RR_size = Gant_RR.size();
gant_head = Gant_RR.begin();
printf(" 라운드   큐 : ");
for(i=0 ; i < RR_size ; i++)
{
	//gant_mark = Gant_RR.front();
	//Gant_RR.pop_front();
	//printf("%c", &gant_mark);
	cout << Gant_RR.front();
	Gant_RR.pop_front();
}
printf("\n");

Fcfs_size = Gant_Fcfs.size();
gant_head = Gant_Fcfs.begin();
printf(" 선입선출 큐 : ");
for(i=0 ; i < Fcfs_size ; i++)
{
	//gant_mark = Gant_Fcfs.front();
	//Gant_Fcfs.pop_front();
	//printf("%c", &gant_mark);
	cout << Gant_Fcfs.front();
	Gant_Fcfs.pop_front();
}
printf("\n");

}