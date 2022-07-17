#include <iostream.h>

void input_value(int, int, int []);
int output_value(int, int []);

void main()
{
	int array[10];
	int head, tail, roll;
	char work;
	int value, count;
	head = 0;
	tail = 0;
	roll = 1;

	for (count=0 ; count<=9 ; count++)
		array[count]=0;

	while(roll)
	{
		cout << "���� �� �۾���?(a:input, d:output, e:exit) : ";
		cin >> work;

		switch(work)
		{
		case 'a' :
				cout << "�Է��ϰ� ���� �� : ";
				cin >> value;
				input_value(value, tail, array);
				tail++;
			break;
		case 'd' :
			if(head != tail)
			{
				value = output_value(head, array);
				cout << "��°� : " << value << endl;
				head++;
			} else 
				cout << "���� ť�� ��� ����" << endl;
			break;
		case 'e' :
			roll = 0;
			break;
		default:
			break;
		}
	

	cout << "���� ť�� head point : " << head << endl;
	cout << "���� ť�� tail point : " << tail << endl;

	for (count=0 ; count<=9 ; count++)
		cout << "|" << array[count] << "|";
	cout << endl << endl;
	
	}

}

void input_value(int v, int t, int a[])
{
	a[t] = v;
}

int output_value(int h, int b[])
{
	int temp;
	temp = b[h];
	b[h] = 0;
	return temp;
}