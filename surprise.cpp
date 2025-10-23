#include "Demineur.h"

void easterEggCat()
{
	const string cat[3] = {
		R"(    |\__/,|   (`\)",
		R"(  _.|o o  |_   ) ))",
		R"(-(((---(((--------)",
	};
	for (int i = 0; i < 3; ++i)
		cout << cat[i] << endl;
}