#include <iostream.h>
#include <stdlib.h>

// 문자를 저장하는 스택과 함수 정의 //////////////////////////////////

#define char_stack_size 30                 // 사이즈 : 30
char char_stack[char_stack_size];          // 스택 선언.
int char_top = -1;                         // top 선언

///////////////////////////////////////////////////////////////////////

int char_Isfull()
{
	if(char_top>=char_stack_size-1)return 1;  // 스택이 가득 찼을 경우 1 리턴.
	else return 0;
}

///////////////////////////////////////////////////////////////////////

int char_Isempty()
{
	if(char_top<=-1)return 1; // 스택이 비었을 경우 1 리턴.
	else return 0;
}

////////////////////////////////////////////////////////////////////////

void char_stack_full()  // 스택이 가득 찼을경우 에러 메세지 출력
{
	cout << endl << " ** err : char_stack full **" << endl;
}

////////////////////////////////////////////////////////////////////////

void char_stack_add(char item)          // item을 스택에 추가.
{
	if(char_top>=char_stack_size-1){    // top이 스택 사이즈-1보다 같거나 크면 스택은 가득 참.
		char_stack_full();
		return;
	}
	char_stack[++char_top] = item;      // 스택의 top+1번 방에 item 저장.
}

////////////////////////////////////////////////////////////////////////

char char_stack_empty()                 // 스택이 비었을 경우 메세지 출력.
{
	cout << endl << " ** err : char_stack empty **" << endl;
	char_stack[0] = '0';
	return char_stack[0];
}

////////////////////////////////////////////////////////////////////////

char char_stack_delete()
{
	char item;
	if(char_top <= -1)                // 스택의 top이 -1보다 작거나 같으면 스택은 빈 상태.
		return char_stack_empty();    
	item = char_stack[char_top--];    // 스택에 값이 있을 경우 char_stack[top]의 값을 리턴하고
	                                  // top-1을 함.
	return item;
}

// 문자를 저장하는 스택 정의 끝 ////////////////////////////////////////

// 정수를 저장하는 스택과 함수 정의 ////////////////////////////////////

#define int_stack_size 30            // 사이즈 지정
int int_stack[int_stack_size];       // 스택 선언
int int_top = -1;                    // top 선언

////////////////////////////////////////////////////////////////////////

int int_Isfull()
{
	if(int_top>=int_stack_size-1)return 1;  // top이 스택 사이즈-1보다 크면 return 1
	else return 0;
}

////////////////////////////////////////////////////////////////////////

int int_Isempty()
{
	if(int_top<=-1)return 1;   // top이 -1보다 작으면 return 1
	else return 0;
}

/////////////////////////////////////////////////////////////////////////

void int_stack_full()          // 스택이 가득 찼을때 에러 메세지.
{
	cout << endl << " ** err : int_stack full **" << endl;
}

/////////////////////////////////////////////////////////////////////////

void int_stack_add(int item)          // item을 스택에 저장
{
	if(int_top>=int_stack_size-1){    // int_top이 스택 사이즈보다 같거나 크면
		int_stack_full();             // 스택은 Full
		return;
	}
	int_stack[++int_top] = item;      // 아닐경우, stack[top]에 값 저장 후 top+1
}

//////////////////////////////////////////////////////////////////////////

int int_stack_empty()                 // 스택이 비었을 경우 에러 메세지 출력
{
	cout << endl << " ** err : int_stack empty **" << endl;
	int_stack[0] = '0';
	return int_stack[0];
}

///////////////////////////////////////////////////////////////////////////

int int_stack_delete()
{
	int item;  
	if(int_top <= -1)               // top이 -1 보다 작거나 같으면 스택은 Empty
		return int_stack_empty();   // 에러 메세지 출력
	item = int_stack[int_top--];    // 아닐경우, stack[top]의 값을 리턴하고 top-1
	return item;
}

// 정수를 저장하는 스택 정의 끝 ///////////////////////////////////////////

// 함수 Prototype /////////////////////////////////////////////////////////

int operand(char x);
int Isp(char x);
int Icp(char x);
void postfix(char *token, char *post);
int eval(char *post);

///////////////////////////////////////////////////////////////////////////

void main()
{
    char exp[50];              // 원 식을 저장하는 배열
	char post[50];             // 결과식을 저장하는 배열
	int r;

	char c = 'y';
    while(c=='y')
	{
		cout << endl << "* enter infix expression : ";
		cin >> exp;            // 원 식 저장.
		postfix(exp, post);    // postfix로 변환
		cout << "  * postfix notation : " << post << endl;
		r = eval(post);        // 결과식을 넘겨주고 r에 리턴 값 저장.
		cout << "  * result of expression : ";

		if(int_Isempty())      // 정수스택이 비었을 경우, 식은 전부 문자로 구성.
			cout << r;
			else
			cout << "operand is character";

		cout << "\n\n Do you want to do another expression('y'or'n')? ";
		cin >> c;
	}
}

////////////////////////////////////////////////////////////////////////////////

int operand(char x)     // x를 받아서, 
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};
	for(int i=0; i<8; i++)if(op[i]==x)return 0;      // x가 연산자일 경우 0을 리턴.
	return 1;
}

/////////////////////////////////////////////////////////////////////////////////

int Isp(char x)         // x를 받아서, 
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};
	int sp[8] =   {0 , 19, 12, 12, 13, 13, 13,0};
	int i;
	for(i=0; i<8; i++)if(op[i]==x)return sp[i];   // op[i]가 x와 같으면 sp[i]를 리턴.
	cout << "* Isp error *\n";
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////

int Icp(char x)         // x를 받아서, 
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};
	int cp[8] = {  20, 19, 12, 12, 13, 13, 13,0};
	int i;
	for(i=0; i<8; i++)if(op[i]==x)return cp[i];   // op[i]가 x와 같으면 cp[i]를 리턴.
	cout << "* Icp error *\n";
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////

void postfix(char *token, char *post)   // token - 원 식 배열, post - 결과 배열
{
	char x;
	int ipost = 0;
	char_top = -1;
	char_stack_add('\0');                    // char_stack에 \0 저장

	for(int i=0; token[i]!='\0'; i++)        // 원시식 배열에서 하나씩 값을 꺼내온다.
	{
		x=token[i];                          // x에 배열의 값 저장.

		if(operand(x))post[ipost++] = x;     // x가 연산자가 아닐경우 post[]에 저장.
		else if(x==')'){                     // x가 연산자일 경우, ')'라면
			while(char_stack[char_top]!='(')post[ipost++] = char_stack_delete(); 
			   // char_stack의 값이 '('이 아닐 동안 post[]에 char_stack[]의 값을 저장.
			char_stack_delete();             //
			}
		else{                                // x가 연산자도 아니며 괄호도 아닐경우, 
			while(Isp(char_stack[char_top])>=Icp(x))post[ipost++] = char_stack_delete();
          //Isp(char_stack[top])의 값이 Icp(x)보다 크거나 같을동안 post[]에 char_stack값 저장.
		  //    
			char_stack_add(x);
			}
	}
	while((x=char_stack_delete()) != '\0')            // x의 값이 존재할동안(스택이 차있을 동안)
		post[ipost++] = x;            // post[]에 x값(char_stack[]의 값)저장.
	post[ipost] = '\0';
	return;
}

///////////////////////////////////////////////////////////////////////////////////////

int eval(char *token)      // postfix된 식을 받아서
{
	char x;
	int op1, op2;
	int_top = -1;

	for(int i=0; token[i]!='\0'; i++)   // token에 값이 존재할 동안
	{
		x=token[i];                     // token의 값을 x에 저장.
		if(operand(x)){                 // x가 연산자가 아니고
			if(x<'0'|| x>'9'){          // x가 0보다 작고 9보다 크다면 
				int_top = 1;            // int_top은 1.
				return 0;
			}
			int_stack_add(atoi(&x));    // int_stack에 x(문자열)를 int형으로 변환하여 저장.
		}
		else{                           // x가 연산자가 아니라면
			op2=int_stack_delete();     // op2는 int_stack[top]을 저장.
			op1=int_stack_delete();     // op1는 int_stack[top-]을 저장.
			switch(x){                  // x가 연산자일때 연산 해준다
				case '+': int_stack_add(op1+op2);
							break;
				case '-': int_stack_add(op1-op2);
							break;
				case '*': int_stack_add(op1*op2);
							break;
				case '/': int_stack_add(op1/op2);
							break;
				case '%': int_stack_add(op1%op2);
			}                           // 연산한 값은 int_stack에 저장.
		}
	}
	return int_stack_delete();          // for문이 종료되면 int_stack[top]의 값을 리턴.
}
