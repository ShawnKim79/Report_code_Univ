#include "list.h"

/*--------------------------------------------------
버스트 시간 : 프로세스 처리에 걸리는 시간
우선 순위 : 프로세스 처리의 우선 순위
도착 시간 : 프로세스가 도착한 시간
--------------------------------------------------*/

struct Process_blk
{
	unsigned int burst_time;     // 버스트 시간
	unsigned int rank;          // 우선순위
	unsigned int start_time;    // 도착 시간
	int wait_count;
};

Process_blk Jump_Q; // 각 큐들 사이를 이동시키기 위해 만들어 둔 전역 변수.
int jump_check; // 큐들의 이동을 위한 체크 변수....켜져 있음 점프 큐가 있다는 소리.

class CFCFS_Q
{
public:
	CFCFS_Q();
	void Fcfs_in(Process_blk *Temp);
	Process_blk* Fcfs_out();
	void Fcfs_process();

private:
	List<Process_blk *> FCFS_Q;
};

class CPrio_Q
{
public:
	CPrio_Q();
	void Prio_in(Process_blk *Temp);
	Process_blk Prio_out();
	void Prio_process();

private:
	List<Process_blk *> Prio_Q;
};


class CRR_Q
{
public:
	CRR_Q();
	void RR_in(Process_blk *Temp);
	Process_blk RR_out();
	void RR_process();

private:
	List<Process_blk *> RR_Q;
};


/* FCFS Part ********************************************************/
/******************************************************************
FCFS의 경우 : 기냥 주어진것 대로 처리 해버 버린다.
중요성 낮은 놈들. 한참을 기다린 자식들 그런런 놈들 모아 처리.
  ******************************************************************/
void CFCFS_Q::Fcfs_in(Process_blk *Temp)
{
	FCFS_Q.AddNode(Temp);

}

Process_blk* CFCFS_Q::Fcfs_out()
{
	return FCFS_Q.SubNode();
}

void CFCFS_Q::Fcfs_process()
{
	Process_blk Temp;

	if(jump_check = 1)
	{
		FCFS_Q.AddNode(Jump_Q);
		jump_check = 0;
	}


	int n_fcfscount; // 프로세스가 처리해야 할 노드 개수
	
	n_fcfscount = FCFS_Q.m_nLength; // 노드 갯수 저장.

	while(n_fcfscount)
	{
		Temp = FCFS_Q.SubNode();
		
		Temp.burst_time=0; // 한마디로, 여기 들어온 프로세스는 이제 종친다는 소리.
		//FCFS_Q.AddNode(Temp); // 처리한 노드를 다시 저장...이 아니라 폐기해야함.(미구현)
		n_fcfscount--;
	}
	
}

/* Priority Part***********************************************************/
/******************************************************************
Priority의 경우 : 우선순위 선점 프로세스.
중요성 높은 놈들만 처리. 중요성 낮고 대기 카운트 5 넘어간 놈들은 죄다 RR로 이동.
1,2 : 중요 / 3,4,5 : 비중요.
  ******************************************************************/
void CPrio_Q::Prio_in(Process_blk *Temp)
{
	Prio_Q.AddNode(Temp);
}

Process_blk CPrio_Q::Prio_out()
{
	return FCFS_Q.SubNode();	
}

void CPrio_Q::Prio_process()
{
	Process_blk Temp;
	int n_priocount = Prio_Q.m_nLength; // Prio 큐의 길이. 처리해야 할 노드 갯수.
	
	while(n_priocount)
	{
		Temp = Prio_Q.SubNode();
		
		// 프로세스의 중요성에 따른 처리.
		if(Temp.rank < 3) // 중요도 2 이하일때.
		{
			Temp.burst_time--;
			Prio_Q.AddNode(Temp); // 버스트 타임 줄이고, 다시 큐에 넣는다.
		}
		else if(Temp.rank > 2 || Temp.wait_count < 5)  // 중요도 낮을때, 이때 대기시간이 5 넘어가면 처리 해 주는 연산 포함.
		{
			Temp.wait_count++; // 대기시간 1 증가.			
			Prio_Q.AddNode(Temp);
		}
		else if(Temp.rank > 2 || Temp.wait_count > 5)
		{
			Temp.wait_count = 0;
			jump_check = 1;
			Jump_Q = Temp;
		}
		n_priocount--;
	}
	
}

/* RR Part***********************************************************/
/******************************************************************
RR의 경우 : 프로세스 별로 돌아가며 처리.
버스트 타임 3미만으로 줄어든 놈은 죄다 FCFS로 날려버려라.
1,2 : 중요 / 3,4,5 : 비중요.
  ******************************************************************/
void CRR_Q::RR_in(Process_blk *Temp)
{
	RR_Q.AddNode(Temp);
}

Process_blk CRR_Q::RR_out()
{
	return RR_Q.SubNode();
}

void CRR_Q::RR_process()
{
	Process_blk Temp;

	if(jump_check = 1)
	{
		RR_Q.AddNode(Jump_Q);
		jump_check = 0;
	}

	int n_rrcount = RR_Q.m_nLength;

	while(n_rrcount)
	{
		Temp = RR_Q.SubNode();
		if(Temp.burst_time > 3)
		{
			Temp.burst_time--;
			RR_Q.AddNode(Temp);
		}
		else if(Temp.burst_time < 4)
		{
			Jump_Q = Temp;
			jump_check = 1;
		}

		n_rrcount--;
	}
}