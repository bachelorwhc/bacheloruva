#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	unsigned short c;
	unsigned long long s = 0;
	while (std::cin >> c, c != 0)
	{
		++s;
		std::vector<unsigned short> boxs(c);
		unsigned short total_box(0);
		for (unsigned short i = 0; i < c; ++i)
		{
			std::cin >> boxs[i];
			total_box += boxs[i];
		}
		unsigned short average(total_box / c);
		unsigned short moves(0);
		for (unsigned short i = 0; i < c; ++i)
			moves += std::abs(boxs[i] - average);
		
		std::cout << "Set #" << s << std::endl;
		std::cout << "The minimum number of moves is " << moves / 2 << '.' << std::endl << std::endl;
	}
	return 0;
}