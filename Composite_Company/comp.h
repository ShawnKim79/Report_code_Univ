#include <list>

using namespace std;

////////////////////////////////////////////////////////////////
class CEmployee{
public:
	virtual ~CEmployee(); // �Ҹ��� : �ݵ�� ������ ���θ� ������ �ٰ�.
	const char* Name(){return _name;}

	virtual unsigned int NetSalary();

	// ����� �߰� ����
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

	//virtual void SetPrice(int); // ������ ���� �¾�
	//virtual unsigned int GetPrice(); // ������ ���� ����

	virtual void Add(CEmployee*);
	virtual void Remove(CEmployee*);
	
	CManagerEmployee();
	CManagerEmployee(const char*, int);
	CManagerEmployee(const char*);
private:
	list<CEmployee*> _Employee; // ������ ����ȴ�.
	const char* _name;
	unsigned int mMngSalary;
};

///////////////////////////////////////////////////////////////
// FCS�� Senser, FireCtrl, DataLnk�� �����Ѵ�.

///////////////////////////////////////////////////////////////////
// Senser�� Rader�� Irtv�� �����Ѵ�.

///////////////////////////////////////////////////////////////////
// Firectrl�� Gunpc�� Mslpc�� �����Ѵ�.

////////////////////////////////////////////////////////////
// Datalnk�� FCS�� ���� ����.
