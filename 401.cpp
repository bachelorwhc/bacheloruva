#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
const char m[35] =
{
	'A', 0, 0, 0, '3', 'F', 'G', 'H', 'I', 'L', 0, 'J', 
	'M', 0, 'O', 0, 0, 0, '2', 'T', 'U', 'V', 'W', 'X', 
	'Y', '5', '1', 'S', 'E', 0, 'Z', 0, 0, '8', 0
};

bool IsMirroredChar(const char c)
{
	if(isdigit(c))
	{
		if(m[26 + c - '1'] != 0)
			return true;
	}
	else
	{
		if(m[c - 'A'] != 0)
			return true;
	}
}

bool IsMirroredString(const std::string& s)
{
	bool result(true);
	unsigned int len(s.length());
	if(len % 2 == 1)
		if(s[len / 2] == 'A' || s[len / 2] == 'H' || s[len / 2] == 'I' || s[len / 2] == 'M' || s[len / 2] == 'O' || 
			s[len / 2] == 'T' || s[len / 2] == 'U' || s[len / 2] == 'V' || s[len / 2] == 'W' || s[len / 2] == 'X' ||
			s[len / 2] == 'Y' || s[len / 2] == '1' || s[len / 2] == '8')
			result = true;
		else
			return false;
	for(unsigned int i = 0; i < len / 2; ++i)
	{
		if(!(IsMirroredChar(s[i]) && IsMirroredChar(s[len - i - 1])))
			return false;

		char m_of_r;
		if(isdigit(s[len - i - 1]))
			m_of_r = m[26 + (s[len - i - 1]) - '1'];
		else
			m_of_r = m[(s[len - i - 1]) - 'A'];

		if(isdigit(s[i]))
		{
			if(s[i] == m_of_r)
				continue;
			else
				return false;
		}
		else
		{
			if(s[i] == m_of_r)
				continue;
			else
				return false;
		}
	}
	return result;
}

int main()
{
	std::string s;
	while (std::cin >> s)
	{
		std::string r(s);
		std::reverse(r.begin(), r.end());
		bool palindrome(false);
		if(r == s)
			palindrome = true;
		bool mirrored(IsMirroredString(s));
		if(mirrored && palindrome)
			std::cout << s << " -- is a mirrored palindrome." << std::endl;
		else if(mirrored)
			std::cout << s << " -- is a mirrored string." << std::endl;
		else if(palindrome)
			std::cout << s << " -- is a regular palindrome." << std::endl;
		else
			std::cout << s << " -- is not a palindrome." << std::endl;
		std::cout << std::endl;
	}
	return 0;
}