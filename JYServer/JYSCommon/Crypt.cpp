
#include "ProjectJY.h"
#include "Crypt.h"
#include <string>

namespace jy
{
	const std::string ForeignKey = "Netmarble Nexus - Seven Knights 2";

	void Crypt::Convert(char* buffer, int size)
	{
		return;

		char* pos = buffer;
		char key = 0;

		for (int n = 0; n < size; ++n)
		{
			key = (char)((key + ForeignKey.at(n % ForeignKey.size())) * 253 + 195);
			*pos = (char)(*pos) ^ key;
			++pos;
		}
	}
}