#include <iostream>
#include <algorithm>
#include <cmath>

int main()
{
	double lights;
	while (std::cin >> lights)
	{
		bool isl(false);
		unsigned int limit(ceil(sqrt(lights)));

		if(((unsigned int)floor(lights)) == 0)
			break;
		if((unsigned int)lights == 1)
			isl = true;
		if((unsigned int)lights == 4)
			isl = true;

		for(unsigned int laps = 3; laps <= limit; ++laps)
		{
			if((unsigned int)lights % laps == 0)
				isl = !isl;
		}
		if(isl)
			std::cout << "yes" << std::endl;
		else
			std::cout << "no" << std::endl;
	}
	return 0;
}