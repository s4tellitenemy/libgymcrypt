#pragma once
#include <string>
#include "encoding/encoding.h"

namespace GymCrypt
{
	class URL : public Encoding
	{
	private:
		PENCODED_DATA EncodeStub(const BYTE* pData, size_t dwDataSize) override
		{
			return nullptr;
		}

		PDECODED_DATA DecodeStub(const BYTE* pData, size_t dwDataSize) override
		{
			return nullptr;
		}
	
	public:
		static inline std::string Encode(const std::string& szData)
		{
			return boost::network::uri::encoded(szData);
		}
		
		static inline std::string Decode(const std::string& szData)
		{
			return boost::network::uri::decoded(szData);
		}
	};
}