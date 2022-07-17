//����ũ�� ����Ʈ

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <Malloc.h>

/// List_Node ���� ////////////////////////////////////////////////////
/// ����� ����� ������ ���� ����� list_pointer�� ����.

typedef struct list_node *list_pointer;
struct list_node{
		list_pointer llink;         // ���� ����� ������ �ּ�
		int data;                   // ������ ����
		list_pointer rlink;         // ������ ����� ������ �ּ�
};

//////////////////////////////////////////////////////////////////////

list_pointer ptr = NULL;            // list_pointer ptr�� NULL����.

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

	list_head();                                       // ù ��� ����.
	cout << endl << " * enter operation type ('i' or 'd' or 'e') ? ";
	cin >> op;
	while(op == 'i' || op == 'd'){
		cout << "  * enter integer : ";
		cin >> d;
		if(op == 'i')list_insert(d);  // d ���� ����Ʈ�� ����.
		if(op == 'd')list_delete(d);  // d ���� ����Ʈ���� ����
		list_print();
		cout << endl << " * enter operation type ('i' or 'd' or 'e') ? ";
		cin >> op;
	}
}

//////////////////////////////////////////////////////////////////////////

void list_head()
{
	list_pointer temp;                                // list_pointer temp ����
	temp = (list_pointer)malloc(sizeof(list_node));   // temp ��� ����, ��� �ּ� temp�� ����.
	if(!temp){                                        // temp�� ���� ���
		fprintf(stderr, "* The memory is full\n");    // ��� ���� ����
		exit(1);
	}
	ptr = temp;                                       // ptr�� �ּҴ� �� ����� �ּ�.
	temp->llink = temp;                               // temp�� ���ʸ�ũ�� �ڱ� �ڽ��� �ּ� 
	temp->rlink = temp;                               // temp�� �����ʸ�ũ�� �ڱ� �ڽ��� �ּ� 
	                                                  // �̰��� ���� ��ũ�� ����Ʈ�� Ư¡�̴�.
}

///////////////////////////////////////////////////////////////////////////

void list_insert(int x)                // x���� ����Ʈ�� ����
{
	list_pointer  p, c;                // list_pointer ����.
	p = ptr;                           // p�� �ּҴ� ptr�� �ּ� 
	c = p->rlink;                      // c�� �ּҴ� p�� ������ ��ũ �ּ�
	while(c!=ptr){                     // c�� �ּҿ� ptr�� �ּҰ� ���� �ٸ� ����
		if(c->data == x){              // c�� �����Ϳ�  x�� ���� ��� 
			cout << endl << x << " is duplicated" << endl;
			                           // ���� �޼��� ���
			return;
		}
		if(c->data > x)c=ptr;          // c�� data�� x���� Ŭ ��� c�� �ּҴ� ptr�� �ּ� 
		else{                          // c�� data�� x���� ���� ���
			p=c;                       // p�� �ּҴ� c�� �ּ�.
			c=p->rlink;                // c�� �ּҴ� p�� ������ ��ũ�� �ּ�.
		}
	}
	node_insert(p, x);                 // p�� �ּҿ� x�� node_insert�� �ش�.
	return;
}

/////////////////////////////////////////////////////////////////////////////

void node_insert(list_pointer node, int data) // ����Ʈ�� ������ �ּҿ� ��忡 ����� ������.
{
	list_pointer newnode;                     // �� ����� ������ ����.
	newnode = (list_pointer)malloc(sizeof(list_node));  //  �� ����� �����ͷ� ��� ����
	if(!newnode){                             // ��尡 �������� ������ ��� 
		fprintf(stderr, "* The memory is full\n");      // �����޼��� ���
		exit(1);
	}
	newnode->data = data;         // �� ����� data�� data(x)����.
	newnode->llink = node;        // �� ����� ���� ��ũ �ּҴ�  p�� ��� �ּ�
	newnode->rlink = node->rlink; // �� ����� ������ ��ũ �ּҴ� p�� ������ ��ũ �ּ� 
	node->rlink->llink = newnode; // p�� ������ ��ũ �ּҰ� ����Ű�� ����� ���� ��ũ ���� �� ���
	node->rlink = newnode;        // p�� ������ ��ũ�� �� ��� 
}

////////////////////////////////////////////////////////////////////////////

void list_delete(int x)           // x���� ���� ��� ���� 
{
	list_pointer  p, c;           // list pointer p, c ���� 
	p = ptr;                      // p�� �ּҴ� ptr�� �ּ� 
	c = p->rlink;                 // c�� �ּҴ� p�� ������ ��ũ(�� ���)�� �ּ� 
	if(p==c){                     // p�� �ּҿ� c�� �ּ� �������
		cout << endl << "* list is empty *" << endl; // ����Ʈ�� ����ִ� ����
		return;
	}
	while(c!=ptr){                // c�� �ּҰ� ptr�� �ٸ�����
		if(c->data==x){           // c�� �ּҰ� x�� ���ٸ�
			node_delete(p, c);    // p�� c�� �ּҸ� node_delete�� ����
			return;
		}
		if(c->data > x)c=ptr;     // c�� �����Ͱ� x���� ũ�ٸ� c�� �ּҴ� ptr�� �ּ� 
		else{                     // c�� �����Ͱ� x���� �۴ٸ� 
			p=c;                  // p�� �ּҴ� c�� �ּ�
			c=p->rlink;           // c�� �ּҴ� p�� ������ ��ũ(�� ���)�� �ּ� 
		}
	}
	cout << endl << x << " is not exist in the list " << endl;
	return;
}

//////////////////////////////////////////////////////////////////////////////

void node_delete(list_pointer node, list_pointer deleted)  // ��� ���� 
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
