#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

//define heap
#define heap_size 30
#define HEAP_FULL(n)(n==heap_size-1)
#define HEAP_EMPTY(n)(!n)

int heap[heap_size];
int n = 0;

// max heap program
void key_add();
void key_delete();
void heap_output();

void main()
{
	char job;
	cout << "Key 추가는 'a', 삭제는 'd', 작업끝은 'e'를 입력하시오 : ";
	cin >> job;
	while(job=='a' || job=='d'){
		if(job=='a')key_add();
		if(job=='d')key_delete();
		heap_output();
		cout << endl;
		cout << "Key 추가는 'a', 삭제는 'd', 작업끝은 'e'를 입력하시오 : ";
		cin >> job;
	}
}

void key_add()
{
	int key, i;
	cout << " * Enter add data : ";
	cin >> key;
	if(HEAP_FULL(n)){
		fprintf(stderr, "* The memory is full\n");
		exit(1);
	}
	i=++n;
	while((i!=1)&&(key>heap[i/2])){
		heap[i] = heap[i/2];
		i/=2;
	}
	heap[i]=key;
}

void key_delete()
{
	int i = 1;
	
	if(HEAP_EMPTY(n))
	{
		return ;
	}
	
	cout << " * delete data : " << heap[1] << endl;

	while(n != 1)
	{
		i = heap[i*2] > heap[i*2+1] ? i*2:i*2+1;
		if(heap[i] < heap[n])
		{
			heap[i/2] = heap[n];
			break;
		}
		else
			heap[i/2] = heap[i];
	}

	heap[n] = 0;

	n--;
}

void heap_output()
{
    int i=1;
	if(!n){
		cout << "* tree is empty *\n";
		return;
	}
	cout << "* 현재 최대 히프 상태 *\n";
	cout << " * root is : " << heap[1] << endl;
	while(i<n){
		i++;
		if(i%2){
			cout << " * " << heap[i/2];
			cout << "의 오른쪽자노드는 : " << heap[i] << endl;
		}
		else{
			cout << " * " << heap[i/2];
			cout << "의 왼쪽  자노드는 : " << heap[i] << endl;
		}
	}
}
