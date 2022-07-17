#include <iostream.h>
#include "comp.h"

void main()
{
	CManagerEmployee cCEO("CEO", 1000);
	CManagerEmployee cVPMktg("VP Marketing");
	CManagerEmployee cVPProd("VP Production");

	CManagerEmployee cSalesMgr("Sales Manager", 500);
	CManagerEmployee cMktgMgr("Marketing Manager", 500);
	CManagerEmployee cProMgr("Pro Manager", 500);
	CManagerEmployee cShipMgr("Ship Manager", 500);

	CEmployee cSales1("Sales Man 1", 200);
	CEmployee cSales2("Sales Man 2", 200);

	CEmployee cSecy1("Secretary", 180);

	CEmployee cShip1("Ship1", 150);
	CEmployee cShip2("Ship2", 150);
	CEmployee cShip3("Ship3", 150);

	CEmployee cTitle1("Title1", 160);
	CEmployee cTitle2("Title2", 160);

	cSalesMgr.Add(&cSales1);
	cSalesMgr.Add(&cSales2);

	cMktgMgr.Add(&cSecy1);

	cProMgr.Add(&cShip1);
	cProMgr.Add(&cShip2);
	cProMgr.Add(&cShip3);

	cShipMgr.Add(&cTitle1);
	cShipMgr.Add(&cTitle2);
	
	cVPMktg.Add(&cSalesMgr);
	cVPMktg.Add(&cMktgMgr);
	cVPProd.Add(&cProMgr);
	cVPProd.Add(&cShipMgr);

	cCEO.Add(&cVPMktg);
	cCEO.Add(&cVPProd);

	cout << cCEO.Name() << cCEO.NetSalary() << endl;
	cout << cVPMktg.Name() << cVPMktg.NetSalary() << endl;
	cout << cVPProd.Name() << cVPProd.NetSalary() << endl;
	cout << cSalesMgr.Name() << cSalesMgr.NetSalary() << endl;
	cout << cMktgMgr.Name() << cMktgMgr.NetSalary() << endl;
	cout << cProMgr.Name() << cProMgr.NetSalary() << endl;
	cout << cShipMgr.Name() << cShipMgr.NetSalary() << endl;
}