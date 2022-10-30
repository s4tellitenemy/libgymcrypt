#include "sha.h"
#include "encoding/HEX/hex.h"

namespace GymCrypt
{
	std::string SHA::Digest()
	{
		std::string digest;
		hash->Update(pData, dwDataSize);
		
		digest.resize(hash->DigestSize());
		hash->Final((PBYTE)&digest[0]);

		this->Clean();

		return HEX::Encode(digest);
	}

	bool SHA::Update(const std::string& szData)
	{
		return this->Update((const PBYTE)szData.data(), szData.size());
	}

	bool SHA::Update(const PBYTE pData, size_t dwDataSize)
	{
		if (NULL == this->pData)
		{
			this->pData = (PBYTE)malloc(dwDataSize);
			
			if (NULL == this->pData)
				return false;

			SecureZeroMemory(this->pData, dwDataSize);
			memcpy_s(this->pData, dwDataSize, pData, dwDataSize);

			this->dwDataSize = dwDataSize;
		}
		else
		{
			this->pData = (PBYTE)realloc(this->pData, this->dwDataSize + dwDataSize);
			
			if (NULL == this->pData)
				return false;

			SecureZeroMemory((this->pData + this->dwDataSize), dwDataSize);
			memcpy_s((this->pData + this->dwDataSize), this->dwDataSize + dwDataSize, pData, dwDataSize);

			this->dwDataSize += dwDataSize;
		}

		return true;
	}
	
	bool SHA::Verify(const std::string& szDigest)
	{
		if (NULL == this->pData)
			return false;


	}

	bool SHA::Verify(const std::string& szDigest, const PBYTE pData, size_t dwDataSize)
	{
		hash->Update(pData, dwDataSize);
		return hash->Verify((const BYTE*)szDigest.data());
	}

	SHA::~SHA()
	{
		this->Clean();
	}
}