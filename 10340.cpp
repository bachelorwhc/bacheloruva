#include <iostream>
#include <string>

int main()
{
	std::string lhs, rhs;
	while (std::cin >> lhs >> rhs)
	{
		unsigned int pol(0);
		unsigned int len(rhs.length());
		for(unsigned int i = 0; i < len; ++i)
		{
			if(pol == lhs.length())
				break;
			if(rhs[i] == lhs[pol]) pol++;
		}
		if(pol == lhs.length())
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	}
	return 0;
}