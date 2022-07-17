#include "stdafx.h"
#include "comp.h"
//////////////////////////////////////////////////////////
// CEquipment의 함수 정의 : 이건 어짜피 기본 장비...이거 내부에 뭔가 추가될 것은 없다.
/*
	virtual ~Equipment(); // 소멸자 : 반드시 컴포짓 내부를 해제해 줄것.
	const char* Name(){return _name;}

	// 장비의 기본 속성 반환
	virtual unsigned int NetPrice();

	// 장비의 추가 삭제
	virtual void Add(Equipment*);
	virtual void Remove(Equipment*);

	Equipment(const char*);
*/

CEquipment::CEquipment(const char* cTemp, int nTemp)
{
	_name = cTemp;
	mPrice = nTemp;
}
/*
CEquipment::CEquipment()
{
	_name = "NoName";
	mPrice = 0;
}
*/
CEquipment::~CEquipment()
{
}

unsigned int CEquipment::NetPrice()
{
	return mPrice;
}

void CEquipment::Add(CEquipment*)
{
	// 장비 리스트에 추가니 이것 쓸일이 없다
}

void CEquipment::Remove(CEquipment*)
{
	// 장비 리스트에서 삭제니 역시 쓸일 없다
}


////////////////////////////////////////////////////////////////
// class CCompositeEquipment 함수정의
/*
	virtual ~CompositeEquipment(); 
	// 리스트 클리어 해 줘야 한다.(안그러면 메모리 KIN~)

	const char* Name(){return _name;}
	virtual unsigned int NetPrice();

  	virtual void Add(CEquipment*);
	virtual void Remove(CEquipment*);
*/


CCompositeEquipment::CCompositeEquipment(const char *cTemp, int nTemp)
{
	_name = cTemp;
	mPrice = nTemp;
}

CCompositeEquipment::~CCompositeEquipment()
{
}

unsigned int CCompositeEquipment::NetPrice()
{
	// iterator를 이용해 연산...
	
	list<CEquipment*>::iterator i = _equipment.begin();
	unsigned int ntemp = 0;

	for(; i != _equipment.end() ; i++)
	{
		CEquipment* temp = (*i);
		ntemp += temp->NetPrice();
	}
//	delete i;
	//delete temp;

	return ntemp;
}


void CCompositeEquipment::Add(CEquipment* temp)
{
	_equipment.insert(_equipment.begin(), temp);
}

void CCompositeEquipment::Remove(CEquipment *temp)
{
	list<CEquipment*>::iterator i = _equipment.begin();
	for(; i != _equipment.end() ; i++)
	{
		_equipment.erase(i);
	}
}

