#include <iostream>
#include <vector>

struct BOOLEAN
{
	BOOLEAN() : is(false) {};
	bool is;
	char a[3];
	BOOLEAN& operator= (bool boolean)
	{
		is = boolean;
		return *this;
	}
};

bool Final13(unsigned int N, unsigned int m)
{
	std::vector<BOOLEAN> table(N);
	table[1 - 1] = true;
	unsigned int count(1);
	for(unsigned int number = 1 + m; count < N;)
	{
		if(table[number - 1].is)
		{
			while (table[number - 1].is)
			{
				++number;
				if(number >= N)
					number = number - N;
			}	
		}

		table[number - 1].is = true;
		++count;

		if(number == 13)
		{
			if(count == N)
				return true;
			else
				return false;
		}

		for(unsigned int shift = 0; shift < m;)
		{
			if(number >= N)
			{
				number -= N;
			}
			if(table[number].is)
			{
				++number;
				continue;
			}
			else
			{
				++shift;
				++number;
			}
		}
	}
	return false;
}


int main()
{
	unsigned int N;
	while (std::cin >> N, N != 0)
	{
		for(unsigned int m = 1;;++m)
		{
			if(Final13(N, m))
			{
				std::cout << m << std::endl;
				break;
			}
		}
	}
	return 0;
}