// postfix ���α׷�.........

#include <iostream.h>

// ���ڸ� �����ϴ� ���ð� �Լ� ���� //////////////////////////////

#define char_stack_size 30         // 30ĭ�� ����.
char char_stack[char_stack_size];  // ���� ����.
int char_top = -1;

///////////////////////////////////////////////////////////////////

int char_Isfull()                               // ������ ���� á�� ���.
{
	if(char_top>=char_stack_size-1)return 1;    // ������ top�� ���� ������ ���� ���ų� Ŭ�� ������ ���� ��
	else return 0;
}

///////////////////////////////////////////////////////////////////

int char_Isempty()
{
	if(char_top<=-1)return 1;  // ������ top�� -1���� ���ų� ������. ������ ����ִ�.
	else return 0;
}

/////////////////////////////////////////////////////////////////////

void char_stack_full()
{
	cout << endl << " ** err : char_stack full **" << endl;  // ������ Full�϶� �޼��� ���
}

/////////////////////////////////////////////////////////////////////

void char_stack_add(char item)              // ���ÿ� ���� �߰��ϴ� �ڵ�
{
	if(char_top>=char_stack_size-1){        // char_top�� char_stack_size-1���� ũ��
		char_stack_full();                  // ������ ���� ��.
		return;                             // �ٷ� �Լ� ����
	}
	char_stack[++char_top] = item;          // �׷��� ���� ���, top�� 1�� ���Ѱ��� item ����.
}

/////////////////////////////////////////////////////////////////////

char char_stack_empty()                     // ������ ������� ���
{
	cout << endl << " ** err : char_stack empty **" << endl;   // �޼��� �����
	char_stack[0] = '0';                    // ������ 0�� ���� �ʱ�ȭ 
	return char_stack[0];
}

//////////////////////////////////////////////////////////////////////

char char_stack_delete()                    // ���ÿ� ���� �ϳ� ����.
{
	char item;
	if(char_top <= -1)                      // top�� ���� -1 ���� �۰ų� ������ ����ִ� ����.
		return char_stack_empty();
	item = char_stack[char_top--];          // �׷��� ������ top�� ���� item�� �����ϰ� top�� ���� -1
	return item;
}

/// ���ڸ� �����ϴ� ���� ���� �� ///////////////////////////////////////

// �Լ� Prototype ///////////////////////////////////////////////////////

int operand(char x);
int Isp(char x);
int Icp(char x);
void postfix(char *token, char *post);

////////////////////////////////////////////////////////////////////////////

void main()
{
    char exp[50];      // ������� ������ �迭.
	char post[50];     // ����� ������ �迭.
	char c = 'y';
    while(c=='y')
	{
		cout << endl << "* enter infix expression : ";
		cin >> exp; 
		postfix(exp, post);   // �迭�� postfix�� ������(������ �ּ�)
		cout << "  * postfix notation : " << post << endl;
		cout << "\n Do you want to do another expression('y'or'n')? ";
		cin >> c;
	}
}

////////////////////////////////////////////////////////////////////////////////

int operand(char x)                                   // x�� �޾� ��.
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};  // �迭 �ʱ�ȭ.
	for(int i=0; i<8; i++)if(op[i]==x)return 0;       // �迭�� ���� x�� ���� ������ 0 ����.
	return 1;
}

//////////////////////////////////////////////////////////////////////////////

int Isp(char x)                                         // x �޾� ��.
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};    //  �迭 �ʱ�ȭ 
	int sp[8] =  { 0, 19, 12, 12, 13, 13, 13,  0};
	int i; 
	for(i=0; i<8; i++)if(op[i]==x)return sp[i];         // op[i]�� ���� x�� ������ ���� �κ��� ��� ���� �� ��ȣ��
														// sp[i]�迭�� �� ����.
	cout << "* Isp error *\n";
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

int Icp(char x)                                         // x �޾� ��.
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};    // �迭 �ʱ�ȭ.
	int cp[8] =  {20, 19, 12, 12, 13, 13, 13,  0};
	int i;
	for(i=0; i<8; i++)if(op[i]==x)return cp[i];         // op[i]�� ���� x�� ������ cp[i]����.

	cout << "* Icp error *\n";
	return 0;
}

////////////////////////////////////////////////////////////////////////////////

void postfix(char *token, char *post)   // ���Ĺ迭 exp -> token, ����迭 post -> post
{
	char x;
	int ipost = 0;
	char_top = -1;
	char_stack_add('\0');                  // char_stack�� 0���� '\0' ���� 

	for(int i=0; token[i]!='\0'; i++)      // token[i]�� '\0'�� �ɶ�����
	{  
		x=token[i];                        // x�� token[i] ����.
		if(operand(x)) post[ipost++] = x;  // x�� 1�� ���(x�� �����ڰ� �ƴ� ���) post�� ����

		else if(x==')'){                   // x�� ) �� ���
			while(char_stack[char_top]!='(')post[ipost++] = char_stack_delete(); 
			                               // char_stack[top]�� ( �� �ƴҵ��� post[]�� char_stack�� �� ����.
			char_stack_delete();           // char_stack[top]�� ( ��� ( ���� post[]�� ����.
			}

		else{                              // x�� �����ڵ�, ()�� �ƴҰ��
			while( Isp(char_stack[char_top])>=Icp(x) ) post[ipost++] = char_stack_delete();
                // Isp(char_stack�� �ֻ��� ���� Icp(x)���� ũ�ų� ���� ����
                // post[]�� char_stack�� �� ����.
			char_stack_add(x);  // Isp(char_stack�� �ֻ��� ��)�� Icp(x)���� �۴ٸ� char_stack�� x ����.
			}
	}

	while( (x=char_stack_delete()) != '\0' ) // char_stack���� ���� ���� '\0'�� �ƴҵ���
		post[ipost++] = x;                   // post[]�� x�� ���� �ִ´�.
	post[ipost] = '\0';                      // ������ ���� �� �迭�� �������� '\0'
	return;
}

