#include <iostream.h>
#include "aegis_imp.h"

class CDestroyer:public CAegisImp
{
public:
	virtual void Senser_Search();
	virtual void Weapon_Fire();
	
	CDestroyer();

private:
	int iEnemy_Sky;
	int iEnemy_Surface;
};

CDestroyer::CDestroyer()
{
	iEnemy_Sky = 0;
	iEnemy_Surface = 0;
}

void CDestroyer::Senser_Search()
{
	int i, j;
	cout << "������ Ŭ���� �۵� ��." <<endl;
	cout << "�������� ������ ���� Ÿ�� �� �Է� : ��� ��ǥ, ���� ��ǥ" << endl;
	cin << i << j;
	
	iEnemy_Sky = i;
	iEnemy_Surface = j;
}

void CDestroyer::Weapon_System()
{
	cout << "������ Ŭ���������� �Ϲ������� ��� ����� ���ݹۿ� ����." << endl;
	cout << "��� ��ǥ ���� : " << iEnemy_Sky << " ����� ��ǥ ���� : " << iEnemy_Surace;
}