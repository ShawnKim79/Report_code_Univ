// postfix 프로그램.........

#include <iostream.h>

// 문자를 저장하는 스택과 함수 정의 //////////////////////////////

#define char_stack_size 30         // 30칸의 스택.
char char_stack[char_stack_size];  // 스택 선언.
int char_top = -1;

///////////////////////////////////////////////////////////////////

int char_Isfull()                               // 스택이 가득 찼을 경우.
{
	if(char_top>=char_stack_size-1)return 1;    // 스택의 top이 스택 사이즈 보다 같거나 클때 스택은 가득 참
	else return 0;
}

///////////////////////////////////////////////////////////////////

int char_Isempty()
{
	if(char_top<=-1)return 1;  // 스택의 top이 -1보다 같거나 작을때. 스택은 비어있다.
	else return 0;
}

/////////////////////////////////////////////////////////////////////

void char_stack_full()
{
	cout << endl << " ** err : char_stack full **" << endl;  // 스택이 Full일때 메세지 출력
}

/////////////////////////////////////////////////////////////////////

void char_stack_add(char item)              // 스택에 값을 추가하는 코드
{
	if(char_top>=char_stack_size-1){        // char_top이 char_stack_size-1보다 크면
		char_stack_full();                  // 스택은 가득 참.
		return;                             // 바로 함수 종료
	}
	char_stack[++char_top] = item;          // 그렇지 않을 경우, top에 1을 더한곳에 item 저장.
}

/////////////////////////////////////////////////////////////////////

char char_stack_empty()                     // 스택이 비어있을 경우
{
	cout << endl << " ** err : char_stack empty **" << endl;   // 메세지 출력후
	char_stack[0] = '0';                    // 스택의 0번 방을 초기화 
	return char_stack[0];
}

//////////////////////////////////////////////////////////////////////

char char_stack_delete()                    // 스택에 값을 하나 제거.
{
	char item;
	if(char_top <= -1)                      // top의 값이 -1 보다 작거나 같으면 비어있는 상태.
		return char_stack_empty();
	item = char_stack[char_top--];          // 그렇지 않으면 top의 값을 item에 저장하고 top의 값에 -1
	return item;
}

/// 문자를 저장하는 스택 정의 끝 ///////////////////////////////////////

// 함수 Prototype ///////////////////////////////////////////////////////

int operand(char x);
int Isp(char x);
int Icp(char x);
void postfix(char *token, char *post);

////////////////////////////////////////////////////////////////////////////

void main()
{
    char exp[50];      // 연산식을 저장할 배열.
	char post[50];     // 결과를 저장할 배열.
	char c = 'y';
    while(c=='y')
	{
		cout << endl << "* enter infix expression : ";
		cin >> exp; 
		postfix(exp, post);   // 배열을 postfix로 보낸다(포인터 주소)
		cout << "  * postfix notation : " << post << endl;
		cout << "\n Do you want to do another expression('y'or'n')? ";
		cin >> c;
	}
}

////////////////////////////////////////////////////////////////////////////////

int operand(char x)                                   // x를 받아 비교.
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};  // 배열 초기화.
	for(int i=0; i<8; i++)if(op[i]==x)return 0;       // 배열의 값과 x의 값이 같으면 0 리턴.
	return 1;
}

//////////////////////////////////////////////////////////////////////////////

int Isp(char x)                                         // x 받아 비교.
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};    //  배열 초기화 
	int sp[8] =  { 0, 19, 12, 12, 13, 13, 13,  0};
	int i; 
	for(i=0; i<8; i++)if(op[i]==x)return sp[i];         // op[i]의 값이 x와 같으면 같은 부분의 방과 같은 방 번호의
														// sp[i]배열의 값 리턴.
	cout << "* Isp error *\n";
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

int Icp(char x)                                         // x 받아 비교.
{
	char op[8] = {'(',')','+','-','*','/','%','\0'};    // 배열 초기화.
	int cp[8] =  {20, 19, 12, 12, 13, 13, 13,  0};
	int i;
	for(i=0; i<8; i++)if(op[i]==x)return cp[i];         // op[i]의 값이 x와 같으면 cp[i]리턴.

	cout << "* Icp error *\n";
	return 0;
}

////////////////////////////////////////////////////////////////////////////////

void postfix(char *token, char *post)   // 원식배열 exp -> token, 결과배열 post -> post
{
	char x;
	int ipost = 0;
	char_top = -1;
	char_stack_add('\0');                  // char_stack의 0번에 '\0' 저장 

	for(int i=0; token[i]!='\0'; i++)      // token[i]이 '\0'이 될때까지
	{  
		x=token[i];                        // x에 token[i] 저장.
		if(operand(x)) post[ipost++] = x;  // x가 1일 경우(x가 연산자가 아닐 경우) post에 저장

		else if(x==')'){                   // x가 ) 일 경우
			while(char_stack[char_top]!='(')post[ipost++] = char_stack_delete(); 
			                               // char_stack[top]이 ( 가 아닐동안 post[]에 char_stack의 값 저장.
			char_stack_delete();           // char_stack[top]이 ( 라면 ( 까지 post[]에 저장.
			}

		else{                              // x가 연산자도, ()도 아닐경우
			while( Isp(char_stack[char_top])>=Icp(x) ) post[ipost++] = char_stack_delete();
                // Isp(char_stack의 최상위 값이 Icp(x)보다 크거나 같을 동안
                // post[]에 char_stack의 값 저장.
			char_stack_add(x);  // Isp(char_stack의 최상위 값)이 Icp(x)보다 작다면 char_stack에 x 저장.
			}
	}

	while( (x=char_stack_delete()) != '\0' ) // char_stack에서 빼낸 값이 '\0'이 아닐동안
		post[ipost++] = x;                   // post[]에 x를 집어 넣는다.
	post[ipost] = '\0';                      // 루프가 끝난 후 배열의 마지막은 '\0'
	return;
}

