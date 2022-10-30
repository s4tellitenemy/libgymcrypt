#pragma once
#include <string>
#include "encoding/encoding.h"

namespace GymCrypt
{
	class HEX : public Encoding
	{
	private:
		static HEX instance;

		PENCODED_DATA EncodeStub(const BYTE* pData, size_t dwDataSize) override;
		PDECODED_DATA DecodeStub(const BYTE* pData, size_t dwDataSize) override;

	public:
		static std::string Encode(const std::string& szData);
		static std::string Decode(const std::string& szData);
	};
}