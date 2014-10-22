#include <iostream>
#include <vector>

struct Day
{
	Day() : a(false) {};
	bool a;
	char alignment[3];

	void set(bool b, unsigned short d)
	{
		if(d % 7 == 6 || d % 7 == 0)
			return;
		a = b;
	}
};

int main()
{
	unsigned int it;
	std::cin >> it;
	for(unsigned int i = 0; i < it; ++i)
	{
		unsigned short nday;
		std::cin >> nday;
		unsigned short n_of_h;
		std::cin >> n_of_h;
		std::vector<Day> s(nday);
		for(unsigned short j = 0; j < n_of_h; ++j)
		{
			unsigned int hj;
			std::cin >> hj;
			for(unsigned int d = 0; d <= nday; d += hj)
			{
				s[d-1].set(true, d);
			}
		}
		unsigned short count(0);
		for(unsigned short j = 0; j < nday; ++j)
		{
			if(s[j].a)
				++count;
		}
		std::cout << count << std::endl;
	}
	return 0;
}
