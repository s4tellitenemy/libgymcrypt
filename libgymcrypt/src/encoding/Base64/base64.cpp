#include "base64.h"
#include <cryptopp/base64.h>

using namespace CryptoPP;

namespace GymCrypt
{
	std::string Base64::Encode(const std::string& szData)
	{
		if (szData.empty())
			return "";

		const auto pEncodedData = instance.EncodeStub((const unsigned char*)szData.data(), szData.size());
		std::string encoded(reinterpret_cast<const char*>(pEncodedData->pData), pEncodedData->dwDataSize);

		delete[] pEncodedData->pData;
		delete pEncodedData;

		return encoded;
	}

	PENCODED_DATA Base64::EncodeStub(const BYTE* pData, size_t dwDataSize)
	{
		PENCODED_DATA pEncodedData = new ENCODED_DATA;
		if (NULL == pEncodedData)
			return nullptr;

		std::string encoded;

		StringSource ss(pData, dwDataSize, true,
			new Base64Encoder(
				new StringSink(encoded)
			));

		pEncodedData->dwDataSize = encoded.size();

		pEncodedData->pData = new BYTE[pEncodedData->dwDataSize];
		if (NULL == pEncodedData->pData)
		{
			delete pEncodedData;
			return nullptr;
		}

		memcpy_s(pEncodedData->pData, pEncodedData->dwDataSize, encoded.data(), pEncodedData->dwDataSize);
		return pEncodedData;
	}

	std::string Base64::Decode(const std::string& szData)
	{
		if (szData.empty())
			return "";

		const auto pDecodedData = instance.DecodeStub((const BYTE*)&szData[0], szData.size());
		std::string decoded(reinterpret_cast<const char*>(pDecodedData->pData), pDecodedData->dwDataSize);

		delete[] pDecodedData->pData;
		delete pDecodedData;

		return decoded;
	}

	PDECODED_DATA Base64::DecodeStub(const BYTE* pData, size_t dwDataSize)
	{
		PDECODED_DATA pDecodedData = new DECODED_DATA;
		if (NULL == pDecodedData)
			return nullptr;

		std::string decoded;

		StringSource ss(pData, dwDataSize, true,
			new Base64Decoder(
				new StringSink(decoded)
			));

		pDecodedData->dwDataSize = decoded.size();

		pDecodedData->pData = new BYTE[pDecodedData->dwDataSize];
		if (NULL == pDecodedData->pData)
		{
			delete pDecodedData;
			return nullptr;
		}

		memcpy_s(pDecodedData->pData, pDecodedData->dwDataSize, decoded.data(), pDecodedData->dwDataSize);
		return pDecodedData;
	}
}