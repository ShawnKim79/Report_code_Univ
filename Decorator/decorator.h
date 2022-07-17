#include <iostream.h>

/////////////////////////////////////////////////////////
// Component 클래스 (사실상 인터페이스?)
class Component
{
public:
	virtual void prtTicket();
};

void Component::prtTicket()
{
}
/////////////////////////////////////////////////////////
// TicketDecorator 클래스
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
// SalesTicket 클래스
class SalesTicket:public Component
{
	virtual void prtTicket();
};

void SalesTicket::prtTicket()
{
	cout << "This is Sales.prtTicket()" << endl;
}

/////////////////////////////////////////////////////////
// HeaderDecorator 클래스
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
// FooterDecorator 클래스
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
