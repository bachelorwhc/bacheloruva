#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <vector>

struct BigN
{
	std::string number;
	void Square()
	{
		const unsigned int len = number.length();
		std::vector<std::string> store(len);
		std::string::iterator end = number.end();
		std::string::iterator start = number.begin();
		unsigned short carry = 0;
		for (unsigned int i = 0; i < len; ++i)
		{
			for (unsigned int j = 0; j < len; ++j)
			{
				unsigned short n((number[len - i - 1] - '0') * (number[len - j - 1] - '0') + carry);
				carry = n / 10;
				store[i] += n % 10 + '0';
			}
			for (unsigned int k = 0; k < i; ++k)
				store[i].insert(store[i].begin(), '0');
		}
		if (carry > 0 && len == 1)
		{
			std::string newc; 
			newc += '0';
			newc += (char)carry + '0';
			store.push_back(newc);
		}
		for (unsigned int i = 0; i < store.size(); ++i)
			std::reverse(store[i].begin(), store[i].end());
		unsigned int new_size = store.size() + len -1;
		char* new_number = new char[new_size + 1];
		for (unsigned int i = 0; i <= new_size; ++i)
			new_number[i] = '\0';
		for (unsigned int i = 0; i < store.size(); ++i)
			for (unsigned int j = 0; j < store.size() - i - 1; ++j)
				store[i].insert(store[i].begin(), '0');
		unsigned int new_carry = 0;
		for (unsigned int ci = 0; ci < new_size; ++ci)
		{
			unsigned int n = new_carry;
			for (unsigned int si = 0; si < store.size(); ++si)
			{
				n += store[si][new_size - ci - 1] - '0';
			}
			new_number[new_size - ci - 1] = n % 10 + '0';
			new_carry = n / 10;
		}
		number = std::string(new_number);
		delete[] new_number;
		return;
	}
};

bool operator<(const BigN& lhs, const BigN& rhs)
{
	unsigned int rl = rhs.number.length();
	unsigned int ll = lhs.number.length();
	if (ll > rl || lhs.number == rhs.number)
		return false;
	if (ll < rl)
		return true;
	if (ll == rl)
	{
		for (unsigned int i = 0; i < ll; ++i)
		{
			if (lhs.number[i] <= rhs.number[i])
				continue;
			else
				return false;
		}
		return true;
	}
	return false;
}

int main()
{
	BigN base;
	BigN bn;
	while (std::cin >> base.number >> bn.number)
	{
		unsigned int ans = 0;
		while (base < bn)
		{
			base.Square();
			++ans;
		}
		std::cout << ans << std::endl;
	}
	return 0;
}