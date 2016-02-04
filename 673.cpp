#include <iostream>
#include <string>
#include <vector>

int main()
{
	unsigned int t;
	std::string s;
    std::cin >> t;
    std::cin.ignore();
    while(t--)
    {
		std::getline(std::cin, s);
		unsigned int len(s.length());
		std::vector<int> p;
		bool right(true);
		for(unsigned int i = 0; i < len; ++i)
		{
			if(s[i] == '(')
				p.push_back(0);
			else if(s[i] == ')')
				if((!p.empty()) && *(p.end()-1) == 0)
					p.pop_back();
				else
				{
					right = false;
					break;
				}
			else if(s[i] == '[')
				p.push_back(1);
			else if(s[i] == ']')
				if((!p.empty()) && *(p.end()-1) == 1)
					p.pop_back();
				else
				{
					right = false;
					break;
				}
		}
		if(right && p.empty())
		{
			std::cout << "Yes" << std::endl;
		}
		else
		{
			std::cout << "No" << std::endl;
		}
	}
	return 0;
}