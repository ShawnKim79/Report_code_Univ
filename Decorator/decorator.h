#include <iostream.h>

/////////////////////////////////////////////////////////
// Component Ŭ���� (��ǻ� �������̽�?)
class Component
{
public:
	virtual void prtTicket();
};

void Component::prtTicket()
{
}
/////////////////////////////////////////////////////////
// TicketDecorator Ŭ����
class TicketDecorator:public Component
{
public:
	TicketDecorator();
	void SetDecorator(Component*);
	virtual void prtTicket();

protected:
	Component* _component;
};

void TicketDecorator::prtTicket()
{
	_component->prtTicket();
}

TicketDecorator::TicketDecorator()
{
	//_component = cTemp;
}

void TicketDecorator::SetDecorator(Component* cTemp)
{
	_component = cTemp;
}



/////////////////////////////////////////////////////////
// SalesTicket Ŭ����
class SalesTicket:public Component
{
	virtual void prtTicket();
};

void SalesTicket::prtTicket()
{
	cout << "This is Sales.prtTicket()" << endl;
}

/////////////////////////////////////////////////////////
// HeaderDecorator Ŭ����
class HeaderDecorator:public TicketDecorator
{
public:
	HeaderDecorator();
	//void SetHeaderDecorator(Component* cTemp);
	virtual void prtTicket();

private:
	void prtHeader();
};

HeaderDecorator::HeaderDecorator()
{
	//_component = cTemp;
}

void HeaderDecorator::prtHeader()
{
	cout << "This is HeaderDecorator.prtHeader()" << endl;
}

void HeaderDecorator::prtTicket()
{
	prtHeader();
	_component->prtTicket();
	cout << "This is HeaderDecorator.prtTicket()" << endl;
}


/////////////////////////////////////////////////////////
// FooterDecorator Ŭ����
class FooterDecorator:public TicketDecorator
{
public:
	FooterDecorator();
	virtual void prtTicket();

private:
	void prtFooter();
};

FooterDecorator::FooterDecorator()
{
	//_component = cTemp;
}

void FooterDecorator::prtFooter()
{
	cout << "This is FooterDecorator.prtFooter()" << endl;
}

void FooterDecorator::prtTicket()
{
	_component->prtTicket();
	cout << "This is FooterDecorator.prtTicket()" << endl;
	prtFooter();
}
