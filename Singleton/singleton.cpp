#include <iostream.h>
#include "singleton.h"

void main()
{
	CNavigation *pNav = CNavigation::GetInstance();

	pNav->SetPoint();
	pNav->ViewPath();
}