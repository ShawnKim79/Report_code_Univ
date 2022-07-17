//더블링크드 리스트

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <Malloc.h>

/// List_Node 정의 ////////////////////////////////////////////////////
/// 참고로 노드의 포인터 변수 선언시 list_pointer를 쓴다.

typedef struct list_node *list_pointer;
struct list_node{
		list_pointer llink;         // 왼쪽 노드의 포인터 주소
		int data;                   // 데이터 저장
		list_pointer rlink;         // 오른족 노드의 포인터 주소
};

//////////////////////////////////////////////////////////////////////

list_pointer ptr = NULL;            // list_pointer ptr에 NULL저장.

//// Function Prototype ///////////////////////////////////////////////

void list_head();
void list_insert(int x);
void node_insert(list_pointer node, int data);
void list_delete(int x);
void node_delete(list_pointer node, list_pointer deleted);
void list_print();

///////////////////////////////////////////////////////////////////////

void main()
{
	char op;
	int d;

	list_head();                                       // 첫 노드 생성.
	cout << endl << " * enter operation type ('i' or 'd' or 'e') ? ";
	cin >> op;
	while(op == 'i' || op == 'd'){
		cout << "  * enter integer : ";
		cin >> d;
		if(op == 'i')list_insert(d);  // d 값을 리스트에 저장.
		if(op == 'd')list_delete(d);  // d 값을 리스트에서 삭제
		list_print();
		cout << endl << " * enter operation type ('i' or 'd' or 'e') ? ";
		cin >> op;
	}
}

//////////////////////////////////////////////////////////////////////////

void list_head()
{
	list_pointer temp;                                // list_pointer temp 선언
	temp = (list_pointer)malloc(sizeof(list_node));   // temp 노드 생성, 노드 주소 temp에 저장.
	if(!temp){                                        // temp가 널일 경우
		fprintf(stderr, "* The memory is full\n");    // 노드 생성 오류
		exit(1);
	}
	ptr = temp;                                       // ptr의 주소는 새 노드의 주소.
	temp->llink = temp;                               // temp의 왼쪽링크는 자기 자신의 주소 
	temp->rlink = temp;                               // temp의 오른쪽링크는 자기 자신의 주소 
	                                                  // 이것이 더블 링크드 리스트의 특징이다.
}

///////////////////////////////////////////////////////////////////////////

void list_insert(int x)                // x값을 리스트에 저장
{
	list_pointer  p, c;                // list_pointer 선언.
	p = ptr;                           // p의 주소는 ptr의 주소 
	c = p->rlink;                      // c의 주소는 p의 오른쪽 링크 주소
	while(c!=ptr){                     // c의 주소와 ptr의 주소가 서로 다를 동안
		if(c->data == x){              // c의 데이터와  x가 같을 경우 
			cout << endl << x << " is duplicated" << endl;
			                           // 에러 메세지 출력
			return;
		}
		if(c->data > x)c=ptr;          // c의 data가 x보다 클 경우 c의 주소는 ptr의 주소 
		else{                          // c의 data가 x보다 작을 경우
			p=c;                       // p의 주소는 c의 주소.
			c=p->rlink;                // c의 주소는 p의 오른쪽 링크의 주소.
		}
	}
	node_insert(p, x);                 // p의 주소와 x값 node_insert에 준다.
	return;
}

/////////////////////////////////////////////////////////////////////////////

void node_insert(list_pointer node, int data) // 리스트의 포인터 주소와 노드에 저장될 데이터.
{
	list_pointer newnode;                     // 새 노드의 포인터 선언.
	newnode = (list_pointer)malloc(sizeof(list_node));  //  새 노드의 포인터로 노드 생성
	if(!newnode){                             // 노드가 생성되지 못했을 경우 
		fprintf(stderr, "* The memory is full\n");      // 에러메세지 출력
		exit(1);
	}
	newnode->data = data;         // 새 노드의 data에 data(x)저장.
	newnode->llink = node;        // 새 노드의 왼쪽 링크 주소는  p의 노드 주소
	newnode->rlink = node->rlink; // 새 노드의 오른쪽 링크 주소는 p의 오른쪽 링크 주소 
	node->rlink->llink = newnode; // p의 오른쪽 링크 주소가 가리키는 노드의 왼쪽 링크 노드는 새 노드
	node->rlink = newnode;        // p의 오른쪽 링크는 새 노드 
}

////////////////////////////////////////////////////////////////////////////

void list_delete(int x)           // x값을 갖는 노드 삭제 
{
	list_pointer  p, c;           // list pointer p, c 선언 
	p = ptr;                      // p의 주소는 ptr의 주소 
	c = p->rlink;                 // c의 주소는 p의 오른쪽 링크(뒷 노드)의 주소 
	if(p==c){                     // p의 주소와 c의 주소 같을경우
		cout << endl << "* list is empty *" << endl; // 리스트는 비어있는 상태
		return;
	}
	while(c!=ptr){                // c의 주소가 ptr과 다를동안
		if(c->data==x){           // c의 주소가 x와 같다면
			node_delete(p, c);    // p와 c의 주소를 node_delete로 보냄
			return;
		}
		if(c->data > x)c=ptr;     // c의 데이터가 x보다 크다면 c의 주소는 ptr의 주소 
		else{                     // c의 데이터가 x보다 작다면 
			p=c;                  // p의 주소는 c의 주소
			c=p->rlink;           // c의 주소는 p의 오른쪽 링크(뒷 노드)의 주소 
		}
	}
	cout << endl << x << " is not exist in the list " << endl;
	return;
}

//////////////////////////////////////////////////////////////////////////////

void node_delete(list_pointer node, list_pointer deleted)  // 노드 삭제 
{
	if(node==deleted)
		cout << "* Deletion of head node not permitted" << endl;  // 
	else{
		deleted->llink->rlink = deleted->rlink;
		deleted->rlink->llink = deleted->llink;
		free(deleted);
	}
}

///////////////////////////////////////////////////////////////////////////////

void list_print()
{
	list_pointer c;
	cout << endl << "    * contents of doubly linked list * " << endl;
	if(ptr==ptr->rlink){
		cout << " list is empty \n";
		return;
	}
	cout << " * forward of linked-list : ";
	c=ptr->rlink;
	cout << c->data;
	c=c->rlink;
	while(c!=ptr){
		cout << " -> " << c->data;
		c=c->rlink;
	}
	cout << endl;
	cout << " * backward of linked-list : ";
	c=ptr->llink;
	cout << c->data;
	c=c->llink;
	while(c!=ptr){
		cout << " -> " << c->data;
		c=c->llink;
	}
	cout << endl;
}
