#ifndef _LINEARHASH_H_
#define _LINEARHASH_H_

#include <stdio.h>
#include <windows.h>
#include <time.h>

#define NOTUSED	0

typedef struct
{
	char cID[32];
	int iUniqueIndex;

}DATA *LPDATA;

class CLinearHash
{
private:
	int *m_iHashTable, m_iBucketSize;

public:
	CLinearHash();
	~CLinearHash();

	void Initialize(int iBucketSize);
	void Insert(char *cpKey, int iUniqueIndex);
	void Delete(char *cpKey);
	int Search(char *cpKey);
	int HashFunc(char *cpKey);
};

#endif

#include "LinearHash.h"

#define MAXBUCKETSIZE 1024

CLinearHash g_LinearHash;

CLinearHash::CLinearHash()
{
}

CLinearHash::~CLinearHash()
{
}


void CLinearHash::Initialize(int iBucketSize)
{
	int iN;

	m_iHashTable = new int[iBucketSize];

	if(m_iHashTable == NULL) return;

	m_iBucketSize = iBucketSize;

	for(iN=0 ; iN<iBucketSize ; iN++)
		m_iHashTable[iN] = NOTUSED;
}

void CLinearHash::Insert(char *cpKey, int iUniqueIndex)
{
	int iHashValue;
	LPDATA lpData;

	iHashValue = HashFunc(cpKey);
}