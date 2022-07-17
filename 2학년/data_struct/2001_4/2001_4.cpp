#include <iostream.h>
#include <stdlib.h>

// ���ڸ� �����ϴ� ���ð� �Լ� ���� //////////////////////////////////

#define char_stack_size 30                 // ������ : 30
char char_stack[char_stack_size];          // ���� ����.
int char_top = -1;                         // top ����

///////////////////////////////////////////////////////////////////////

int char_Isfull()
{
	if(char_top>=char_stack_size-1)return 1;  // ������ ���� á�� ��� 1 ����.
	else return 0;
}

///////////////////////////////////////////////////////////////////////

int char_Isempty()
{
	if(char_top<=-1)return 1; // ������ ����� ��� 1 ����.
	else return 0;
}

////////////////////////////////////////////////////////////////////////

void char_stack_full()  // ������ ���� á����� ���� �޼��� ���
{
	cout << endl << " ** err : char_stack full **" << endl;
}

////////////////////////////////////////////////////////////////////////

void char_stack_add(char item)          // item�� ���ÿ� �߰�.
{
	if(char_top>=char_stack_size-1){    // top�� ���� ������-1���� ���ų� ũ�� ������ ���� ��.
		char_stack_full();
		return;
	}
	char_stack[++char_top] = item;      // ������ top+1�� �濡 item ����.
}

////////////////////////////////////////////////////////////////////////

char char_stack_empty()                 // ������ ����� ��� �޼��� ���.
{
	cout << endl << " ** err : char_stack empty **" << endl;
	char_stack[0] = '0';
	return char_stack[0];
}

////////////////////////////////////////////////////////////////////////

char char_stack_delete()
{
	char item;
	if(char_top <= -1)                // ������ top�� -1���� �۰ų� ������ ������ �� ����.
		return char_stack_empty();    
	item = char_stack[char_top--];    // ���ÿ� ���� ���� ��� char_stack[top]�� ���� �����ϰ�
	                                  // top-1�� ��.
	return item;
}

// ���ڸ� �����ϴ� ���� ���� �� ////////////////////////////////////////

// ������ �����ϴ� ���ð� �Լ� ���� ////////////////////////////////////

#define int_stack_size 30            // ������ ����
int int_stack[int_stack_size];       // ���� ����
int int_top = -1;                    // top ����

////////////////////////////////////////////////////////////////////////

int int_Isfull()
{
	if(int_top>=int_stack_size-1)return 1;  // top�� ���� ������-1���� ũ�� return 1
	else return 0;
}

////////////////////////////////////////////////////////////////////////

int int_Isempty()
{
	if(int_top<=-1)return 1;   // top�� -1���� ������ return 1
	else return 0;
}

/////////////////////////////////////////////////////////////////////////

void int_stack_full()          // ������ ���� á���� ���� �޼���.
{
	cout << endl << " ** err : int_stack full **" << endl;
}

/////////////////////////////////////////////////////////////////////////

void int_stack_add(int item)          // item�� ���ÿ� ����
{
	if(int_top>=int_stack_size-1){    // int_top�� ���� ������� ���ų� ũ��
		int_stack_full();             // ������ Full
		return;
	}
	int_stack[++int_top] = item;      // �ƴҰ��, stack[top]�� �� ���� �� top+1
}

//////////////////////////////////////////////////////////////////////////

int int_stack_empty()                 // ������ ����� ��� ���� �޼��� ���
{
	cout << endl << " ** err : int_stack empty **" << endl;
	int_stack[0] = '0';
	return int_stack[0];
}

///////////////////////////////////////////////////////////////////////////

int int_stack_delete()
{
	int item;  
	if(int_top <= -1)               // top�� -1 ���� �۰ų� ������ ������ Empty
		return int_stack_empty();   // ���� �޼��� ���
	item = int_stack[int_top--];    // �ƴҰ��, stack[top]�� ���� �����ϰ� top-1
	return item;
}

// ������ �����ϴ� ���� ���� �� ///////////////////////////////////////////

// �Լ� Prototype /////////////////////////////////////////////////////////

int operand(char x);
int Isp(char x);
int Icp(char x);
void postfix(char *token, char *post);
int eval(char *post);

///////////////////////////////////////////////////////////////////////////

void main()
{
    char exp[50];              // �� ���� �����ϴ� �迭
	char post[50];             // ������� �����ϴ� �迭
	int r;

	char c = 'y';
    while(c=='y')
	{
		cout << endl << "* enter infix expression : ";
		cin >> exp;            // �� �� ����.
		postfix(exp, post);    // postfix�� ��ȯ
		cout << "  * postfix notation : " << post << endl;
		r = eval(post);        // ������� �Ѱ��ְ� r�� ���� �� ����.
		cout << "  * result of expression : ";

		if(int_Isempty())      // ���������� ����� ���, ���� ���� ���ڷ� ����.
			cout << r;
			else
			cout << "operand is character";

		cout << "\n\n Do you want to do another expression('y'or'n')? ";
		cin >> c;
	}
}

////////////////////////////////////////////////////////////////////////////////

int operand(char x)     // x�� �޾Ƽ�, 
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};
	for(int i=0; i<8; i++)if(op[i]==x)return 0;      // x�� �������� ��� 0�� ����.
	return 1;
}

/////////////////////////////////////////////////////////////////////////////////

int Isp(char x)         // x�� �޾Ƽ�, 
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};
	int sp[8] =   {0 , 19, 12, 12, 13, 13, 13,0};
	int i;
	for(i=0; i<8; i++)if(op[i]==x)return sp[i];   // op[i]�� x�� ������ sp[i]�� ����.
	cout << "* Isp error *\n";
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////

int Icp(char x)         // x�� �޾Ƽ�, 
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};
	int cp[8] = {  20, 19, 12, 12, 13, 13, 13,0};
	int i;
	for(i=0; i<8; i++)if(op[i]==x)return cp[i];   // op[i]�� x�� ������ cp[i]�� ����.
	cout << "* Icp error *\n";
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////

void postfix(char *token, char *post)   // token - �� �� �迭, post - ��� �迭
{
	char x;
	int ipost = 0;
	char_top = -1;
	char_stack_add('\0');                    // char_stack�� \0 ����

	for(int i=0; token[i]!='\0'; i++)        // ���ý� �迭���� �ϳ��� ���� �����´�.
	{
		x=token[i];                          // x�� �迭�� �� ����.

		if(operand(x))post[ipost++] = x;     // x�� �����ڰ� �ƴҰ�� post[]�� ����.
		else if(x==')'){                     // x�� �������� ���, ')'���
			while(char_stack[char_top]!='(')post[ipost++] = char_stack_delete(); 
			   // char_stack�� ���� '('�� �ƴ� ���� post[]�� char_stack[]�� ���� ����.
			char_stack_delete();             //
			}
		else{                                // x�� �����ڵ� �ƴϸ� ��ȣ�� �ƴҰ��, 
			while(Isp(char_stack[char_top])>=Icp(x))post[ipost++] = char_stack_delete();
          //Isp(char_stack[top])�� ���� Icp(x)���� ũ�ų� �������� post[]�� char_stack�� ����.
		  //    
			char_stack_add(x);
			}
	}
	while((x=char_stack_delete()) != '\0')            // x�� ���� �����ҵ���(������ ������ ����)
		post[ipost++] = x;            // post[]�� x��(char_stack[]�� ��)����.
	post[ipost] = '\0';
	return;
}

///////////////////////////////////////////////////////////////////////////////////////

int eval(char *token)      // postfix�� ���� �޾Ƽ�
{
	char x;
	int op1, op2;
	int_top = -1;

	for(int i=0; token[i]!='\0'; i++)   // token�� ���� ������ ����
	{
		x=token[i];                     // token�� ���� x�� ����.
		if(operand(x)){                 // x�� �����ڰ� �ƴϰ�
			if(x<'0'|| x>'9'){          // x�� 0���� �۰� 9���� ũ�ٸ� 
				int_top = 1;            // int_top�� 1.
				return 0;
			}
			int_stack_add(atoi(&x));    // int_stack�� x(���ڿ�)�� int������ ��ȯ�Ͽ� ����.
		}
		else{                           // x�� �����ڰ� �ƴ϶��
			op2=int_stack_delete();     // op2�� int_stack[top]�� ����.
			op1=int_stack_delete();     // op1�� int_stack[top-]�� ����.
			switch(x){                  // x�� �������϶� ���� ���ش�
				case '+': int_stack_add(op1+op2);
							break;
				case '-': int_stack_add(op1-op2);
							break;
				case '*': int_stack_add(op1*op2);
							break;
				case '/': int_stack_add(op1/op2);
							break;
				case '%': int_stack_add(op1%op2);
			}                           // ������ ���� int_stack�� ����.
		}
	}
	return int_stack_delete();          // for���� ����Ǹ� int_stack[top]�� ���� ����.
}
