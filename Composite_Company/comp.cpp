#include <iostream>
#include "comp.h"

//using namespace std;

//////////////////////////////////////////////////////////
// CEmployee의 함수 정의 : 이건 어짜피 기본 장비...이거 내부에 뭔가 추가될 것은 없다.
/*
	virtual ~Employee(); // 소멸자 : 반드시 컴포짓 내부를 해제해 줄것.
	const char* Name(){return _name;}

	// 장비의 기본 속성 반환
	virtual unsigned int NetPrice();
	virtual unsigned int DiscountPrice();

	// 장비의 추가 삭제
	virtual void Add(Employee*);
	virtual void Remove(Employee*);

	virtual Iterator<CEmployee*>CreateIterator();
	Employee(const char*);
*/

CEmployee::CEmployee()
{

}

CEmployee::CEmployee(const char* cTemp, int nTemp)
{
	_name = cTemp;
	mSalary = nTemp;
}

unsigned int CEmployee::NetSalary()
{
	return mSalary;
}

CEmployee::~CEmployee()
{
}

void CEmployee::Add(CEmployee*)
{
	// 장비 리스트에 추가니 이것 쓸일이 없다
}

void CEmployee::Remove(CEmployee*)
{
	// 장비 리스트에서 삭제니 역시 쓸일 없다
}

/*
Iterator<CEmployee*> CEmployee::CreateIterator()
{
	// 이건 모르겠다...아마 쓸일 없지 않을까
}
*/

////////////////////////////////////////////////////////////////
// class CManagerEmployee 함수정의
/*
	virtual ~CompositeEmployee(); 
	// 리스트 클리어 해 줘야 한다.(안그러면 메모리 KIN~)

	const char* Name(){return _name;}
	virtual unsigned int NetPrice();
	// 소속된 부품 총가격
	virtual unsigned int DiscountPrice();

  	virtual void Add(CEmployee*);
	virtual void Remove(CEmployee*);
	virtual Iterator<CEmployee*> *CreateIterator();

	List<CEmployee*> _Employee; // 장비들이 저장된다.

*/

CManagerEmployee::CManagerEmployee()
{

}

CManagerEmployee::CManagerEmployee(const char *cTemp)
{
	_name = cTemp;
	mMngSalary = 0;
	
}

CManagerEmployee::CManagerEmployee(const char *cTemp, int nTemp)
{
	_name = cTemp;
	mMngSalary = nTemp;
}

unsigned int CManagerEmployee::MySalary()
{
	return mMngSalary;
}

unsigned int CManagerEmployee::NetSalary()
{
	// iterator를 이용해 연산...
	int counter;
	unsigned int temp;

	temp = MySalary();

	list<CEmployee*>::iterator i = _Employee.begin();
	unsigned int ntemp = 0;

	for(; i != _Employee.end() ; i++)
	{
		counter++;

		CEmployee* eTemp = *i;
		//cout << eTemp->Name() << eTemp->NetSalary() << endl;
	}
	
	return ntemp+(counter*100) + temp;
}

void CManagerEmployee::Add(CEmployee* temp)
{
	_Employee.insert(_Employee.begin(), temp);
	//SetPrice(temp->mPrice);		
}
/*
void CManagerEmployee::SetPrice(int nTemp)
{
	//mPrice += nTemp;
}

void CManagerEmployee::GetPrice()
{
	//return mPrice;
}
*/
void CManagerEmployee::Remove(CEmployee *temp)
{
	// temp로 검색해서 삭제...인가.
	//iterator It = _Employee::iterator;
}


CManagerEmployee::~CManagerEmployee()
{
}