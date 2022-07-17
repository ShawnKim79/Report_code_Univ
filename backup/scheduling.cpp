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

// �������� ���μ��� ����ü ����.
for (count = 0 ; count < 3 ; count++)
{
	Process_blk *p_Newprocess;
	p_Newprocess = new Process_blk;

	printf("=====================================\n");
	printf("===== %d ��° ���μ��� �Է�==========\n", count+1);

	printf("���μ��� ����Ʈ �Է� : ");
	scanf("%d", &p_Newprocess->n_burst);

	printf("���μ��� �߿䵵 �Է� (1:�߿䵵 �� ~ 5:�߿䵵 ��) : ");
	scanf("%d", &p_Newprocess->n_rank);

	printf("���μ��� ��� �ð�(���μ��� ���̵�) : %d \n", count);
	p_Newprocess->n_time = count; // �̰� ���μ��� ���̵� ����Ѵ�.(�Էµ� ���� = ���μ��� ���̵�)
	
	p_Newprocess->n_wait = 0; // �����Ǵ� ���μ����� ��� Ÿ���� 0
	printf("���μ��� ��� �ð� : %d \n", p_Newprocess->n_wait);

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