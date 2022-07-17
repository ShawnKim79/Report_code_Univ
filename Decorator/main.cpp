#include "decorator.h"

void main()
{
	SalesTicket *pSalesTicket = new SalesTicket();
	HeaderDecorator *pHeaderDecorator = new HeaderDecorator();
	pHeaderDecorator->SetDecorator(pSalesTicket);
	FooterDecorator *pFooterDecorator = new FooterDecorator();
	pFooterDecorator->SetDecorator(pHeaderDecorator);

	//pHeaderDecorator->prtTicket();
	pFooterDecorator->prtTicket();
}
