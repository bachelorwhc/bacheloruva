#include <iostream>

int main()
{
	unsigned int it;
	std::cin >> it;
	for(unsigned int i = 0; i < it; ++i)
	{
		unsigned short a;
		unsigned int f;
		std::cin >> a >> f;
		for(unsigned int j = 0; j < f; ++j)
		{
			for(unsigned short na = 1; na < a; ++na)
			{
				for(unsigned short n = 0; n < na; ++n)
					std::cout << na;
				std::cout << std::endl;
			}
			for(unsigned short na = a; na > 0; --na)
			{
				for(unsigned short n = na; n > 0; --n)
					std::cout << na;
				if(!(na == 1 && i == it - 1 && j == f-1))
					std::cout << std::endl;
			}
			//if(!(i == it - 1 && j == f-1))
				std::cout << std::endl;
		}
	}
	return 0;
}