#include <iostream.h>

#include "comp.h"

void main()
{
	CCompositeEquipment cFcs("FCS");
	CCompositeEquipment cSenser("Senser");
	CCompositeEquipment cFirectrl("Fire Control");

	// 2. ��� ��ü
	CEquipment cRader("Rader", 300);
	CEquipment cIrtv("IR_Tv", 250);
	CEquipment cGunpc("Gun_PC", 200);
	CEquipment cMslpc("Missle_PC", 250);
	CEquipment cDatalnk("Data_Link", 300);

	// 3. �� ��� ����.
	cSenser.Add(&cRader);
	cSenser.Add(&cIrtv);
	cFirectrl.Add(&cGunpc);
	cFirectrl.Add(&cMslpc);
	cFcs.Add(&cSenser);
	cFcs.Add(&cFirectrl);
	cFcs.Add(&cDatalnk);

	cout << "������Ʈ �̸� : " << cFcs.Name() << " ���� :" << cFcs.NetPrice() << endl;
	cout << "������Ʈ �̸� : " << cSenser.Name() << " ���� :" << cSenser.NetPrice() << endl;
	cout << "������Ʈ �̸� : " << cFirectrl.Name() << " ���� :" << cFirectrl.NetPrice() << endl;

}