#include <iostream.h>

int weight[10]={3,7,2,9,12,5,8,6,4,2};

bool knapsack(int, int);

void main()
{
	int target, candidate;
	candidate = 0;
	
	cout << "�� �� �ִ� ����? : ";
	cin >> target;

	knapsack(target, candidate);

	cout << endl;
	
}

bool knapsack(int target, int candidate)
{
	if (target == 0)
		return(true);
	else if ((target < 0) || (candidate > 10))
		return(false);
	else if (knapsack(target-weight[candidate], candidate+1))
	{
		cout << weight[candidate] << " "; 
		return (true);
	}
	else return (knapsack(target, candidate+1));
}

/*
proc knapsack(target:int ; candidate:int) boolean;
// target = ���� ��, candidate = �칰��
begin
	if target=0;
		then return(true)
	else if (target<0) or (candidate>m)
		then return(true)
	else if knapsack(target-weight[candidate], candidate+1) // ����, weight = ������ ����
		then begin
			writeln(weight [candidate])

			return (true)
		end
else return(knapsack(target, candidate+1))
*/