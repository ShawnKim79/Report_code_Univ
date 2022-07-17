#include <iostream.h>
#include "ab_factory.h"

void main()
{
	int iType;
	
	CVideo* pVideo;
	CPrinter* pPrinter;

	CResFactory* pResFactory;

	cout << "해상도를 결정해 주십시오(1: 저해상도 2: 고해상도) : ";
	cin >> iType;

	if(iType == 1) // 저해상도 처리
	{
		pResFactory = new CLowResFact;
		pVideo = pResFactory->getDispDrv();
		pPrinter = pResFactory->getPrtDrv();

		pVideo->setVideoRes();
		pPrinter->setPrinterRes();

		delete pVideo, pPrinter;
	}
	else if(iType == 2) // 고해상도 처리
	{
		pResFactory = new CHighResFact;
		pVideo = pResFactory->getDispDrv();
		pPrinter = pResFactory->getPrtDrv();

		pVideo->setVideoRes();
		pPrinter->setPrinterRes();

		delete pVideo, pPrinter;
	}

	delete pResFactory;
}