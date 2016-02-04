#include <iostream>
#include <algorithm>
#include <vector>

bool isOrder(std::vector<unsigned short>& t)
{
	unsigned int len = t.size();
	for(unsigned int i = 0; i < len; ++i)
	{
		if(t[i] != i + 1)
			return false;
	}
	return true;
}

void toPos(std::vector<unsigned short>& t, unsigned short p, unsigned short target, bool right, unsigned int & count)
{
	while(t[target - 1] != target)
	{
		if(right)
		{
			std::swap(t[p], t[p + 1]);
			++p;
		}
		else
		{
			std::swap(t[p], t[p - 1]);
			--p;
		}
		++count;
	}
}

int swapping(std::vector<unsigned short>& t)
{
	unsigned int len(t.size());
	unsigned int max(len);
	unsigned int min(1);
	unsigned int count(0);
	unsigned int maxtimes(len/2 + len%2);
	unsigned int i(0);
	while (i++ < maxtimes)
	{
		std::vector<unsigned short>::iterator imax(std::find(t.begin(), t.end(), max));
		unsigned short pmax = imax - t.begin();
		toPos(t, pmax, t[pmax], true, count);
		std::vector<unsigned short>::iterator imin(std::find(t.begin(), t.end(), min));
		unsigned short pmin = imin - t.begin();
		toPos(t, pmin, t[pmin], false, count);
		--max;
		++min;
	}
	return count;
}

int main()
{
	unsigned int it;
	std::cin >> it;
	for(unsigned int i = 0; i < it; ++i)
	{
		unsigned short l;
		std::cin >> l;
		std::vector<unsigned short> t(l);
		for(int j = 0; j < l; ++j)
		{
			std::cin >> t[j];
		}
		std::cout << "Optimal train swapping takes " << swapping(t) << " swaps." << std::endl;
	}
	return 0;
}