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
	unsigned int n_wait; // ���ð�.

}Process_blk;

//static Process_blk *s_jumpQ = NULL; // Ŭ������ ��� ���� ���� ����, �ӽ÷� �����ϴ� ���μ��� ����.

// �켱���� ���� ť - ��� ���μ����� �̰ɷ� ����.
class C_Q 
{

public:
	unsigned int n_Priocount; // ���� ť ���� ���μ��� ����
	unsigned int n_Prioburst;
	unsigned int n_Rrcount; // ���� ť ���� ���μ��� ����
	unsigned int n_Fcfscount; // ���� ť ���� ���μ��� ����

	int n_waitsum;
	int n_processcount;
	float n_waitave;

	list<Process_blk *>::iterator Q_head;

	//list<char>::iterator gant_head;
	
	void Prio_in(Process_blk *Temp);
	void RR_in(Process_blk *Temp);
	void Fcfs_in(Process_blk *Temp);
	
	void Prio_process();
	void RR_process();
	void Fcfs_process();

private:
	list<Process_blk *> Prio_Q;
	list<Process_blk *> RR_Q;
	list<Process_blk *> FCFS_Q;
/*
	list<char> Gant_Prio;
	list<char> Gant_RR;
	list<char> Gant_Fcfs;
*/
};

void C_Q::Fcfs_in(Process_blk *Temp)
{
	FCFS_Q.push_back(Temp);
	
}
void C_Q::Prio_in(Process_blk *Temp)
{

	Prio_Q.push_back(Temp);
}

void C_Q::RR_in(Process_blk *Temp)
{
	RR_Q.push_back(Temp);
}



/* Priority Part***********************************************************/
/******************************************************************
Priority�� ��� : �켱���� ���� ���μ���.
�߿伺 ���� ��鸸 ó��. �߿伺 ���� ��� ī��Ʈ 5 �Ѿ ����� �˴� RR�� �̵�.
1,2 : �߿� / 3,4,5 : ���߿�.
  ******************************************************************/


void C_Q::Prio_process()
{
	Process_blk *Temp;
	n_Priocount = Prio_Q.size();	

	Q_head = Prio_Q.end();
//	gant_head = Gant_Prio.begin();

		
	//for(Q_head ; Q_head != Prio_Q.begin(); Q_head--)
	for (int i=0 ; i < n_Priocount ; i++) 
	{
		//Temp = *Prio_head;
			
		Temp = Prio_Q.front(); // ���� �������� ���μ����� ����.
		Prio_Q.pop_front();
		
		// ���μ����� �߿伺�� ���� ó��.
		if(Temp->n_rank <= 2) // �߿䵵 2 �����϶� ó�� ���ش�.
		{
			if(Temp->n_burst > 0)
			{
				n_Prioburst = n_Prioburst + Temp->n_burst;
				Temp->n_burst=0;

				printf("==================%d ��° ���μ���ó����==============\n", Temp->n_time);
				printf("���μ��� ����\n");
				printf("���μ��� ���̵� : %d \n", Temp->n_time);
				printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
				printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
				printf("���μ��� ���ð� : %d \n\n", Temp->n_wait);

				n_waitsum = n_waitsum + Temp->n_wait;

				printf("�� ���μ����� �̹� ����Ǿ����ϴ�.\n");

				//Gant_Prio.push_back("O");

				delete Temp;
				n_Priocount--;

				//Prio_Q.push_back(Temp); // ����Ʈ Ÿ�� ���̰�, �ٽ� ť�� �ִ´�.
			}
			/*
			else if(Temp->n_burst <= 0)
			{
				n_waitsum = n_waitsum + Temp->n_wait;
				printf("==================%d ��° ���μ���ó����==============\n", Temp->n_time);
				printf("�� ���μ����� �̹� ����Ǿ����ϴ�.\n");
				delete Temp;
				n_Priocount--;
			}
			*/
		}
		else if(Temp->n_rank >= 3 && Temp->n_wait < 5)  // �߿䵵 ������, �̶� ���ð��� 5 �Ѿ�� ó�� �� �ִ� ���� ����.
		{
			Temp->n_wait = Temp->n_wait+n_Prioburst; // ���ð� ����.

			//printf("==================�켱���� ť===========================\n");
			printf("==================%d ��° ���μ���ó����==============\n", Temp->n_time);
			printf("���μ��� ����\n");
			printf("���μ��� ���̵� : %d \n", Temp->n_time);
			printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
			printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
			printf("���μ��� ���ð� : %d \n\n", Temp->n_wait);

			//Gant_Prio.push_back("O");

			Prio_Q.push_back(Temp);

		}
		else if(Temp->n_rank >= 3 && Temp->n_wait >= 5)
		{
			//Temp->n_wait = 0;

			//printf("==================�켱���� ť===========================\n");
			printf("==================%d ��° ���μ���ó����==============\n", Temp->n_time);
			printf("���μ��� ����\n");
			printf("���μ��� ���̵� : %d \n", Temp->n_time);
			printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
			printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
			printf("���μ��� ���ð� : %d \n\n", Temp->n_wait);
			
			printf("%d ��° ���μ��� ���� �κ� ť�� �̵��մϴ�.\n\n", Temp->n_time);
			n_Rrcount++;
			n_Priocount--;
			RR_in(Temp);
		}
	
	}
	n_Priocount = Prio_Q.size();
}

/* RR Part***********************************************************/
/******************************************************************
RR�� ��� : ���μ��� ���� ���ư��� ó��.
����Ʈ Ÿ�� 3�̸����� �پ�� ���� �˴� FCFS�� ����������.
1,2 : �߿� / 3,4,5 : ���߿�.
  ******************************************************************/

void C_Q::RR_process()
{
	n_Rrcount = RR_Q.size();
	Process_blk *Temp;
	
	Q_head = RR_Q.end();
	//gant_head = Gant_RR.begin();

	//for(Q_head ; Q_head != RR_Q.begin() ; Q_head--)
	for (int i=0 ; i < n_Rrcount ; i++) 
	{
		Temp = RR_Q.front();
		RR_Q.pop_front();

		if(Temp->n_burst > 2)
		{
			Temp->n_burst = Temp->n_burst-2;

			//printf("==================���� �κ� ť===========================\n");
			printf("==================%d ��° ���μ���ó����==============\n", Temp->n_time);
			printf("���μ��� ����\n");
			printf("���μ��� ���̵� : %d \n", Temp->n_time);
			printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
			printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
			printf("���μ��� ���ð� : %d \n\n", Temp->n_wait);

			Temp->n_wait = Temp->n_wait+2;

			//Gant_RR.push_back("O");

			RR_Q.push_front(Temp);
		}
		else if(Temp->n_burst <= 3)
		{
			//printf("==================���� �κ� ť===========================\n");
			printf("==================%d ��° ���μ���ó����==============\n", Temp->n_time);
			printf("���μ��� ����\n");
			printf("���μ��� ���̵� : %d \n", Temp->n_time);
			printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
			printf("���μ��� �ʿ�ð� : %d \n", Temp->n_burst);
			printf("���μ��� ���ð� : %d \n\n", Temp->n_wait);
			
			printf("%d ��° ���μ��� ���� ���� ť�� �̵��մϴ�.\n\n", Temp->n_time);

//			FCFS_Q.Fcfs_in(Temp); // ���� Ŭ������ ������ ������ ����.
			n_Fcfscount++;
			n_Rrcount--;
			Fcfs_in(Temp);
		}

		
	}
	n_Rrcount = RR_Q.size();
}

// ���μ��� ť�� �۾� ��Ʈ .......................
/* FCFS Part ********************************************************/
/******************************************************************
FCFS�� ��� : ��� �־����� ��� ó�� �ع� ������.
�߿伺 ���� ���. ������ ��ٸ� �ڽĵ� �׷��� ��� ��� ó��.
���������� ���� ����� �α׸� ��� ����.
  ******************************************************************/

void C_Q::Fcfs_process()
{
	n_Fcfscount = FCFS_Q.size();
	Process_blk *Temp;

	Q_head = FCFS_Q.end();
	//gant_head = Gant_Fcfs.begin();

	for(Q_head ; Q_head != FCFS_Q.begin() ; Q_head--)
	{
		Temp = FCFS_Q.front(); // ���� �������� ���μ����� ����.
		FCFS_Q.pop_front();
		
		Temp->n_burst=0; // �Ѹ����, ���� ���� ���μ����� ���� ��ģ�ٴ� �Ҹ�.

		printf("==================%d ��° ���μ���ó����==============\n", Temp->n_time);
		printf("%d ��° ���μ����� ����Ǿ����ϴ�.\n", Temp->n_time);
		printf("����� ���μ��� ����\n");
		printf("���μ��� ���̵� : %d \n", Temp->n_time);
		printf("���μ��� �߿䵵 : %d \n", Temp->n_rank);
		printf("���μ��� ���ð� : %d \n\n", Temp->n_wait);

		n_waitsum = n_waitsum + Temp->n_wait;

//		Gant_Fcfs.push_back();
		n_Fcfscount--;
		
		delete Temp;
		//FCFS_Q.AddNode(Temp); // ó���� ��带 �ٽ� ����...�� �ƴ϶� ����ؾ���.(�̱���)
		
	}
	n_Fcfscount = FCFS_Q.size();
	
}