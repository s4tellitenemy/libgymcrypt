#pragma once
#include <boost/network/uri.hpp>
#include <Windows.h>

typedef struct _DATA
{
	PBYTE pData;
	size_t dwDataSize;
} ENCODED_DATA, *PENCODED_DATA, DECODED_DATA, *PDECODED_DATA;

class Encoding
{
protected:
	virtual PENCODED_DATA EncodeStub(const BYTE* pData, size_t dwDataSize) = 0;
	virtual PDECODED_DATA DecodeStub(const BYTE* pData, size_t dwDataSize) = 0;
};