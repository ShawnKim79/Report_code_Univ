#include "stdafx.h"
#include "comp.h"
//////////////////////////////////////////////////////////
// CEquipment�� �Լ� ���� : �̰� ��¥�� �⺻ ���...�̰� ���ο� ���� �߰��� ���� ����.
/*
	virtual ~Equipment(); // �Ҹ��� : �ݵ�� ������ ���θ� ������ �ٰ�.
	const char* Name(){return _name;}

	// ����� �⺻ �Ӽ� ��ȯ
	virtual unsigned int NetPrice();

	// ����� �߰� ����
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
	// ��� ����Ʈ�� �߰��� �̰� ������ ����
}

void CEquipment::Remove(CEquipment*)
{
	// ��� ����Ʈ���� ������ ���� ���� ����
}


////////////////////////////////////////////////////////////////
// class CCompositeEquipment �Լ�����
/*
	virtual ~CompositeEquipment(); 
	// ����Ʈ Ŭ���� �� ��� �Ѵ�.(�ȱ׷��� �޸� KIN~)

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
	// iterator�� �̿��� ����...
	
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

