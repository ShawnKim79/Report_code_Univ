// ����Ʈ�� ����ó�� ����Ͽ� postfix ����
/*
   1. ������ top�� ���⼭�� ����Ʈ�� ���� �ּҷ� �Ѵ�.

*/
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/// ��� ���� ���� //////////////////////////////////////////////////

typedef struct stack_node *stack_pointer;

struct stack_node {
    char data;
	stack_pointer next_link;
};

//// �Լ� Prototype //////////////////////////////////////////////////

int operand(char);
int Isp(char);
int Icp(char);
void postfix(char *, char *);
void node_insert(stack_pointer*, stack_pointer, char);

//////////////////////////////////////////////////////////////////////

stack_pointer top = NULL;   // ����Ʈ�� ���� ������ 

//////////////////////////////////////////////////////////////////////
void stack_push(char x)
{
	stack_pointer front;

	if(top)  // node�� ���� �Ҷ� 
	{
		front=(stack_pointer)malloc(sizeof(stack_node));
		front->data = x;
		
		front->next_link = top;
		top=front;		
	}
	else    //node�� �������� ������
	{
		front=(stack_pointer)malloc(sizeof(stack_node));
		front->data = x;
		top=front;
		front->next_link=NULL;		
	}
	return;
}


//////////////////////////////////////////////////////////////////////
char stack_pop()
{
	char value;  // �ǵ����� ��� �� ������.
	
	if(!top){
		stack_pointer delete_node;
		delete_node = top;
		value = delete_node->data;
		top = delete_node->next_link;
	    return value;
	}
	else
	{
		return '\0';
	}
}


//////////////////////////////////////////////////////////////////////////
char read_stack()          // ������ �� ������ ����.
{
	stack_pointer read;
	if (!top) return '\0';
	else{
		read = top;
		return read->data;
	}
}

//////////////////////////////////////////////////////////////////////

void main()
{
	char orignal_form[50];                      // �� �� �����ϴ� �迭
	char postfix_form[50];                      // postfix�� �����ϴ� �迭.
	char c = 'y';                               // ���α׷��� ���� ���� ����.
    while(c=='y')
	{
		cout << endl << "* enter infix expression : "; 
		cin >> orignal_form;                    // �� �Է�

		postfix(orignal_form, postfix_form);    // ��ȯ  

		cout << "  * postfix notation : " << postfix_form << endl;
		cout << "\n Do you want to do another expression('y'or'n')? ";
		cin >> c;
	}

}


//////////////////////////////////////////////////////////////////////////

void postfix(char *o_form, char *p_form)
{
	char x;           // ���� �迭�� �� ����.
	int p_count=0 ;   // postfix �迭�� ���� ī����.

    /* stack_pointer read;
	   read = ptr; */

	for(int i=0 ; o_form[i]!='\0' ; i++)
	{
		x = o_form[i];

		if(operand(x))p_form[p_count++] = x;   // �����ڰ� �ƴҰ�� �迭�� ���� ��ū 1�� ����.
        // �׸��� x�� �������� ���.....
		else if(x==')'){
			while( read_stack()!='(' ) p_form[p_count++] = stack_pop();
			stack_pop();
			}
		// x�� �������̳� ()�� �ƴҰ��.....
		else{
			while( Isp( read_stack() ) >= Icp(x) ) p_form[p_count++] = stack_pop();
			// Isp()�� Icp()���� ũ�ų� �������� p_form[]�� stack�� ���� ���� �ִ´�.
			// Isp()�� Icp()���� ������ �� ������ ���� �ȵȴ�.
			stack_push(x);
			}
	}

	while( (x=stack_pop()) != '\0')
		p_form[p_count++] = x;
	p_form[p_count] = '\0';
	return;
}

////////////////////////////////////////////////////////////////////////////

int operand(char x)
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};
	for(int i=0; i<8; i++)if(op[i]==x)return 0;
	return 1;
}

/////////////////////////////////////////////////////////////////////////////

int Isp(char x)
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};
	int sp[8] =  {  0, 19, 12, 12, 13, 13, 13,0};
	int i;
	for(i=0; i<8; i++)if(op[i]==x)return sp[i];
	cout << "* Isp error *\n";
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

int Icp(char x)
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};
	int cp[8] = {  20, 19, 12, 12, 13, 13, 13,0};
	int i;
	for(i=0; i<8; i++)if(op[i]==x)return cp[i];
	cout << "* Icp error *\n";
	return 0;
}