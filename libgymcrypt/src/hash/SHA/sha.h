#pragma once
#include <string>
#include <map>
#include <iterator>
#include <cryptopp/sha.h>
#include <cryptopp/sha3.h>

namespace GymCrypt
{
	typedef enum class _HASH_TYPE
	{
		SHA1,
		SHA3,
		SHA128,
		SHA224,
		SHA256,
		SHA384,
		SHA512,
	
	}HASH_TYPE;

	// GymCrypt::HASH<SHA256> md5;
	// md5.Digest();

	static std::map<HASH_TYPE, CryptoPP::HashTransformation*> hash_types = {
		{HASH_TYPE::SHA1, new CryptoPP::SHA1()},
		// Add SHA3 here
		//{HASH_TYPE::SHA128, new CryptoPP::SHA128()},
		{HASH_TYPE::SHA224, new CryptoPP::SHA224()},
		{HASH_TYPE::SHA256, new CryptoPP::SHA256()},
		{HASH_TYPE::SHA384, new CryptoPP::SHA384()},
		{HASH_TYPE::SHA512, new CryptoPP::SHA512()},
	};

	template <HASH_TYPE Type>
	class SHA
	{
	public:
		SHA()
		{
			this->pData = NULL;
			this->dwDataSize = 0;

			this->hash = std::make_unique<CryptoPP::SHA56>();
		}
		
		~SHA();

		std::string Digest();
		
		bool Update(const std::string& szData);
		bool Update(const PBYTE pData, size_t dwDataSize);
		
		bool Verify(const std::string& szDigest);
		bool Verify(const std::string& szDigest, const PBYTE pData, size_t dwDataSize);

		inline size_t blocksize()
		{
			return hash->BlockSize();
		}

	private:
		void Clean()
		{
			if (NULL != this->pData)
			{
				SecureZeroMemory(this->pData, this->dwDataSize);
				free(this->pData);
				this->pData = NULL;
			}
		}

	private:
		PBYTE pData;
		size_t dwDataSize;

		std::unique_ptr<CryptoPP::HashTransformation> hash;
	};
}