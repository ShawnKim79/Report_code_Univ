#include <iostream.h>

#include "comp.h"

void main()
{
	CCompositeEquipment cFcs("FCS");
	CCompositeEquipment cSenser("Senser");
	CCompositeEquipment cFirectrl("Fire Control");

	// 2. 기능 개체
	CEquipment cRader("Rader", 300);
	CEquipment cIrtv("IR_Tv", 250);
	CEquipment cGunpc("Gun_PC", 200);
	CEquipment cMslpc("Missle_PC", 250);
	CEquipment cDatalnk("Data_Link", 300);

	// 3. 각 기능 포함.
	cSenser.Add(&cRader);
	cSenser.Add(&cIrtv);
	cFirectrl.Add(&cGunpc);
	cFirectrl.Add(&cMslpc);
	cFcs.Add(&cSenser);
	cFcs.Add(&cFirectrl);
	cFcs.Add(&cDatalnk);

	cout << "컴포넌트 이름 : " << cFcs.Name() << " 가격 :" << cFcs.NetPrice() << endl;
	cout << "컴포넌트 이름 : " << cSenser.Name() << " 가격 :" << cSenser.NetPrice() << endl;
	cout << "컴포넌트 이름 : " << cFirectrl.Name() << " 가격 :" << cFirectrl.NetPrice() << endl;

}