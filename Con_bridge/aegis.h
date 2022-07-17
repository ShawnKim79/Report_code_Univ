

class CAegisImp
{
public:
	virtual void Senser_Search() = 0;
	virtual void Weapon_System() = 0;
	// 각 함별로 서로 다른 센서 보유.
	// 함의 기종에 따라 다르게 구현해야 함.
};
/////////////////////////////////////////////////////////////////////////////////////////////
class CAegis
{
public:
	virtual void Weapon_Fire();

//	virtual void Senser_Search(); // Imp쪽으로 가서 구현될 것.
	// 이 클래스의 파생 클래스에 가서 구현될 것.
//	virtual void Weapon_System();	
	// 발사되는 무기는 Imp개체에서 파생되는 개체 타입에 좌우된다.

protected:
	CAegisImp* GetAegisImp();

private:
	CAegisImp* _imp;
};

void CAegis::Weapon_Fire()
{

}

class CCrusier:public CAegisImp
{
public:
	virtual void Senser_Search();
	virtual void Weapon_System();

	CCrusier();

	int iEnemy_Sky;
	int iEnemy_Surface;
	int iEnemy_Sub;
};

CCrusier::CCrusier()
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
	cin >> i >> j >> k;
	
	iEnemy_Sky = i;
	iEnemy_Surface = j;
	iEnemy_Sub = k;
}

void CCrusier::Weapon_System()
{
	cout << "순양함 클래스에서는 일반적으로 대공 대수상 대수중 공격가능." << endl;
	cout << "대공 목표 갯수 : " << iEnemy_Sky << " 대수상 목표 갯수 : " << iEnemy_Surface << " 대수중 목표 갯수 : " << 
		iEnemy_Sub; 
}
////////////////////////////////////////////////////////////////////////////////////////
class CDestroyer:public CAegisImp
{
public:
	virtual void Senser_Search();
	virtual void Weapon_System();
	
	CDestroyer();


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
	cin >> i >> j;
	
	iEnemy_Sky = i;
	iEnemy_Surface = j;
}

void CDestroyer::Weapon_System()
{
	cout << "구축함 클래스에서는 일반적으로 대공 대수상 공격밖에 못함." << endl;
	cout << "대공 목표 갯수 : " << iEnemy_Sky << " 대수상 목표 갯수 : " << iEnemy_Surface;
}

CAegisImp* CAegis::GetAegisImp()
{
	int i;
	cout << " 시스템 선택 : 1. 구축함, 2. 순양함 : ";
	cin >> i;
	if (i == 1)
	{
		CDestroyer temp;
		return (CAegisImp*)&temp;
	}
	else if(i == 2)
	{
		CCrusier temp;
		return (CAegisImp*)&temp;
	}
}

class CAegisWeapon:public CAegis
{
public:
	virtual void Weapon_Fire();
};

void CAegisWeapon::Weapon_Fire()
{
	CAegisImp* imp = GetAegisImp();

	imp->Senser_Search();
	imp->Weapon_System();
	
}

