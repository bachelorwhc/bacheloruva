#include <iostream>

int main()
{
	unsigned int it;
	std::cin >> it;
	for(unsigned int i = 0; i < it; ++i)
	{
		long s, d;
		std::cin >> s >> d;
		long px((s + d) / 2);
		long py(s - px);

		if(px < 0 || py < 0 || (px - py != d))
			std::cout << "impossible" << std::endl;
		else
			std::cout << px << ' ' << py << std::endl;
	}
	return 0;
}