#include <iostream.h>
#include "aegis_imp.h"

class CCrusier:public CAegisImp
{
public:
	virtual void Senser_Search();
	virtual void Weapon_System();

	CCrusier();
private:
	int iEnemy_Sky;
	int iEnemy_Surface;
	int iEnemy_Sub;
};

CCrusier::CDestroyer()
{
	iEnemy_Sky = 0;
	iEnemy_Surface = 0;
	iEnemy_Sub = 0;
}

void CCrusier::Senser_Search()
{
	int i, j, k;
	cout << "������ Ŭ���� �۵� ��." <<endl;
	cout << "�������� ������ ���� Ÿ�� �� �Է� : ��� ��ǥ, ���� ��ǥ, ���� ��ǥ" << endl;
	cin << i << j << k;
	
	iEnemy_Sky = i;
	iEnemy_Surface = j;
	iEnemy_Sub = k;
}

void CCrusier::Weapon_System()
{
	cout << "������ Ŭ���������� �Ϲ������� ��� ����� ����� ���ݰ���." << endl;
	cout << "��� ��ǥ ���� : " << iEnemy_Sky << " ����� ��ǥ ���� : " << iEnemy_Surace << " ����� ��ǥ ���� : " << 
		iEnemy_Sub; 
}