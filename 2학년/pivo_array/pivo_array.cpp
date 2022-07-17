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

		printf("배열의 길이가: %d" ,count);
		printf(" 일때 시간은 : %lf \n", dur);
	}
}

void work_process(int n)
{
	int k, i, j, t, r;
	int s[15];

	

	// Data 갯수 입력 , 갯수는 n에 저장됨
		
	// Data 입력	
	
	for(k=0; k<n; k++)          // 배열 s에 입력(count는 k)
		s[k]=k;		// 입력 종료 시점에서 k는 배열의 마지막 위치.

////////////////////////////////////////////////////////////////
//
	for(k=0; k<n-1; k++)		// k는 0부터 배열 마지막의 전까지
	{
		for(r=n-1; r>k; r--)	// r은 배열의 마지막의 전부터 k까지
		{
			if(s[r-1] > s[r])	// s[r-1]보다 s[r]이 크다면
			{
				t = s[r];
				s[r] = s[r-1];
				s[r-1] = t;		// 두 방의 값 교환
			}
		}
	}
///////////////////////////////////////////////////////////////////////
// 배열의 값 출력
	
	for(k=0; k<n; k++)   // k는 n까지.
		printf("%d ", s[k]);
	printf("\n");

	
///////////////////////////////////////////////////////////////////////
	while(k>0)						// k가 0보다 클 동안
	{
		for(k=n-1; k>0; k--)		// k는 n-1까지 감소
		{
			if(s[k-1] < s[k])       // 배열이 현재 k-1방보다 그 뒷방의 값이 크면
			{
				i = k-1;            // i는 k-1 처리후 루프 아웃
				break;
			}
		}

		if(k==0) continue;			// k가 0과 같으면 컨티뉴           
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
