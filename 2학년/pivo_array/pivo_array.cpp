#include <stdio.h>
#include <iostream.h>
#include <time.h>

void work_process(int);

void main()
{

	clock_t start, end;
	double dur;

	for(int count=6 ; count<=15 ; count++)
	{
		start=clock();
		work_process(count);
		end=clock();
		dur= ((double)(end-start)) / CLK_TCK;

		printf("�迭�� ���̰�: %d" ,count);
		printf(" �϶� �ð��� : %lf \n", dur);
	}
}

void work_process(int n)
{
	int k, i, j, t, r;
	int s[15];

	

	// Data ���� �Է� , ������ n�� �����
		
	// Data �Է�	
	
	for(k=0; k<n; k++)          // �迭 s�� �Է�(count�� k)
		s[k]=k;		// �Է� ���� �������� k�� �迭�� ������ ��ġ.

////////////////////////////////////////////////////////////////
//
	for(k=0; k<n-1; k++)		// k�� 0���� �迭 �������� ������
	{
		for(r=n-1; r>k; r--)	// r�� �迭�� �������� ������ k����
		{
			if(s[r-1] > s[r])	// s[r-1]���� s[r]�� ũ�ٸ�
			{
				t = s[r];
				s[r] = s[r-1];
				s[r-1] = t;		// �� ���� �� ��ȯ
			}
		}
	}
///////////////////////////////////////////////////////////////////////
// �迭�� �� ���
	
	for(k=0; k<n; k++)   // k�� n����.
		printf("%d ", s[k]);
	printf("\n");

	
///////////////////////////////////////////////////////////////////////
	while(k>0)						// k�� 0���� Ŭ ����
	{
		for(k=n-1; k>0; k--)		// k�� n-1���� ����
		{
			if(s[k-1] < s[k])       // �迭�� ���� k-1�溸�� �� �޹��� ���� ũ��
			{
				i = k-1;            // i�� k-1 ó���� ���� �ƿ�
				break;
			}
		}

		if(k==0) continue;			// k�� 0�� ������ ��Ƽ��           
			j = i+1;
		for(k=i+2; k<n; k++)
		{
			if(s[i] < s[k])
				if(s[k] < s[j]) j=k;
		}

		t = s[i];
		s[i] = s[j];
		s[j] = t;

		for(r=i+1; r<n-1; r++)
		{
			for(k=n-1; k>r; k--)
			{
				if(s[k-1] > s[k])
				{
					t = s[k];
					s[k] = s[k-1];
					s[k-1] = t;
				}
			}
		}
	}


	
	for(k=0; k<n; k++)
	{
		printf("%d ", s[k]);
		printf("\n");
	}
	printf("end\n");

}
