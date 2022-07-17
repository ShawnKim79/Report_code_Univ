#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

//define heap // 힙의 정의.
#define heap_size 30                  // 힙 크기 : 30
#define HEAP_FULL(n)(n==heap_size-1)  // HEAP_FULL(n) =>문장 대체: n==heap_size-1
#define HEAP_EMPTY(n)(!n)             // HEAP_EMPTY(n) =>문장 대체: !n

// 전역 변수
int heap[heap_size];                  // 힙 선언
int n = 0;                            // 힙의 현재 사용량 저장.

// max heap program
void key_add();                       // key 추가
void key_delete();                    // key 삭제
void heap_output();                   // key 출력

void main()
{
	char job;                         // 작업 선택 스위치.

	cout << "Key 추가는 'a', 삭제는 'd', 작업끝은 'e'를 입력하시오 : ";
	cin >> job;                       // 작업 결정.

	while(job=='a' || job=='d'){      // job가 a나 b일경우 프로그램 continue
		if(job=='a')key_add();        // a일 경우 key 삽입
		if(job=='d')key_delete();     // d일 경우 key 삭제
		 
		heap_output();                // heap출력. 매 작업 종료후 마다 실행.
		cout << endl;
		cout << "Key 추가는 'a', 삭제는 'd', 작업끝은 'e'를 입력하시오 : ";
		cin >> job;
	}
}

// Key 입력 함수 ////////////////////////////////////////////////////////////
void key_add()
{
	int key, i;                       // key:입력값. i:heap node count
	cout << " * Enter add data : ";
	cin >> key;

	if(HEAP_FULL(n)){                  // heap이 가득 차있다면 메세지 출력.
		fprintf(stderr, "* The memory is full\n");
		exit(1);
	}

	i=++n;                             // i의 값 결정.(현재 힙 사용량이며, 대입후에는 현재 사용량+1)

	while((i!=1)&&(key>heap[i/2])){    // i값이 1이 아니거나 -> heap이 차있거나,
		                               // key의 값이 heap[1/2]에 저장된 값보다 클 경우 
		                               // 즉, 현재 마지막 노드의 상위 노드의 값보다 key값이 클 경우 루프 실행

		heap[i] = heap[i/2];           // heap[i](현재 마지막 노드)의 값은 heap[i/2](마지막 노드의 상위노드)
		                               // 의 값이 되며
		i/=2;                          // 현재 연산중인 위치는 상위 노드로 이동한다.
	}
	heap[i]=key;                       // 연산이 끝난 후의 노드에 key값 저장.
}                                      

// 노드 삭제 함수 //////////////////////////////////////////////////////////////
void key_delete()
{
//	int temp;
	int i=1;

	if ((!n==0))
		cout << "* 노드 삭제 : 제일 첫 노드 = " << heap[1] << endl; //노드 삭제.
	else {
		cout << " 현재 노드는 비어있음." << endl;
		return;
	}

	// 노드 재구성 //
	
	while ( n!=1 ){
			if( heap[i*2] > heap[i*2+1] ){
				i=i*2;
				heap[i/2]=heap[i];
			}
			else {
				i=i*2+1;
				heap[i/2]=heap[i];
			}
	}

	n=n-1;
}

// 힙 출력 함수 ////////////////////////////////////////////////////////////////
void heap_output()
{
    int i=1;                               // heap을 읽을 변수, 노드 카운트
 
	if(!n){                                // heap이 비어있을 경우 (n이 0)
		cout << "* tree is empty *\n";
		return;
	}

	cout << "* 현재 최대 히프 상태 *\n";   
	cout << " * root is : " << heap[1] << endl; 

	while(i<n){                             // 노드 카운트가 n(힙 사용량)보다 작을 동안
		i++;
		if(i%2){                            // 노드번호가 홀수 일때
			cout << " * " << heap[i/2];
			cout << "의 오른쪽자노드는 : " << heap[i] << endl;
			}
		else{                               // 노드 번호가 짝수 일때.
			cout << " * " << heap[i/2];
			cout << "의 왼쪽  자노드는 : " << heap[i] << endl;
			}
	}
}


