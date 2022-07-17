#include <stdio.h>
#include <iostream>
#include <list>
//#include "init_class.h"

using namespace std;

typedef struct
{
	unsigned int n_rank; // 프로세스 우선순위
	unsigned int n_time; // 도착시간.
	unsigned int n_burst; // 버스트 시간.
	unsigned int n_wait; // 대기시간.

}Process_blk;

//static Process_blk *s_jumpQ = NULL; // 클래스간 통신 위한 전역 변수, 임시로 점핑하는 프로세스 저장.

// 우선순위 선점 큐 - 모든 프로세스는 이걸로 시작.
class C_Q 
{

public:
	unsigned int n_Priocount; // 현재 큐 내의 프로세스 개수
	unsigned int n_Prioburst;
	unsigned int n_Rrcount; // 현재 큐 내의 프로세스 개수
	unsigned int n_Fcfscount; // 현재 큐 내의 프로세스 개수

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
Priority의 경우 : 우선순위 선점 프로세스.
중요성 높은 놈들만 처리. 중요성 낮고 대기 카운트 5 넘어간 놈들은 죄다 RR로 이동.
1,2 : 중요 / 3,4,5 : 비중요.
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
			
		Temp = Prio_Q.front(); // 현재 진행중인 프로세스는 제거.
		Prio_Q.pop_front();
		
		// 프로세스의 중요성에 따른 처리.
		if(Temp->n_rank <= 2) // 중요도 2 이하일때 처리 해준다.
		{
			if(Temp->n_burst > 0)
			{
				n_Prioburst = n_Prioburst + Temp->n_burst;
				Temp->n_burst=0;

				printf("==================%d 번째 프로세스처리중==============\n", Temp->n_time);
				printf("프로세스 정보\n");
				printf("프로세스 아이디 : %d \n", Temp->n_time);
				printf("프로세스 중요도 : %d \n", Temp->n_rank);
				printf("프로세스 필요시간 : %d \n", Temp->n_burst);
				printf("프로세스 대기시간 : %d \n\n", Temp->n_wait);

				n_waitsum = n_waitsum + Temp->n_wait;

				printf("이 프로세스는 이미 종료되었습니다.\n");

				//Gant_Prio.push_back("O");

				delete Temp;
				n_Priocount--;

				//Prio_Q.push_back(Temp); // 버스트 타임 줄이고, 다시 큐에 넣는다.
			}
			/*
			else if(Temp->n_burst <= 0)
			{
				n_waitsum = n_waitsum + Temp->n_wait;
				printf("==================%d 번째 프로세스처리중==============\n", Temp->n_time);
				printf("이 프로세스는 이미 종료되었습니다.\n");
				delete Temp;
				n_Priocount--;
			}
			*/
		}
		else if(Temp->n_rank >= 3 && Temp->n_wait < 5)  // 중요도 낮을때, 이때 대기시간이 5 넘어가면 처리 해 주는 연산 포함.
		{
			Temp->n_wait = Temp->n_wait+n_Prioburst; // 대기시간 증가.

			//printf("==================우선순위 큐===========================\n");
			printf("==================%d 번째 프로세스처리중==============\n", Temp->n_time);
			printf("프로세스 정보\n");
			printf("프로세스 아이디 : %d \n", Temp->n_time);
			printf("프로세스 중요도 : %d \n", Temp->n_rank);
			printf("프로세스 필요시간 : %d \n", Temp->n_burst);
			printf("프로세스 대기시간 : %d \n\n", Temp->n_wait);

			//Gant_Prio.push_back("O");

			Prio_Q.push_back(Temp);

		}
		else if(Temp->n_rank >= 3 && Temp->n_wait >= 5)
		{
			//Temp->n_wait = 0;

			//printf("==================우선순위 큐===========================\n");
			printf("==================%d 번째 프로세스처리중==============\n", Temp->n_time);
			printf("프로세스 정보\n");
			printf("프로세스 아이디 : %d \n", Temp->n_time);
			printf("프로세스 중요도 : %d \n", Temp->n_rank);
			printf("프로세스 필요시간 : %d \n", Temp->n_burst);
			printf("프로세스 대기시간 : %d \n\n", Temp->n_wait);
			
			printf("%d 번째 프로세스 라운드 로빈 큐로 이동합니다.\n\n", Temp->n_time);
			n_Rrcount++;
			n_Priocount--;
			RR_in(Temp);
		}
	
	}
	n_Priocount = Prio_Q.size();
}

/* RR Part***********************************************************/
/******************************************************************
RR의 경우 : 프로세스 별로 돌아가며 처리.
버스트 타임 3미만으로 줄어든 놈은 죄다 FCFS로 날려버려라.
1,2 : 중요 / 3,4,5 : 비중요.
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

			//printf("==================라운드 로빈 큐===========================\n");
			printf("==================%d 번째 프로세스처리중==============\n", Temp->n_time);
			printf("프로세스 정보\n");
			printf("프로세스 아이디 : %d \n", Temp->n_time);
			printf("프로세스 중요도 : %d \n", Temp->n_rank);
			printf("프로세스 필요시간 : %d \n", Temp->n_burst);
			printf("프로세스 대기시간 : %d \n\n", Temp->n_wait);

			Temp->n_wait = Temp->n_wait+2;

			//Gant_RR.push_back("O");

			RR_Q.push_front(Temp);
		}
		else if(Temp->n_burst <= 3)
		{
			//printf("==================라운드 로빈 큐===========================\n");
			printf("==================%d 번째 프로세스처리중==============\n", Temp->n_time);
			printf("프로세스 정보\n");
			printf("프로세스 아이디 : %d \n", Temp->n_time);
			printf("프로세스 중요도 : %d \n", Temp->n_rank);
			printf("프로세스 필요시간 : %d \n", Temp->n_burst);
			printf("프로세스 대기시간 : %d \n\n", Temp->n_wait);
			
			printf("%d 번째 프로세스 선입 선출 큐로 이동합니다.\n\n", Temp->n_time);

//			FCFS_Q.Fcfs_in(Temp); // 역시 클래스간 데이터 전송이 문제.
			n_Fcfscount++;
			n_Rrcount--;
			Fcfs_in(Temp);
		}

		
	}
	n_Rrcount = RR_Q.size();
}

// 프로세스 큐잉 작업 파트 .......................
/* FCFS Part ********************************************************/
/******************************************************************
FCFS의 경우 : 기냥 주어진것 대로 처리 해버 버린다.
중요성 낮은 놈들. 한참을 기다린 자식들 그런런 놈들 모아 처리.
마지막으로 남은 놈들을 싸그리 모아 정리.
  ******************************************************************/

void C_Q::Fcfs_process()
{
	n_Fcfscount = FCFS_Q.size();
	Process_blk *Temp;

	Q_head = FCFS_Q.end();
	//gant_head = Gant_Fcfs.begin();

	for(Q_head ; Q_head != FCFS_Q.begin() ; Q_head--)
	{
		Temp = FCFS_Q.front(); // 현재 진행중인 프로세스는 제거.
		FCFS_Q.pop_front();
		
		Temp->n_burst=0; // 한마디로, 여기 들어온 프로세스는 이제 종친다는 소리.

		printf("==================%d 번째 프로세스처리중==============\n", Temp->n_time);
		printf("%d 번째 프로세스는 종료되었습니다.\n", Temp->n_time);
		printf("종료된 프로세스 정보\n");
		printf("프로세스 아이디 : %d \n", Temp->n_time);
		printf("프로세스 중요도 : %d \n", Temp->n_rank);
		printf("프로세스 대기시간 : %d \n\n", Temp->n_wait);

		n_waitsum = n_waitsum + Temp->n_wait;

//		Gant_Fcfs.push_back();
		n_Fcfscount--;
		
		delete Temp;
		//FCFS_Q.AddNode(Temp); // 처리한 노드를 다시 저장...이 아니라 폐기해야함.(미구현)
		
	}
	n_Fcfscount = FCFS_Q.size();
	
}