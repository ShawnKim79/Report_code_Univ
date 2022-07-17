

class CAegisImp
{
public:
	virtual void Senser_Search() = 0;
	virtual void Weapon_System() = 0;
	// �� �Ժ��� ���� �ٸ� ���� ����.
	// ���� ������ ���� �ٸ��� �����ؾ� ��.
};
/////////////////////////////////////////////////////////////////////////////////////////////
class CAegis
{
public:
	virtual void Weapon_Fire();

//	virtual void Senser_Search(); // Imp������ ���� ������ ��.
	// �� Ŭ������ �Ļ� Ŭ������ ���� ������ ��.
//	virtual void Weapon_System();	
	// �߻�Ǵ� ����� Imp��ü���� �Ļ��Ǵ� ��ü Ÿ�Կ� �¿�ȴ�.

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
	cout << "������ Ŭ���� �۵� ��." <<endl;
	cout << "�������� ������ ���� Ÿ�� �� �Է� : ��� ��ǥ, ���� ��ǥ, ���� ��ǥ" << endl;
	cin >> i >> j >> k;
	
	iEnemy_Sky = i;
	iEnemy_Surface = j;
	iEnemy_Sub = k;
}

void CCrusier::Weapon_System()
{
	cout << "������ Ŭ���������� �Ϲ������� ��� ����� ����� ���ݰ���." << endl;
	cout << "��� ��ǥ ���� : " << iEnemy_Sky << " ����� ��ǥ ���� : " << iEnemy_Surface << " ����� ��ǥ ���� : " << 
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
	cout << "������ Ŭ���� �۵� ��." <<endl;
	cout << "�������� ������ ���� Ÿ�� �� �Է� : ��� ��ǥ, ���� ��ǥ" << endl;
	cin >> i >> j;
	
	iEnemy_Sky = i;
	iEnemy_Surface = j;
}

void CDestroyer::Weapon_System()
{
	cout << "������ Ŭ���������� �Ϲ������� ��� ����� ���ݹۿ� ����." << endl;
	cout << "��� ��ǥ ���� : " << iEnemy_Sky << " ����� ��ǥ ���� : " << iEnemy_Surface;
}

CAegisImp* CAegis::GetAegisImp()
{
	int i;
	cout << " �ý��� ���� : 1. ������, 2. ������ : ";
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

