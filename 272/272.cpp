#include <iostream>
#include <string>

int main()
{
	std::string s;
	bool o(true);
	while (std::getline(std::cin, s))
	{
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '\"')
			{
				if (o)
					std::cout << "\`\`";
				else
					std::cout <<"\'\'";
				o = !o;
			}
			else
				std::cout << s[i];
		}
		std::cout << std::endl;
	}
	return 0;
}