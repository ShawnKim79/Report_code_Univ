// Singleton Patton : 전체 프로그램에서 하나의 객체만이 존재하여야 할 때.
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
	cout << "항법장치를 가동합니다" << endl;
}

int CNavigation::ViewPath()
{
	int i = 1;
	while(i > 0)
	{
		if(0 > GetAsyncKeyState(VK_UP))
		{
			cout << "북쪽으로 가고 있습니다" << endl;
		}
		else if(0 > GetAsyncKeyState(VK_DOWN))
		{
			cout << "남쪽으로 가고 있습니다" << endl;
		}
		else if(0 > GetAsyncKeyState(VK_LEFT))
		{
			cout << "서쪽으로 가고 있습니다" << endl;
		}
		else if(0 > GetAsyncKeyState(VK_RIGHT))
		{
			cout << "동쪽으로 가고 있습니다" << endl;
		}
		else if(0 > GetAsyncKeyState(VK_SPACE))
		{
			i = 0;
		}
		Sleep(10);
	}
	return 0;
}