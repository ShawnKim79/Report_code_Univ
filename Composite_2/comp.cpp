#include "comp.h"

//using namespace std;

//////////////////////////////////////////////////////////
// CEquipment�� �Լ� ���� : �̰� ��¥�� �⺻ ���...�̰� ���ο� ���� �߰��� ���� ����.
/*
	virtual ~Equipment(); // �Ҹ��� : �ݵ�� ������ ���θ� ������ �ٰ�.
	const char* Name(){return _name;}

	// ����� �⺻ �Ӽ� ��ȯ
	virtual unsigned int NetPrice();
	virtual unsigned int DiscountPrice();

	// ����� �߰� ����
	virtual void Add(Equipment*);
	virtual void Remove(Equipment*);

	virtual Iterator<CEquipment*>CreateIterator();
	Equipment(const char*);
*/

CEquipment::CEquipment()
{

}

CEquipment::CEquipment(const char* cTemp, int nTemp)
{
	_name = cTemp;
	mPrice = nTemp;
}

unsigned int CEquipment::NetPrice()
{
	return mPrice;
}

CEquipment::~CEquipment()
{
}

void CEquipment::Add(CEquipment*)
{
	// ��� ����Ʈ�� �߰��� �̰� ������ ����
}

void CEquipment::Remove(CEquipment*)
{
	// ��� ����Ʈ���� ������ ���� ���� ����
}

/*
Iterator<CEquipment*> CEquipment::CreateIterator()
{
	// �̰� �𸣰ڴ�...�Ƹ� ���� ���� ������
}
*/

////////////////////////////////////////////////////////////////
// class CCompositeEquipment �Լ�����
/*
	virtual ~CompositeEquipment(); 
	// ����Ʈ Ŭ���� �� ��� �Ѵ�.(�ȱ׷��� �޸� KIN~)

	const char* Name(){return _name;}
	virtual unsigned int NetPrice();
	// �Ҽӵ� ��ǰ �Ѱ���
	virtual unsigned int DiscountPrice();

  	virtual void Add(CEquipment*);
	virtual void Remove(CEquipment*);
	virtual Iterator<CEquipment*> *CreateIterator();

	List<CEquipment*> _equipment; // ������ ����ȴ�.

*/

CCompositeEquipment::CCompositeEquipment()
{

}

CCompositeEquipment::CCompositeEquipment(const char *cTemp)
{
	_name = cTemp;
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
	
	return ntemp;
}

void CCompositeEquipment::Add(CEquipment* temp)
{
	_equipment.insert(_equipment.begin(), temp);
	//SetPrice(temp->mPrice);		
}
/*
void CCompositeEquipment::SetPrice(int nTemp)
{
	//mPrice += nTemp;
}

void CCompositeEquipment::GetPrice()
{
	//return mPrice;
}
*/
void CCompositeEquipment::Remove(CEquipment *temp)
{
	// temp�� �˻��ؼ� ����...�ΰ�.
	//iterator It = _equipment::iterator;
}


CCompositeEquipment::~CCompositeEquipment()
{
}