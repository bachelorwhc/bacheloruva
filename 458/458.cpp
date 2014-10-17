#include <iostream>
#include <string>

int main()
{
	std::string s;
	while (std::getline(std::cin, s))
	{
		unsigned int l(s.length());
		for (int i = 0; i < l; ++i)
			s[i] = (char)((int)s[i] - 7);
		std::cout << s << std::endl;
	}
	return 0;
}