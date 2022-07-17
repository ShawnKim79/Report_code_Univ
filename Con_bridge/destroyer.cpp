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
	cout << "구축함 클래스 작동 중." <<endl;
	cout << "구축함의 센서가 잡은 타겟 수 입력 : 대공 목표, 수상 목표" << endl;
	cin << i << j;
	
	iEnemy_Sky = i;
	iEnemy_Surface = j;
}

void CDestroyer::Weapon_System()
{
	cout << "구축함 클래스에서는 일반적으로 대공 대수상 공격밖에 못함." << endl;
	cout << "대공 목표 갯수 : " << iEnemy_Sky << " 대수상 목표 갯수 : " << iEnemy_Surace;
}