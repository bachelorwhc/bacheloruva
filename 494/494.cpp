#include <iostream>
#include <string>
#include <cstdlib>

int main()
{
	std::string s;
	while (std::getline(std::cin, s))
	{
		unsigned int l(s.length());
		unsigned int token(0);
		char p = s[0];
		bool skip(false);
		for (unsigned int i = 1; i < l; ++i)
		{
			if (isalpha(p))
			{
				if (!isalpha(s[i]))
					++token;
			}
			p = s[i];
		}
		if (isalpha(p))
			++token;
		std::cout << token << std::endl;
	}
	return 0;
}