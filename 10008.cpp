#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#define ANUM 26
#define ISIZE 10001

struct A
{
	A() : n(0), _char(0) {};
	unsigned int n;
	char _char;
};

bool operator<(const A& lhs, const A& rhs)
{
	if(lhs.n == rhs.n)
		if(lhs._char < rhs._char)
			return false;
		else
			return true;
	if(lhs.n < rhs.n)
		return true;
	return false;
}

int main()
{
	std::vector<A> dic(26);
	unsigned int t;
	std::string s;
	for(unsigned short i = 0; i < ANUM; ++i)
	{
		dic[i]._char = 'A' + i;
		dic[i].n = 0;
	}

    std::cin >> t;
    std::cin.ignore();
    while(t--)
    {
		std::getline(std::cin, s);
		
		for(unsigned int i = 0; i < s.length(); ++i)
		{
			if(isalpha(s[i]))
			{
				++dic[(isupper(s[i]) ? s[i] : (s[i] - 32)) - 'A'].n;
			}
		}
	}
	std::sort(dic.begin(), dic.end());
	std::reverse(dic.begin(), dic.end());
	for(unsigned short i = 0; i < ANUM; ++i)
	{
		if(dic[i].n != 0)
			printf("%c %u\n", dic[i]._char, dic[i].n);
	}
	return 0;
}