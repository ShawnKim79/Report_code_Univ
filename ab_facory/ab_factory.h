// �߻� Ŭ���� : ����
class CVideo
{
public:
	virtual int setVideoRes() = 0;
};

// �߻� Ŭ���� : ������
class CPrinter
{
public:
	virtual int setPrinterRes() = 0;
};

class CHighVideo:public CVideo // ���ػ� ���� ��ü
{
public:
	virtual int setVideoRes()
	{
		cout << "Set Video Resolution : High" << endl;
		return 1;
	}
};

class CLowVideo:public CVideo // ���ػ� ���� ��ü
{
public:
	virtual int setVideoRes()
	{
		cout << "Set Video Resolution : Low" << endl;
		return 1;
	}

};

class CHighPrinter:public CPrinter // ���ػ� ������ ��ü
{
public:
	virtual int setPrinterRes()
	{
		cout << "Set Printer Resolution : High" << endl;
		return 1;
	}
};

class CLowPrinter:public CPrinter // ���ػ� ������ ��ü
{
public:
	virtual int setPrinterRes()
	{
		cout << "Set Printer Resolution : Low" << endl;
		return 1;
	}
};


// �߻� ����
class CResFactory
{
public:
	virtual CVideo* getDispDrv() = 0;	// �ػ� ����̹�
	virtual CPrinter* getPrtDrv() = 0;	// ������ ����̹�
};

// ���ػ� ���� ����
class CHighResFact:public CResFactory
{
public:
	virtual CVideo* getDispDrv(){return new CHighVideo;}
	virtual CPrinter* getPrtDrv(){return new CHighPrinter;}
};

// ���ػ� ���� ����
class CLowResFact:public CResFactory
{
public:
	virtual CVideo* getDispDrv(){return new CLowVideo;}
	virtual CPrinter* getPrtDrv(){return new CLowPrinter;}
};