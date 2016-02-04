#include <iostream>

int main()
{
	int in;
	std::cin >> in;
	for(int i = 0; i < in; ++i)
	{
		long long a, b;
		std::cin >> a >> b;
		if(a > b)
			std::cout << '>' << std::endl;
		else if(a == b)
			std::cout << '=' << std::endl;
		else
			std::cout << '<' << std::endl;
	}
	return 0;
}