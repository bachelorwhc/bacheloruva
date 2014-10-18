#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

int main()
{
	std::string s;
	while (std::getline(std::cin, s))
	{
		char* cs((char*)s.c_str());

		bool* space_table = new bool[s.length()];
		for(unsigned short i = 0; i < s.length(); ++i)
		{
			space_table[i] = false;
			if(s[i] == ' ')
				space_table[i] = true;
		}

		char* token(strtok(cs, " "));

		for(unsigned int count = 0; count < s.length();)
		{
			if(space_table[count])
			{
				std::cout << ' ';
				++count;
			}
			else
			{
				std::string t(token);
				unsigned int len(t.length());
				for(short i = len - 1; i >= 0; --i)
				{
					std::cout << t[i];
					++count;
				}
				token = strtok(NULL, " ");
			}
		}

		std::cout << std::endl;
	}
	return 0;
}