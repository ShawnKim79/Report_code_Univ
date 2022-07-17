#include <iostream.h>
#include "ab_factory.h"

void main()
{
	int iType;
	
	CVideo* pVideo;
	CPrinter* pPrinter;

	CResFactory* pResFactory;

	cout << "�ػ󵵸� ������ �ֽʽÿ�(1: ���ػ� 2: ���ػ�) : ";
	cin >> iType;

	if(iType == 1) // ���ػ� ó��
	{
		pResFactory = new CLowResFact;
		pVideo = pResFactory->getDispDrv();
		pPrinter = pResFactory->getPrtDrv();

		pVideo->setVideoRes();
		pPrinter->setPrinterRes();

		delete pVideo, pPrinter;
	}
	else if(iType == 2) // ���ػ� ó��
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