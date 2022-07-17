// 추상 클래스 : 비디오
class CVideo
{
public:
	virtual int setVideoRes() = 0;
};

// 추상 클래스 : 프린터
class CPrinter
{
public:
	virtual int setPrinterRes() = 0;
};

class CHighVideo:public CVideo // 고해상도 비디오 객체
{
public:
	virtual int setVideoRes()
	{
		cout << "Set Video Resolution : High" << endl;
		return 1;
	}
};

class CLowVideo:public CVideo // 저해상도 비디오 객체
{
public:
	virtual int setVideoRes()
	{
		cout << "Set Video Resolution : Low" << endl;
		return 1;
	}

};

class CHighPrinter:public CPrinter // 고해상도 프린터 객체
{
public:
	virtual int setPrinterRes()
	{
		cout << "Set Printer Resolution : High" << endl;
		return 1;
	}
};

class CLowPrinter:public CPrinter // 저해상도 프린터 객체
{
public:
	virtual int setPrinterRes()
	{
		cout << "Set Printer Resolution : Low" << endl;
		return 1;
	}
};


// 추상 공장
class CResFactory
{
public:
	virtual CVideo* getDispDrv() = 0;	// 해상도 드라이버
	virtual CPrinter* getPrtDrv() = 0;	// 프린터 드라이버
};

// 고해상도 버전 생성
class CHighResFact:public CResFactory
{
public:
	virtual CVideo* getDispDrv(){return new CHighVideo;}
	virtual CPrinter* getPrtDrv(){return new CHighPrinter;}
};

// 저해상도 버전 생성
class CLowResFact:public CResFactory
{
public:
	virtual CVideo* getDispDrv(){return new CLowVideo;}
	virtual CPrinter* getPrtDrv(){return new CLowPrinter;}
};