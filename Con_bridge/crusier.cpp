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
	cout << "순양함 클래스 작동 중." <<endl;
	cout << "순양함의 센서가 잡은 타겟 수 입력 : 대공 목표, 수상 목표, 수중 목표" << endl;
	cin << i << j << k;
	
	iEnemy_Sky = i;
	iEnemy_Surface = j;
	iEnemy_Sub = k;
}

void CCrusier::Weapon_System()
{
	cout << "순양함 클래스에서는 일반적으로 대공 대수상 대수중 공격가능." << endl;
	cout << "대공 목표 갯수 : " << iEnemy_Sky << " 대수상 목표 갯수 : " << iEnemy_Surace << " 대수중 목표 갯수 : " << 
		iEnemy_Sub; 
}