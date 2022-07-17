#include <list>

using namespace std;

////////////////////////////////////////////////////////////////
class CEquipment{
public:
	virtual ~CEquipment(); // �Ҹ��� : �ݵ�� ������ ���θ� ������ �ٰ�.
	const char* Name(){return _name;}

	// ����� �⺻ �Ӽ� ��ȯ
	virtual unsigned int NetPrice();

	// ����� �߰� ����
	virtual void Add(CEquipment*);
	virtual void Remove(CEquipment*);

	CEquipment();
	CEquipment(const char*, int);
private:
	const char* _name;
	unsigned int mPrice;
};

////////////////////////////////////////////////////////////////
class CCompositeEquipment:public CEquipment
{
public:
	virtual ~CCompositeEquipment();
	const char* Name(){return _name;}
	
	virtual unsigned int NetPrice();

	//virtual void SetPrice(int); // ������ ���� �¾�
	//virtual unsigned int GetPrice(); // ������ ���� ����

	virtual void Add(CEquipment*);
	virtual void Remove(CEquipment*);
	
	CCompositeEquipment();
	CCompositeEquipment(const char*);
private:
	list<CEquipment*> _equipment; // ������ ����ȴ�.
	const char* _name;
};

///////////////////////////////////////////////////////////////
// FCS�� Senser, FireCtrl, DataLnk�� �����Ѵ�.

///////////////////////////////////////////////////////////////////
// Senser�� Rader�� Irtv�� �����Ѵ�.

///////////////////////////////////////////////////////////////////
// Firectrl�� Gunpc�� Mslpc�� �����Ѵ�.

////////////////////////////////////////////////////////////
// Datalnk�� FCS�� ���� ����.
