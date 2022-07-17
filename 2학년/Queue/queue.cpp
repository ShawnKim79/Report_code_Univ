#include <iostream.h>

struct node{
	int value;
	node* next;
};

void queue_input(node, int);
int queue_output(node);
void queue_roll(node, node);

void main()
{

	int i, k, rtn, roll;
	roll = 1;

	// �ʱ� ��弳��
	node front;
	node rear;

	rear.next = front.next;

	while(roll)
	{
		cout << "������ �۾���? (input:1, delete:2, end:3) : ";
		cin >> i;
		
		switch(i)
		{
		case 1:
			cout << "�Է��� ���� �ֽʽÿ� : ";
			cin >> k;
			queue_input(front, k);
			break;
		case 2:
			rtn = queue_output(rear);
			cout << "ť�� ��� �� : " << rtn;
			break;
		case 3:
			roll = 0;
			break;
		default:
			break;
		}
		
		queue_roll(front, rear);
	}
}

void queue_roll(node head, node tail);