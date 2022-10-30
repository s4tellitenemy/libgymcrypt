#include "md5.h"
#include <cryptopp/md5.h>
#include <cryptopp/filters.h>
#include <cryptopp/cryptlib.h>
#include "encoding/HEX/hex.h"

namespace GymCrypt
{
	std::string MD5::Digest(const std::string& szData, bool truncated = false)
	{
		std::string digest;

		CryptoPP::Weak1::MD5 md5;
		md5.Update((const unsigned char*)szData.data(), szData.size());

		if (truncated) {
			digest.resize(md5.DigestSize());
			md5.Final((unsigned char*)&digest[0]);
		}
		else {
			digest.resize(md5.DigestSize() / 2);
			md5.TruncatedFinal((unsigned char*)&digest[0], digest.size());
		}

		return HEX::Encode(digest);
	}
}