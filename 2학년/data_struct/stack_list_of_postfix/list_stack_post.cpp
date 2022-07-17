// 리스트를 스택처럼 사용하여 postfix 제작
/*
   1. 스택의 top을 여기서는 리스트의 시작 주소로 한다.

*/
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/// 노드 구조 정의 //////////////////////////////////////////////////

typedef struct stack_node *stack_pointer;

struct stack_node {
    char data;
	stack_pointer next_link;
};

//// 함수 Prototype //////////////////////////////////////////////////

int operand(char);
int Isp(char);
int Icp(char);
void postfix(char *, char *);
void node_insert(stack_pointer*, stack_pointer, char);

//////////////////////////////////////////////////////////////////////

stack_pointer top = NULL;   // 리스트의 시작 포인터 

//////////////////////////////////////////////////////////////////////
void stack_push(char x)
{
	stack_pointer front;

	if(top)  // node가 존재 할때 
	{
		front=(stack_pointer)malloc(sizeof(stack_node));
		front->data = x;
		
		front->next_link = top;
		top=front;		
	}
	else    //node가 존재하지 않을때
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
	char value;  // 되돌려줄 노드 내 데이터.
	
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
char read_stack()          // 스택의 최 상위를 읽음.
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
	char orignal_form[50];                      // 원 식 저장하는 배열
	char postfix_form[50];                      // postfix를 저장하는 배열.
	char c = 'y';                               // 프로그램의 실행 연장 결정.
    while(c=='y')
	{
		cout << endl << "* enter infix expression : "; 
		cin >> orignal_form;                    // 식 입력

		postfix(orignal_form, postfix_form);    // 변환  

		cout << "  * postfix notation : " << postfix_form << endl;
		cout << "\n Do you want to do another expression('y'or'n')? ";
		cin >> c;
	}

}


//////////////////////////////////////////////////////////////////////////

void postfix(char *o_form, char *p_form)
{
	char x;           // 원식 배열의 값 저장.
	int p_count=0 ;   // postfix 배열의 저장 카운터.

    /* stack_pointer read;
	   read = ptr; */

	for(int i=0 ; o_form[i]!='\0' ; i++)
	{
		x = o_form[i];

		if(operand(x))p_form[p_count++] = x;   // 연산자가 아닐경우 배열에 식의 토큰 1개 저장.
        // 그리고 x가 연산자일 경우.....
		else if(x==')'){
			while( read_stack()!='(' ) p_form[p_count++] = stack_pop();
			stack_pop();
			}
		// x가 연산자이나 ()는 아닐경우.....
		else{
			while( Isp( read_stack() ) >= Icp(x) ) p_form[p_count++] = stack_pop();
			// Isp()가 Icp()보다 크거나 같을동안 p_form[]에 stack의 값을 집어 넣는다.
			// Isp()가 Icp()보다 작으면 이 루프는 실행 안된다.
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