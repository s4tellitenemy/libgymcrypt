#include <iostream>
#include <string>
#include "libgymcrypt.h"

int main(int argc, char* argv[])
{
	std::string msg1 = "FUCK";
	std::string msg2 = "YOU12345";

	// not same fucking class instance so data gets deleted, i guess i do need to create a class instance instead of using static methods

	GymCrypt::SHA2 hash;
	
	hash.Update(msg1);
	hash.Update(msg2);
	hash.Update((const PBYTE)"HELLO", 5);

	std::string digest = hash.Digest();

	hash.Update("TEST");
	std::cout << hash.Digest() << std::endl;

	std::cout << digest << std::endl;

	return 0;
}