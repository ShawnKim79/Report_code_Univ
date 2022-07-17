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
		cout << "수행 할 작업은?(a:input, d:output, e:exit) : ";
		cin >> work;

		switch(work)
		{
		case 'a' :
				cout << "입력하고 싶은 값 : ";
				cin >> value;
				input_value(value, tail, array);
				tail++;
			break;
		case 'd' :
			if(head != tail)
			{
				value = output_value(head, array);
				cout << "출력값 : " << value << endl;
				head++;
			} else 
				cout << "현재 큐는 비어 있음" << endl;
			break;
		case 'e' :
			roll = 0;
			break;
		default:
			break;
		}
	

	cout << "현재 큐의 head point : " << head << endl;
	cout << "현재 큐의 tail point : " << tail << endl;

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