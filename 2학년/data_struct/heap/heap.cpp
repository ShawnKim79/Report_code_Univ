#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

//define heap // ���� ����.
#define heap_size 30                  // �� ũ�� : 30
#define HEAP_FULL(n)(n==heap_size-1)  // HEAP_FULL(n) =>���� ��ü: n==heap_size-1
#define HEAP_EMPTY(n)(!n)             // HEAP_EMPTY(n) =>���� ��ü: !n

// ���� ����
int heap[heap_size];                  // �� ����
int n = 0;                            // ���� ���� ��뷮 ����.

// max heap program
void key_add();                       // key �߰�
void key_delete();                    // key ����
void heap_output();                   // key ���

void main()
{
	char job;                         // �۾� ���� ����ġ.

	cout << "Key �߰��� 'a', ������ 'd', �۾����� 'e'�� �Է��Ͻÿ� : ";
	cin >> job;                       // �۾� ����.

	while(job=='a' || job=='d'){      // job�� a�� b�ϰ�� ���α׷� continue
		if(job=='a')key_add();        // a�� ��� key ����
		if(job=='d')key_delete();     // d�� ��� key ����
		 
		heap_output();                // heap���. �� �۾� ������ ���� ����.
		cout << endl;
		cout << "Key �߰��� 'a', ������ 'd', �۾����� 'e'�� �Է��Ͻÿ� : ";
		cin >> job;
	}
}

// Key �Է� �Լ� ////////////////////////////////////////////////////////////
void key_add()
{
	int key, i;                       // key:�Է°�. i:heap node count
	cout << " * Enter add data : ";
	cin >> key;

	if(HEAP_FULL(n)){                  // heap�� ���� ���ִٸ� �޼��� ���.
		fprintf(stderr, "* The memory is full\n");
		exit(1);
	}

	i=++n;                             // i�� �� ����.(���� �� ��뷮�̸�, �����Ŀ��� ���� ��뷮+1)

	while((i!=1)&&(key>heap[i/2])){    // i���� 1�� �ƴϰų� -> heap�� ���ְų�,
		                               // key�� ���� heap[1/2]�� ����� ������ Ŭ ��� 
		                               // ��, ���� ������ ����� ���� ����� ������ key���� Ŭ ��� ���� ����

		heap[i] = heap[i/2];           // heap[i](���� ������ ���)�� ���� heap[i/2](������ ����� �������)
		                               // �� ���� �Ǹ�
		i/=2;                          // ���� �������� ��ġ�� ���� ���� �̵��Ѵ�.
	}
	heap[i]=key;                       // ������ ���� ���� ��忡 key�� ����.
}                                      

// ��� ���� �Լ� //////////////////////////////////////////////////////////////
void key_delete()
{
//	int temp;
	int i=1;

	if ((!n==0))
		cout << "* ��� ���� : ���� ù ��� = " << heap[1] << endl; //��� ����.
	else {
		cout << " ���� ���� �������." << endl;
		return;
	}

	// ��� �籸�� //
	
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

// �� ��� �Լ� ////////////////////////////////////////////////////////////////
void heap_output()
{
    int i=1;                               // heap�� ���� ����, ��� ī��Ʈ
 
	if(!n){                                // heap�� ������� ��� (n�� 0)
		cout << "* tree is empty *\n";
		return;
	}

	cout << "* ���� �ִ� ���� ���� *\n";   
	cout << " * root is : " << heap[1] << endl; 

	while(i<n){                             // ��� ī��Ʈ�� n(�� ��뷮)���� ���� ����
		i++;
		if(i%2){                            // ����ȣ�� Ȧ�� �϶�
			cout << " * " << heap[i/2];
			cout << "�� �������ڳ��� : " << heap[i] << endl;
			}
		else{                               // ��� ��ȣ�� ¦�� �϶�.
			cout << " * " << heap[i/2];
			cout << "�� ����  �ڳ��� : " << heap[i] << endl;
			}
	}
}


