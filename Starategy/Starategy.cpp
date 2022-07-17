#include <iostream.h>
#include "starategy.h"

class Composition
{
public:
	Composition(Compositor*);
	void ShotSelect();
/*
	int m_swingPower;
	int m_swingAngle;
	int m_batFound;
*/

private:
	Compositor* _compositor;
};

Composition::Composition(Compositor* temp)
{
	_compositor = temp;
}

void Composition::ShotSelect()
{
	int swingPower;
	int swingAngle;
	
	cout << "input swing power : ";
	cin >> swingPower;
	cout << "input swing angle : ";
	cin >> swingAngle;

	_compositor->Shot(swingPower, swingAngle);

}

void main()
{
	Composition* Low = new Composition(new LowShot);
	Composition* Mid = new Composition(new MidShot);
	Composition* High = new Composition(new HighShot(10));

	Low->ShotSelect();
	Mid->ShotSelect();
	High->ShotSelect();
}