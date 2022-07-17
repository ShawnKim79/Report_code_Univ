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


// �������� ���μ��� ����ü ����.
for (count = 1 ; count < 4 ; count++)
{
	Process_blk *p_Newprocess;
	p_Newprocess = new Process_blk;

	printf("=====================================\n");
	printf("===== %d ��° ���μ��� �Է�==========\n", count);

	printf("���μ��� ��� �ð�(���μ��� ���̵�) : %d \n", count);
	p_Newprocess->n_time = count; // �̰� ���μ��� ���̵� ����Ѵ�.(�Էµ� ���� = ���μ��� ���̵�)
	
	printf("���μ��� �߿䵵 �Է� (1:�߿䵵 �� ~ 5:�߿䵵 ��) : ");
	scanf("%d", &p_Newprocess->n_rank);

	printf("���μ��� ����Ʈ �Է� : ");
	scanf("%d", &p_Newprocess->n_burst);

	p_Newprocess->n_wait = 0; // �����Ǵ� ���μ����� ��� Ÿ���� 0
	printf("���μ��� ��� �ð� : %d \n", p_Newprocess->n_wait);

	CFirst.Prio_in(p_Newprocess);
	CFirst.n_Priocount++;
	CFirst.n_processcount++;
}

CFirst.n_Prioburst = 0;

printf("\n\n");
printf("���μ��� ��ŸƮ");
printf("\n\n");

while((CFirst.n_Priocount + CFirst.n_Rrcount + CFirst.n_Fcfscount))
{
	printf("\n==================�켱���� ť===========================\n");
	CFirst.Prio_process();

	gant_head = Gant_Prio.begin();
	Gant_Prio.push_back('O');

	gant_head = Gant_RR.begin();
	Gant_RR.push_back('-');

	gant_head = Gant_Fcfs.begin();
	Gant_Fcfs.push_back('-');

	printf("\n==================���� �κ� ť===========================\n");
	CFirst.RR_process();

	gant_head = Gant_Prio.begin();
	Gant_Prio.push_back('-');

	gant_head = Gant_RR.begin();
	Gant_RR.push_back('O');

	gant_head = Gant_Fcfs.begin();
	Gant_Fcfs.push_back('-');

	printf("\n==================���Լ��� ť===========================\n");
	CFirst.Fcfs_process();
	gant_head = Gant_Prio.begin();
	Gant_Prio.push_back('-');

	gant_head = Gant_RR.begin();
	Gant_RR.push_back('-');

	gant_head = Gant_Fcfs.begin();
	Gant_Fcfs.push_back('O');
//	getch();
}

printf("\n================���μ��� ���ð� ���=======================\n");

CFirst.n_waitave = (float)((float)CFirst.n_waitsum / (float)CFirst.n_processcount);

printf("��� ��սð� : %f \n", CFirst.n_waitave);

printf("\n================Gant Chart=======================\n");

Prio_size = Gant_Prio.size();
gant_head = Gant_Prio.begin();

printf(" �켱���� ť : ");
for(i=0 ; i < Prio_size; i++)
{
	cout << Gant_Prio.front();
	Gant_Prio.pop_front();
}
printf("\n");

RR_size = Gant_RR.size();
gant_head = Gant_RR.begin();
printf(" ����   ť : ");
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
printf(" ���Լ��� ť : ");
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