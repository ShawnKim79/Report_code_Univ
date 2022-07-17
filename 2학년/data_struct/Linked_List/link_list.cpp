// Linked_List......

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <Malloc.h>

////// List Node ���� /////////////////////////////////////////////////

typedef struct list_node *list_pointer;    // list_node�� �ּҸ� list_pointer�� ����.
struct list_node{
		int data;                          // data : int�� ����.
		list_pointer link;                 // link : �ڿ� �� ����� ������.
};

////////////////////////////////////////////////////////////////////////

list_pointer ptr = NULL;  // ����Ʈ�� ���������� �ʱ�ȭ.

/// �Լ� ProtoType /////////////////////////////////////////////////////

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

	while(op == 'i' || op == 'd'){          // op�� i(insert)�� d(delete)�� ����
		cout << "  * enter integer : "; 
		cin >> d;                           // ����Ʈ�� ����� ���� d

		if(op == 'i')list_insert(d);        // i�϶� ����Ʈ �߰�.
		if(op == 'd')list_delete(d);        // d�϶� ����Ʈ ����.
		list_print();                       // ���� ����Ʈ ���

		cout << endl << " * enter operation type ('i' or 'd' or 'e') ? ";
		cin >> op;
	}
}

//////////////////////////////////////////////////////////////////////////

void list_insert(int x)               // x�� �޾Ƽ� ����.
{
	list_pointer  p, c;               // list_pointer(list_node) ���� p, c 
	p = 0;                            // p�� �ּ� = 0;
	c = ptr;                          // c�� �ּ� = ptr�� �ּ�

	while(c){                         // c�� ���϶� (��尡 �Ѱ��� ������ ��, c�� ������ ��)
		if(c->data == x){             // c�� �����Ͱ� x�� ���ٸ�
			cout << endl << x << " is duplicated" << endl;
			return;
		}
		if(c->data > x)c=0;           // c�� �����Ͱ� x���� ũ�ٸ� c�� �ּҴ� 0
		else{                         // c�� �����Ͱ� x���� �۴ٸ�
			p=c;                      // p�� �ּҿ� c�� �ּ� ����
			c=p->link;                // c�� �ּҴ� p�� ��ũ
		}
	}

	node_insert(&ptr, p, x);  // ��� ����(���� : ptr�� �ּ�, List_pointer(list_node) p�� ������ x)
	return;
}

/////////////////////////////////////////////////////////////////////////////

void node_insert(list_pointer *ptr, list_pointer node, int data)
//�������Լ�:������ ����� ������, �� ����� ������ , ������ ������
{
	list_pointer temp;                                  // list_pointer ���� temp
	temp = (list_pointer)malloc(sizeof(list_node));     // temp�� list_node�� ũ�⸸ŭ �Ҵ��
	                                                    // �޸� ������ �ּҸ� ����.
	if(!temp){                                          // temp�� NULL�϶�
		fprintf(stderr, "* The memory is full\n");      // malloc�� �޸𸮸� �Ҵ��� �� ������ NULL�� �����Ѵ�.
		exit(1);
	}

	temp->data = data;                       // temp�� data����� x�� ����.

	if(node){                                // node�� ������ ���.
		temp->link = node->link;             // temp�� ��ũ�� node�� ��ũ ����.
		node->link = temp;                   // node�� ��ũ�� temp�� �ּ� ����.               
	}
	else{                                    // node�� �������� ���� ���
		temp->link = *ptr;                   // temp�� ��ũ�� ptr�� �ּ� ����. 
		*ptr = temp;                         // ptr�� �ּҿ� temp�� �ּ� ����.
	}
}

//////////////////////////////////////////////////////////////////////////////////

void list_delete(int x)                      // x���� ���� ��� ����.
{
	list_pointer  p, c;                      // list_pointer p, c ����.

	if(!ptr){                                // ptr�� �ּҰ� NULL �ϰ��.
		cout << endl << "* list is empty *" << endl;  // list�� ����ִ�.
		return;
	}

	p = 0;                            // p�� �ּ� : 0
	c = ptr;                          // c�� �ּҿ� ptr�� �ּ� ����.

	while(c){                         // c�� �ּҰ� ������ ���(ptr�� NULL�� �ƴҰ��)
		if(c->data==x){               // c�� �����Ͱ� x�� ���ٸ�
			node_delete(&ptr, p, c);  // node_delete�Լ� ȣ��.
			return;
		}
		if(c->data > x)c=0;           // c�� �����Ͱ� x���� ũ�ٸ� c�� �ּҴ� 0
		else{                         // c�� �����Ͱ� x���� �۴ٸ�
			p=c;                      // p�� �ּҴ� c�� ����
			c=p->link;                // c�� �ּҴ� p�� ��ũ�� ����.
		}
	}
	cout << endl << x << " is not exist in the list " << endl;
	return;
}

////////////////////////////////////////////////////////////////////////////////

void node_delete(list_pointer *ptr, list_pointer trail, list_pointer node)
//�������Լ�:������ ����� ������,  ������ ����� �� ������, ������ ����� ������ 
{
	if(trail)                      // ������ ����� �� ��尡 ������ ���.
		trail->link = node->link;  // ������ ����� ��ũ�� �� ����� ��ũ�� ����
	else                           // ������ ����� �� ��尡 �������� ���� ���.    
		*ptr = (*ptr)->link;       // ptr�� �ּҿ� ptr�� ��ũ ����.
	free(node);                    // ��� ���� 
}

/////////////////////////////////////////////////////////////////////////////////

void list_print()                       // ����Ʈ�� ����Լ�
{
	list_pointer c;                     // ����Ʈ ������ ����
	cout << endl << " * contents of linked-list * " << endl;
	if(!ptr){                           // ptr�� �ּҰ� NULL�� ��� 
		cout << " list is empty \n";    // list�� �������.
		return;
	}
	cout << ptr->data;                  // ptr�� ������ ���.
	c=ptr->link;                        // c�� ptr�� ��ũ ����.
	while(c){                           // c�� ���� �� ����
		cout << " -> " << c->data;      // c�� ������ ���.
		c=c->link;                      // c�� c �ڽ��� ��ũ ����.
	}
	cout << endl;
}

