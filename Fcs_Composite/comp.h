#include <list>
#include <string>
using namespace std;

////////////////////////////////////////////////////////////////
class CEquipment{
public:
	virtual ~CEquipment(); // 소멸자 : 반드시 컴포짓 내부를 해제해 줄것.
	const char* Name(){return _name;}

	virtual unsigned int NetPrice();
	
	// 장비의 추가 삭제
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
	
	virtual void Add(CEquipment*);
	virtual void Remove(CEquipment*);

	//CCompositeEquipment();
	CCompositeEquipment(const char*, int);
	
private:
	list<CEquipment*> _equipment; // 장비들이 저장된다.
	const char* _name;
	unsigned int mPrice;
};

///////////////////////////////////////////////////////////////
// FCS는 Senser, FireCtrl, DataLnk를 포함한다.

///////////////////////////////////////////////////////////////////
// Senser는 Rader와 Irtv를 포함한다.

///////////////////////////////////////////////////////////////////
// Firectrl는 Gunpc와 Mslpc를 포함한다.

////////////////////////////////////////////////////////////
// Datalnk는 FCS의 모듈로 들어간다.