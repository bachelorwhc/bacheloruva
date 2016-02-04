#include <iostream>
#include <algorithm>
#include <vector>
#define FIND_RANGE 1000000

struct BOOLEAN
{
    BOOLEAN() : is(true) {};
    bool is;
    char a[3];
};

std::vector<BOOLEAN> table(FIND_RANGE);
std::vector<unsigned int> prime_table;

void ContstructTable()
{
    for(unsigned int i = 2; i <= FIND_RANGE; ++i)
    {
        if(table[i - 1].is)
        {
            prime_table.push_back(i);
            for(unsigned int d = i + i; d <= FIND_RANGE; d+=i)
            {
                table[d - 1].is = false;
            }
        }
    }
}

int main()
{
    ContstructTable();
    unsigned int n;
    while(std::cin >> n, n != 0)
    {
        unsigned int check(0);
        unsigned int front_n(0);
        unsigned int back_n(0);
		unsigned int front(0);
		unsigned int back(0);
        bool exist(false);

        for(back_n = 0; back_n < prime_table.size(); ++back_n)
        {
            if(prime_table[back_n] < (n - 2))
			{
				if(table[n - prime_table[back_n] - 1].is && (n - prime_table[back_n]) % 2 == 1)
					back = prime_table[back_n];
			}
			if(prime_table[back_n] >= n - 2)
				break;
        }

        for(front_n = 0; front_n < back_n; ++front_n)
        {
            if(back + prime_table[front_n] == n)
			{
                exist = true;
				front = prime_table[front_n];
				break;
			}
        }
        if(exist)
			std::cout << n << " = " << front << " + " << back << std::endl;
        else
            std::cout << "Goldbach's conjecture is wrong." << std::endl;
    }
	return 0;
}
