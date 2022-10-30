#pragma once
#include <string>

namespace GymCrypt
{
	class MD5
	{
	public:
		static void Update();
		static std::string Digest(const std::string& szData, bool truncated);
		static bool Verify();
	};
}