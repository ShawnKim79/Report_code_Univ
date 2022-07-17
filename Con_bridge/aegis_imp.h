#include "aegis.h"

class CAegisImp
{
public:
	virtual void Senser_Search() = 0;
	// 각 함별로 서로 다른 센서 보유.
	// 함의 기종에 따라 다르게 구현해야 함.
};