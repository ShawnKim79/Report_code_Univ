// Singleton Patton : ��ü ���α׷����� �ϳ��� ��ü���� �����Ͽ��� �� ��.
#include <windows.h>
#include <time.h>

class CNavigation
{
public:
	static CNavigation* GetInstance();
	void SetPoint();
	int ViewPath();

	~CNavigation();

protected:
	CNavigation();

private:
	static CNavigation* _instance;
};

CNavigation* CNavigation::_instance = NULL;

CNavigation::CNavigation()
{

}

CNavigation::~CNavigation()
{
	_instance = NULL;
}

CNavigation* CNavigation::GetInstance()
{
	if(_instance == 0)
	{
		_instance = new CNavigation;
	}

	return _instance;
}

void CNavigation::SetPoint()
{
	cout << "�׹���ġ�� �����մϴ�" << endl;
}

int CNavigation::ViewPath()
{
	int i = 1;
	while(i > 0)
	{
		if(0 > GetAsyncKeyState(VK_UP))
		{
			cout << "�������� ���� �ֽ��ϴ�" << endl;
		}
		else if(0 > GetAsyncKeyState(VK_DOWN))
		{
			cout << "�������� ���� �ֽ��ϴ�" << endl;
		}
		else if(0 > GetAsyncKeyState(VK_LEFT))
		{
			cout << "�������� ���� �ֽ��ϴ�" << endl;
		}
		else if(0 > GetAsyncKeyState(VK_RIGHT))
		{
			cout << "�������� ���� �ֽ��ϴ�" << endl;
		}
		else if(0 > GetAsyncKeyState(VK_SPACE))
		{
			i = 0;
		}
		Sleep(10);
	}
	return 0;
}