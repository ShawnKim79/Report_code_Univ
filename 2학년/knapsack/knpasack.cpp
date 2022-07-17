#include <iostream.h>

int weight[10]={3,7,2,9,12,5,8,6,4,2};

bool knapsack(int, int);

void main()
{
	int target, candidate;
	candidate = 0;
	
	cout << "쓸 수 있는 돈은? : ";
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
// target = 남은 돈, candidate = 살물건
begin
	if target=0;
		then return(true)
	else if (target<0) or (candidate>m)
		then return(true)
	else if knapsack(target-weight[candidate], candidate+1) // 살경우, weight = 물건의 가격
		then begin
			writeln(weight [candidate])

			return (true)
		end
else return(knapsack(target, candidate+1))
*/