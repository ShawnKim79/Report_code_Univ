#include <iostream.h>

// 추상 클래스. 인터페이스만 제공해 준다.
class Compositor
{
public:
	virtual void Shot(int swingPower, int swingAngle);
protected:
	Compositor();
};

Compositor::Compositor()
{
}

void Compositor::Shot(int sptemp, int satemp)
{
}

////////////////////////////////////////////////
//
class LowShot:public Compositor
{
public:
	LowShot();
	virtual void Shot(int swingPower, int swingAngle);
};

LowShot::LowShot()
{
}

void LowShot::Shot(int swingPower, int swingAngle)
{
	int return_value;
	return_value = swingAngle + swingPower;
	cout << return_value << " : " ;
	cout << "Low shot" << endl;
	
}

////////////////////////////////////////////////
//
class MidShot:public Compositor
{
public:
	MidShot();
	virtual void Shot(int swingPower, int swingAngle);
};

MidShot::MidShot()
{
}

void MidShot::Shot(int swingPower, int swingAngle)
{
	int return_value;
	return_value = (int)(swingPower*2) + swingAngle;
	cout << return_value << " : " ;
	cout << "Middle shot" << endl;
}

////////////////////////////////////////////////
//
class HighShot:public Compositor
{
public:
	HighShot(int found);
	virtual void Shot(int swingPower, int swingAngle);

	int batfound;
};

HighShot::HighShot(int found)
{
	batfound = found;
}

void HighShot::Shot(int swingPower, int swingAngle)
{
	int return_value;
	return_value = (int)(swingPower*batfound) + swingAngle;
	cout << return_value << " : " ;
	cout << "High shot" << endl;
}