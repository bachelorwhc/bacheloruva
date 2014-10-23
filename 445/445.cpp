#include <iostream>
#include <string>
#include <cctype>

int main()
{
	std::string s;
	while (std::getline(std::cin, s))
	{
		unsigned int count(0);
		for(unsigned int i = 0; i < s.length(); ++i)
		{
			if(isdigit(s[i]))
			{
				count += s[i] - '0';
			}
			else if(s[i] == '!')
				std::cout << std::endl;
			else
			{
				for(unsigned int t = 0; t < count; ++t)
					if(s[i] == 'b')
						std::cout << ' ';
					else
						std::cout << s[i];
				count = 0;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}