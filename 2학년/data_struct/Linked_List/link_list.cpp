// Linked_List......

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <Malloc.h>

////// List Node 정의 /////////////////////////////////////////////////

typedef struct list_node *list_pointer;    // list_node의 주소를 list_pointer가 가짐.
struct list_node{
		int data;                          // data : int값 저장.
		list_pointer link;                 // link : 뒤에 올 노드의 포인터.
};

////////////////////////////////////////////////////////////////////////

list_pointer ptr = NULL;  // 리스트의 시작포인터 초기화.

/// 함수 ProtoType /////////////////////////////////////////////////////

void list_insert(int x);  
void node_insert(list_pointer *ptr, list_pointer node, int data);
void list_delete(int x);
void node_delete(list_pointer *ptr, list_pointer trail, list_pointer node);
void list_print();

/////////////////////////////////////////////////////////////////////////

void main()
{
	char op;
	int d;

	cout << endl << " * enter operation type ('i' or 'd' or 'e') ? ";
	cin >> op;

	while(op == 'i' || op == 'd'){          // op가 i(insert)나 d(delete)일 동안
		cout << "  * enter integer : "; 
		cin >> d;                           // 리스트에 저장될 변수 d

		if(op == 'i')list_insert(d);        // i일때 리스트 추가.
		if(op == 'd')list_delete(d);        // d일때 리스트 삭제.
		list_print();                       // 현재 리스트 출력

		cout << endl << " * enter operation type ('i' or 'd' or 'e') ? ";
		cin >> op;
	}
}

//////////////////////////////////////////////////////////////////////////

void list_insert(int x)               // x를 받아서 저장.
{
	list_pointer  p, c;               // list_pointer(list_node) 변수 p, c 
	p = 0;                            // p의 주소 = 0;
	c = ptr;                          // c의 주소 = ptr의 주소

	while(c){                         // c가 참일때 (노드가 한개라도 존재할 때, c가 존재할 때)
		if(c->data == x){             // c의 데이터가 x와 같다면
			cout << endl << x << " is duplicated" << endl;
			return;
		}
		if(c->data > x)c=0;           // c의 데이터가 x보다 크다면 c의 주소는 0
		else{                         // c의 데이터가 x보다 작다면
			p=c;                      // p의 주소에 c의 주소 저장
			c=p->link;                // c의 주소는 p의 링크
		}
	}

	node_insert(&ptr, p, x);  // 노드 삽입(인자 : ptr의 주소, List_pointer(list_node) p와 데이터 x)
	return;
}

/////////////////////////////////////////////////////////////////////////////

void node_insert(list_pointer *ptr, list_pointer node, int data)
//노드삽입함수:마지막 노드의 포인터, 새 노드의 포인터 , 저장할 데이터
{
	list_pointer temp;                                  // list_pointer 변수 temp
	temp = (list_pointer)malloc(sizeof(list_node));     // temp는 list_node의 크기만큼 할당된
	                                                    // 메모리 공간의 주소를 가짐.
	if(!temp){                                          // temp가 NULL일때
		fprintf(stderr, "* The memory is full\n");      // malloc는 메모리를 할당할 수 없을때 NULL을 리턴한다.
		exit(1);
	}

	temp->data = data;                       // temp의 data멤버에 x값 저장.

	if(node){                                // node가 존재할 경우.
		temp->link = node->link;             // temp의 링크에 node의 링크 저장.
		node->link = temp;                   // node의 링크에 temp의 주소 저장.               
	}
	else{                                    // node가 존재하지 않을 경우
		temp->link = *ptr;                   // temp의 링크에 ptr의 주소 저장. 
		*ptr = temp;                         // ptr의 주소에 temp의 주소 저장.
	}
}

//////////////////////////////////////////////////////////////////////////////////

void list_delete(int x)                      // x값을 가진 노드 삭제.
{
	list_pointer  p, c;                      // list_pointer p, c 선언.

	if(!ptr){                                // ptr의 주소가 NULL 일경우.
		cout << endl << "* list is empty *" << endl;  // list는 비어있다.
		return;
	}

	p = 0;                            // p의 주소 : 0
	c = ptr;                          // c의 주소에 ptr의 주소 저장.

	while(c){                         // c의 주소가 존재할 경우(ptr이 NULL이 아닐경우)
		if(c->data==x){               // c의 데이터가 x와 같다면
			node_delete(&ptr, p, c);  // node_delete함수 호출.
			return;
		}
		if(c->data > x)c=0;           // c의 데이터가 x보다 크다면 c의 주소는 0
		else{                         // c의 데이터가 x보다 작다면
			p=c;                      // p의 주소는 c와 같고
			c=p->link;                // c의 주소는 p의 링크와 같다.
		}
	}
	cout << endl << x << " is not exist in the list " << endl;
	return;
}

////////////////////////////////////////////////////////////////////////////////

void node_delete(list_pointer *ptr, list_pointer trail, list_pointer node)
//노드삭제함수:마지막 노드의 포인터,  제거할 노드의 앞 포인터, 제거할 노드의 포인터 
{
	if(trail)                      // 제거할 노드의 앞 노드가 존재할 경우.
		trail->link = node->link;  // 제거할 노드의 링크를 앞 노드의 링크에 저장
	else                           // 제거할 노드의 앞 노드가 존재하지 않을 경우.    
		*ptr = (*ptr)->link;       // ptr의 주소에 ptr의 링크 저장.
	free(node);                    // 노드 삭제 
}

/////////////////////////////////////////////////////////////////////////////////

void list_print()                       // 리스트의 출력함수
{
	list_pointer c;                     // 리스트 포인터 선언
	cout << endl << " * contents of linked-list * " << endl;
	if(!ptr){                           // ptr의 주소가 NULL일 경우 
		cout << " list is empty \n";    // list는 비어있음.
		return;
	}
	cout << ptr->data;                  // ptr의 데이터 출력.
	c=ptr->link;                        // c에 ptr의 링크 저장.
	while(c){                           // c가 존재 할 동안
		cout << " -> " << c->data;      // c의 데이터 출력.
		c=c->link;                      // c에 c 자신의 링크 저장.
	}
	cout << endl;
}

