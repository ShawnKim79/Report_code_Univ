#include <stdio.h>
#include <iostream>
#include <list>
//#include "init_class.h"

using namespace std;

typedef struct
{
	unsigned int n_rank; // ���μ��� �켱����
	unsigned int n_time; // �����ð�.
	unsigned int n_burst; // ����Ʈ �ð�.
	int n_wait; // ���ð�.

}Process_blk;

//static Process_blk *s_jumpQ = NULL; // Ŭ������ ��� ���� ���� ����, �ӽ÷� �����ϴ� ���μ��� ����.

// �켱���� ���� ť - ��� ���μ����� �̰ɷ� ����.
class CPrio_Q 
{

public:
	unsigned int n_processcount; // ���� ť ���� ���μ��� ����
	list<Process_blk *>::iterator Prio_head;
	
	void Prio_in(Process_blk *Temp);
	//Process_blk Prio_out();
	void Prio_process();

private:
	list<Process_blk *> Prio_Q;
};

// ���� �κ� - �켱���� ���� ����� �ι�° ������.
class CRR_Q
{
public:
	unsigned int n_processcount; // ���� ť ���� ���μ��� ����
	list<Process_blk *>::iterator Rr_head;
	
	void RR_in(Process_blk *Temp);
	//Process_blk RR_out();
	void RR_process();

private:
	list<Process_blk *> RR_Q;
};

// ���� ���� ť - ������ ó��.
class CFCFS_Q 
{
public:
	unsigned int n_processcount; // ���� ť ���� ���μ��� ����
	list<Process_blk *>::iterator Fcfs_head; // ����Ʈ�� ���� ������.
	
	void Fcfs_in(Process_blk *Temp);
	//Process_blk Fcfs_out();
	void Fcfs_process();

private:
	list<Process_blk *> FCFS_Q;
};

/* FCFS Part ********************************************************/
/******************************************************************
FCFS�� ��� : ��� �־����� ��� ó�� �ع� ������.
�߿伺 ���� ���. ������ ��ٸ� �ڽĵ� �׷��� ��� ��� ó��.
���������� ���� ����� �α׸� ��� ����.
  ******************************************************************/

void CFCFS_Q::Fcfs_in(Process_blk *Temp)
{
	FCFS_Q.push_front(Temp);
	
}

void CFCFS_Q::Fcfs_process()
{
	n_processcount = FCFS_Q.size();
	Process_blk *Temp;

	Fcfs_head = FCFS_Q.end();

	for(Fcfs_head ; Fcfs_head != FCFS_Q.begin() ; Fcfs_head--)
	{
		Temp = FCFS_Q.back(); // ���� �������� ���μ����� ����.
		
		Temp->n_burst=0; // �Ѹ����, ���� ���� ���μ����� ���� ��ģ�ٴ� �Ҹ�.

		printf("==================���Լ��� ť===========================");
		printf("%d ��° ���μ����� ����Ǿ����ϴ�.\n", Temp->n_time);
		printf("����� ���μ��� ����\n");
		printf("���μ��� ���̵� : %d \n", Temp->n_time);
		printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
		
		//FCFS_Q.AddNode(Temp); // ó���� ��带 �ٽ� ����...�� �ƴ϶� ����ؾ���.(�̱���)
		
	}
	n_processcount = FCFS_Q.size();
	
}

/* Priority Part***********************************************************/
/******************************************************************
Priority�� ��� : �켱���� ���� ���μ���.
�߿伺 ���� ��鸸 ó��. �߿伺 ���� ��� ī��Ʈ 5 �Ѿ ����� �˴� RR�� �̵�.
1,2 : �߿� / 3,4,5 : ���߿�.
  ******************************************************************/
void CPrio_Q::Prio_in(Process_blk *Temp)
{

	Prio_Q.push_back(Temp);
}

void CPrio_Q::Prio_process()
{
	n_processcount = Prio_Q.size();
	Process_blk *Temp;
	
	Prio_head = Prio_Q.end();
		
	for(Prio_head ; Prio_head != Prio_Q.begin(); Prio_head--)
	{
		//Temp = *Prio_head;
			
		Temp = Prio_Q.back(); // ���� �������� ���μ����� ����.
		
		// ���μ����� �߿伺�� ���� ó��.
		if(Temp->n_rank < 3) // �߿䵵 2 �����϶�.
		{
			Temp->n_burst--;

			printf("==================�켱���� ť===========================");
			printf("%d ��° ���μ���ó���� .\n", Temp->n_time);
			printf("���μ��� ����\n");
			printf("���μ��� ���̵� : %d \n", Temp->n_time);
			printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
			printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
			printf("���μ��� ���ð� : %d \n", Temp->n_wait);

			Prio_Q.push_front(Temp); // ����Ʈ Ÿ�� ���̰�, �ٽ� ť�� �ִ´�.
		}
		else if(Temp->n_rank > 2 || Temp->n_wait < 5)  // �߿䵵 ������, �̶� ���ð��� 5 �Ѿ�� ó�� �� �ִ� ���� ����.
		{
			Temp->n_wait++; // ���ð� 1 ����.

			printf("==================�켱���� ť===========================");
			printf("%d ��° ���μ���ó���� .\n", Temp->n_time);
			printf("���μ��� ����\n");
			printf("���μ��� ���̵� : %d \n", Temp->n_time);
			printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
			printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
			printf("���μ��� ���ð� : %d \n", Temp->n_wait);

			Prio_Q.push_front(Temp);
		}
		else if(Temp->n_rank > 2 || Temp->n_wait > 5)
		{
			Temp->n_wait = 0;

			printf("==================�켱���� ť===========================");
			printf("%d ��° ���μ���ó���� .\n", Temp->n_time);
			printf("���μ��� ����\n");
			printf("���μ��� ���̵� : %d \n", Temp->n_time);
			printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
			printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
			printf("���μ��� ���ð� : %d \n", Temp->n_wait);
			
			printf("%d ��° ���μ��� ���� �κ� ť�� �̵��մϴ�.", Temp->n_time);

			CSecond.RR_in(Temp);
		}
	
	}
	n_processcount = Prio_Q.size();
}

/* RR Part***********************************************************/
/******************************************************************
RR�� ��� : ���μ��� ���� ���ư��� ó��.
����Ʈ Ÿ�� 3�̸����� �پ�� ���� �˴� FCFS�� ����������.
1,2 : �߿� / 3,4,5 : ���߿�.
  ******************************************************************/
void CRR_Q::RR_in(Process_blk *Temp)
{
	RR_Q.push_front(Temp);
}

void CRR_Q::RR_process()
{
	n_processcount = RR_Q.size();
	Process_blk *Temp;
	
	Rr_head = RR_Q.end();

	for(Rr_head ; Rr_head != RR_Q.begin() ; Rr_head--)
	{
		Temp = RR_Q.back();

		if(Temp->n_burst > 3)
		{
			Temp->n_burst = Temp->n_burst-2;

			printf("==================���� �κ� ť===========================");
			printf("%d ��° ���μ���ó���� .\n", Temp->n_time);
			printf("���μ��� ����\n");
			printf("���μ��� ���̵� : %d \n", Temp->n_time);
			printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
			printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
			printf("���μ��� ���ð� : %d \n", Temp->n_wait);

			RR_Q.push_front(Temp);
		}
		else if(Temp->n_burst < 4)
		{
			printf("==================���� �κ� ť===========================");
			printf("%d ��° ���μ���ó���� .\n", Temp->n_time);
			printf("���μ��� ����\n");
			printf("���μ��� ���̵� : %d \n", Temp->n_time);
			printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
			printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
			printf("���μ��� ���ð� : %d \n", Temp->n_wait);
			
			printf("%d ��° ���μ��� ���� ���� ť�� �̵��մϴ�.", Temp->n_time);

//			FCFS_Q.Fcfs_in(Temp); // ���� Ŭ������ ������ ������ ����.
			CThird.Fcfs_in(Temp);
		}

		
	}
	n_processcount = RR_Q.size();
}
