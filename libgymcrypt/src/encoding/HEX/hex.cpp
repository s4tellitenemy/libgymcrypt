#include "hex.h"
#include <Windows.h>
#include <cryptopp/hex.h>

using namespace CryptoPP;

namespace GymCrypt
{
	std::string HEX::Encode(const std::string& szData)
	{
		if (szData.empty())
			return "";

		HEX hex;
		const auto pEncodedData = hex.EncodeStub((const BYTE*)&szData[0], szData.size());
		std::string encoded(reinterpret_cast<const char*>(pEncodedData->pData), pEncodedData->dwDataSize);

		delete[] pEncodedData->pData;
		delete pEncodedData;

		return encoded;
	}

	PENCODED_DATA HEX::EncodeStub(const BYTE* pData, size_t dwDataSize)
	{
		PENCODED_DATA pEncodedData = new ENCODED_DATA;
		if (NULL == pEncodedData)
			return nullptr;

		std::string encoded;

		StringSource ss(pData, dwDataSize, true,
			new HexEncoder(
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

	std::string HEX::Decode(const std::string& szData)
	{
		if (szData.empty())
			return "";

		HEX hex;
		const auto pDecodedData = hex.DecodeStub((const BYTE*)&szData[0], szData.size());
		std::string decoded(reinterpret_cast<const char*>(pDecodedData->pData), pDecodedData->dwDataSize);

		delete[] pDecodedData->pData;
		delete pDecodedData;

		return decoded;
	}

	PDECODED_DATA HEX::DecodeStub(const BYTE* pData, size_t dwDataSize)
	{
		PDECODED_DATA pDecodedData = new DECODED_DATA;
		if (NULL == pDecodedData)
			return nullptr;

		std::string decoded;

		StringSource ss(pData, dwDataSize, true,
			new HexDecoder(
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