#include "list.h"

/*--------------------------------------------------
����Ʈ �ð� : ���μ��� ó���� �ɸ��� �ð�
�켱 ���� : ���μ��� ó���� �켱 ����
���� �ð� : ���μ����� ������ �ð�
--------------------------------------------------*/

struct Process_blk
{
	unsigned int burst_time;     // ����Ʈ �ð�
	unsigned int rank;          // �켱����
	unsigned int start_time;    // ���� �ð�
	int wait_count;
};

Process_blk Jump_Q; // �� ť�� ���̸� �̵���Ű�� ���� ����� �� ���� ����.
int jump_check; // ť���� �̵��� ���� üũ ����....���� ���� ���� ť�� �ִٴ� �Ҹ�.

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
FCFS�� ��� : ��� �־����� ��� ó�� �ع� ������.
�߿伺 ���� ���. ������ ��ٸ� �ڽĵ� �׷��� ��� ��� ó��.
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


	int n_fcfscount; // ���μ����� ó���ؾ� �� ��� ����
	
	n_fcfscount = FCFS_Q.m_nLength; // ��� ���� ����.

	while(n_fcfscount)
	{
		Temp = FCFS_Q.SubNode();
		
		Temp.burst_time=0; // �Ѹ����, ���� ���� ���μ����� ���� ��ģ�ٴ� �Ҹ�.
		//FCFS_Q.AddNode(Temp); // ó���� ��带 �ٽ� ����...�� �ƴ϶� ����ؾ���.(�̱���)
		n_fcfscount--;
	}
	
}

/* Priority Part***********************************************************/
/******************************************************************
Priority�� ��� : �켱���� ���� ���μ���.
�߿伺 ���� ��鸸 ó��. �߿伺 ���� ��� ī��Ʈ 5 �Ѿ ����� �˴� RR�� �̵�.
1,2 : �߿� / 3,4,5 : ���߿�.
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
	int n_priocount = Prio_Q.m_nLength; // Prio ť�� ����. ó���ؾ� �� ��� ����.
	
	while(n_priocount)
	{
		Temp = Prio_Q.SubNode();
		
		// ���μ����� �߿伺�� ���� ó��.
		if(Temp.rank < 3) // �߿䵵 2 �����϶�.
		{
			Temp.burst_time--;
			Prio_Q.AddNode(Temp); // ����Ʈ Ÿ�� ���̰�, �ٽ� ť�� �ִ´�.
		}
		else if(Temp.rank > 2 || Temp.wait_count < 5)  // �߿䵵 ������, �̶� ���ð��� 5 �Ѿ�� ó�� �� �ִ� ���� ����.
		{
			Temp.wait_count++; // ���ð� 1 ����.			
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
RR�� ��� : ���μ��� ���� ���ư��� ó��.
����Ʈ Ÿ�� 3�̸����� �پ�� ���� �˴� FCFS�� ����������.
1,2 : �߿� / 3,4,5 : ���߿�.
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