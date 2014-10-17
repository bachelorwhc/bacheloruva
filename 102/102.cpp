#include <iostream>
#include <numeric>
#include <vector>

enum BinColor{
	BROWN, CLEAR, GREEN
};

struct Recyle
{
	unsigned int brown;
	unsigned int green;
	unsigned int clear;
};

void SumBin(Recyle* rs, BinColor bc, unsigned int* total)
{
	for (int i = 0; i < 3; ++i)
	{
		switch (bc)
		{
		case BROWN:
			total[bc] += rs[i].brown;
			break;
		case GREEN:
			total[bc] += rs[i].green;
			break;
		case CLEAR:
			total[bc] += rs[i].clear;
			break;
		}
	}
}

unsigned int CountTime(unsigned short index, Recyle* rs, BinColor c)
{
	unsigned int sum = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (index == i)
			continue;
		switch (c)
		{
		case BROWN:
			sum += rs[i].brown;
			break;
		case GREEN:
			sum += rs[i].green;
			break;
		case CLEAR:
			sum += rs[i].clear;
			break;
		}
	}
	return sum;
}

unsigned int TimeOfMove(BinColor* rc, Recyle* rs)
{
	unsigned int times = 0;
	for (unsigned short i = 0; i < 3; ++i)
	{
		switch (rc[i])
		{
		case BROWN:
			times += CountTime(i, rs, BROWN);
			break;
		case GREEN:
			times += CountTime(i, rs, GREEN);
			break;
		case CLEAR:
			times += CountTime(i, rs, CLEAR);
			break;
		}
	}
	return times;
}

BinColor order[18] = { BROWN, CLEAR, GREEN, BROWN, GREEN, CLEAR, CLEAR, BROWN, GREEN, CLEAR, GREEN, BROWN, GREEN, BROWN, CLEAR, GREEN, CLEAR, BROWN };
int main()
{
	Recyle* rs = new Recyle[3];
	while (std::cin
		>> (rs + 0)->brown >> (rs + 0)->green >> (rs + 0)->clear
		>> (rs + 1)->brown >> (rs + 1)->green >> (rs + 1)->clear
		>> (rs + 2)->brown >> (rs + 2)->green >> (rs + 2)->clear)
	{
		unsigned int total_bin[3] = { 0 };
		SumBin(rs, BROWN, total_bin);
		SumBin(rs, GREEN, total_bin);
		SumBin(rs, CLEAR, total_bin);
		unsigned int min = 2147483647;
		unsigned int base = 0;
		for (int i = 0; i < 6; ++i)
		{
			unsigned int t = TimeOfMove((order + i * 3), rs);
			if (min > t)
			{
				min = t;
				base = i;
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			switch (order[base * 3 + i])
			{
			case BROWN:
				std::cout << 'B';
				break;
			case GREEN:
				std::cout << 'G';
				break;
			case CLEAR:
				std::cout << 'C';
				break;
			}
		}
		std::cout << ' ' << min << std::endl;
	}
	return 0;
}