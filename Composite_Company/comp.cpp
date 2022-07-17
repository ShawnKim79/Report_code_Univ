#include <iostream>
#include "comp.h"

//using namespace std;

//////////////////////////////////////////////////////////
// CEmployee�� �Լ� ���� : �̰� ��¥�� �⺻ ���...�̰� ���ο� ���� �߰��� ���� ����.
/*
	virtual ~Employee(); // �Ҹ��� : �ݵ�� ������ ���θ� ������ �ٰ�.
	const char* Name(){return _name;}

	// ����� �⺻ �Ӽ� ��ȯ
	virtual unsigned int NetPrice();
	virtual unsigned int DiscountPrice();

	// ����� �߰� ����
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
	// ��� ����Ʈ�� �߰��� �̰� ������ ����
}

void CEmployee::Remove(CEmployee*)
{
	// ��� ����Ʈ���� ������ ���� ���� ����
}

/*
Iterator<CEmployee*> CEmployee::CreateIterator()
{
	// �̰� �𸣰ڴ�...�Ƹ� ���� ���� ������
}
*/

////////////////////////////////////////////////////////////////
// class CManagerEmployee �Լ�����
/*
	virtual ~CompositeEmployee(); 
	// ����Ʈ Ŭ���� �� ��� �Ѵ�.(�ȱ׷��� �޸� KIN~)

	const char* Name(){return _name;}
	virtual unsigned int NetPrice();
	// �Ҽӵ� ��ǰ �Ѱ���
	virtual unsigned int DiscountPrice();

  	virtual void Add(CEmployee*);
	virtual void Remove(CEmployee*);
	virtual Iterator<CEmployee*> *CreateIterator();

	List<CEmployee*> _Employee; // ������ ����ȴ�.

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
	// iterator�� �̿��� ����...
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
	// temp�� �˻��ؼ� ����...�ΰ�.
	//iterator It = _Employee::iterator;
}


CManagerEmployee::~CManagerEmployee()
{
}