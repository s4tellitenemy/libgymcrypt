#pragma once
#include <Windows.h>
#include <string>
#include "encoding/encoding.h"

namespace GymCrypt
{
	class Base64 : public Encoding
	{
	private:
		static Base64 instance;

		PENCODED_DATA EncodeStub(const BYTE* pData, size_t dwDataSize) override;
		PDECODED_DATA DecodeStub(const BYTE* pData, size_t dwDataSize) override;

	public:
		static inline std::string Encode(const std::string& szData);
		static inline std::string Decode(const std::string& szData);
	};
}