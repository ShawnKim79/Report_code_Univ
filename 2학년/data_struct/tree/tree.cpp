// Tree structure......

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <Malloc.h>

// define tree node ////////////////////////////////////

typedef struct tree_node *tree_pointer;
struct tree_node{
		tree_pointer lchild;        // ���� ����� �ּ�
		char data;                  // ������ �ʵ�
		tree_pointer rchild;        // ������ ����� �ּ�
};

tree_pointer ptr = NULL;            // ù ����� �ּ� : Null

/////////////////////////////////////////////////////////

// define queue /////////////////////////////////////////
#define queue_size 30                 // queue�� ������ : 30
tree_pointer queue[queue_size];
int front = 0;
int rear = 0;

//////////////////////////////////////////////////////////

int Isfull()                        // queue�� ���� á�°� �˻��ϴ� �Լ�.
{
	if(rear+1==front)return 1;      // rear+1�� front�� ������ 1 ����
	else return 0;                  // �ٸ��� 0 ����
}

//////////////////////////////////////////////////////////

int Isempty()                       // queue�� ������� �˻�.
{
	if(front==rear)return 1;        // front��rear�� ������ 1 ����
	else return 0;                  // �ٸ��� 0����.
}

////////////////////////////////////////////////////////////

void queue_full(int *rear)          // queue�� full�϶� ó��(rear�� �ּҸ� ���ڷ� ����.)
{
	if(*rear==0)*rear=queue_size-1;
		else *rear-=1;
	cout << endl << " ** err : queue full **" << endl;
}

////////////////////////////////////////////////////////////

void queue_add(int *rear, tree_pointer item)
{
	*rear = (*rear+1) % queue_size;
	if(front == *rear){
		queue_full(rear);
		return;
	}
	queue[*rear] = item;
}

tree_pointer queue_empty()
{
	cout << endl << " ** err : queue empty **" << endl;
	return NULL;
}

tree_pointer queue_delete(int *front)
{
	if(*front == rear)
		return queue_empty();
	*front = (*front+1) % queue_size;
	return queue[*front];
}

// tree program
void tree_input();
void node_input();
void child_input(char child, tree_pointer n);
tree_pointer node_creat();
void tree_inorder(tree_pointer ptr);
void tree_preorder(tree_pointer ptr);
void tree_postorder(tree_pointer ptr);

void main()
{
	cout << "�Է��� �� data�� ���� 1�ڸ�, �ڳ�尡 ������ '0'�� �Է��Ͻÿ�.\n";
	tree_input();
	cout << endl << " * tree inorder : ";
	tree_inorder(ptr);
	cout << endl << " * tree preorder : ";
	tree_preorder(ptr);
	cout << endl << " * tree postorder : ";
	tree_postorder(ptr);
	cout << endl;
}

void tree_input()
{
	tree_pointer temp;
	char root;
	cout << " * Enter root data : ";
	cin >> root;
	if(root=='0')return;
	temp = node_creat();
	ptr = temp;
	temp->data = root;
	queue_add(&rear, temp);
	while(!Isempty())node_input();
	cout << endl << "* Tree input completed *" <<endl;
	return;
}

void node_input()
{
	tree_pointer  p;
	p = queue_delete(&front);
	child_input('l',p);
	child_input('r',p);
	return;
}

void child_input(char child, tree_pointer n)
{
	tree_pointer temp;
	char data;
	if(child == 'r')
		cout << " * Enter right ";
	else
		cout << " * Enter left ";
	cout << "child of " << n->data << " : ";
	cin >> data;
	if(data=='0')return;
	temp = node_creat();
	if(child == 'r')
		n->rchild = temp;
	else
		n->lchild = temp;
	temp->data = data;
	queue_add(&rear, temp);
}

tree_pointer node_creat()
{
	tree_pointer temp;
	temp = (tree_pointer)malloc(sizeof(tree_node));
	if(!temp){
		fprintf(stderr, "* The memory is full\n");
		exit(1);
	}
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}

void tree_inorder(tree_pointer ptr)
{
	if(ptr){
		tree_inorder(ptr->lchild);
		cout << ptr->data << ' ';
		tree_inorder(ptr->rchild);
	}
}

void tree_preorder(tree_pointer ptr)
{
	if(ptr){
		cout << ptr->data << ' ';
		tree_preorder(ptr->lchild);
		tree_preorder(ptr->rchild);
	}
}

void tree_postorder(tree_pointer ptr)
{
	if(ptr){
		tree_postorder(ptr->lchild);
		tree_postorder(ptr->rchild);
		cout << ptr->data << ' ';
	}
}