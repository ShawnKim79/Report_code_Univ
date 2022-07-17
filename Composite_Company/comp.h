#include <list>

using namespace std;

////////////////////////////////////////////////////////////////
class CEmployee{
public:
	virtual ~CEmployee(); // 소멸자 : 반드시 컴포짓 내부를 해제해 줄것.
	const char* Name(){return _name;}

	virtual unsigned int NetSalary();

	// 장비의 추가 삭제
	virtual void Add(CEmployee*);
	virtual void Remove(CEmployee*);

	CEmployee();
	CEmployee(const char*, int);
private:
	const char* _name;
	unsigned int mSalary;
};

////////////////////////////////////////////////////////////////
class CManagerEmployee:public CEmployee
{
public:
	virtual ~CManagerEmployee();
	const char* Name(){return _name;}
	
	virtual unsigned int NetSalary();
	virtual unsigned int MySalary();

	//virtual void SetPrice(int); // 컴포짓 가격 셋업
	//virtual unsigned int GetPrice(); // 컴포짓 가격 인출

	virtual void Add(CEmployee*);
	virtual void Remove(CEmployee*);
	
	CManagerEmployee();
	CManagerEmployee(const char*, int);
	CManagerEmployee(const char*);
private:
	list<CEmployee*> _Employee; // 장비들이 저장된다.
	const char* _name;
	unsigned int mMngSalary;
};

///////////////////////////////////////////////////////////////
// FCS는 Senser, FireCtrl, DataLnk를 포함한다.

///////////////////////////////////////////////////////////////////
// Senser는 Rader와 Irtv를 포함한다.

///////////////////////////////////////////////////////////////////
// Firectrl는 Gunpc와 Mslpc를 포함한다.

////////////////////////////////////////////////////////////
// Datalnk는 FCS의 모듈로 들어간다.
