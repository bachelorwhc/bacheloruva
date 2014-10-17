#include <iostream>
#include <string>

struct Number
{
	std::string n;
	unsigned int getLength() const
	{
		return n.length();
	}
};

int cToNumber(const char c)
{
	return c - '0';
}

unsigned int operator+(const Number& lhs, const Number& rhs)
{
	unsigned int ll = lhs.getLength();
	unsigned int rl = rhs.getLength();
	int bl = ll > rl ? rl : ll;
	bool isL = ll > rl ? true : false;
	unsigned short carryReturn = 0;
	bool isC(false);
	for(int i = 0; i < bl; ++i)
	{
		int c = isC ? 1 : 0;
		if(cToNumber(lhs.n[ll-i-1]) + cToNumber(rhs.n[rl-i-1]) + c > 9)
		{
			++carryReturn;
			isC = true;
		}
		else
			isC = false;
	}
	Number restN = isL ? lhs : rhs;
	for(int i = bl; i < restN.getLength(); ++i)
	{
		int c = isC ? 1 : 0;
		if(cToNumber(restN.n[restN.getLength() - i - 1]) + c > 9)
		{
			++carryReturn;
			isC = true;
		}
		else
			isC = false;
	}
	return carryReturn;
}

int main()
{
	Number a, b;
	while (std::cin >> a.n >> b.n)
	{
		if(a.n == "0" && b.n == "0")
			return 0;
		unsigned int r(a + b);
		if(r == 0)
			std::cout << "No carry operation." << std::endl;
		else if(r == 1)
			std::cout << "1 carry operation." << std::endl;
		else
			std::cout << r << " carry operations." << std::endl;
	}
	return 0;
}