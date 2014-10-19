#include <iostream>
#include <string>
char cstr[1000] = {0};
std::string plus(std::string& lhs, std::string& rhs)
{
	int len_of_lhs(lhs.length());
	int len_of_rhs(rhs.length());
	int base(len_of_lhs < len_of_rhs ? len_of_lhs : len_of_rhs);
	int newlen(len_of_lhs > len_of_rhs ? len_of_lhs : len_of_rhs);
	std::string longstr(len_of_lhs > len_of_rhs ? lhs : rhs);

	for(int i = 0; i <= newlen; ++i)
		cstr[i] = '\0';
	bool carry(false);
	for(int i = 0; i < base; ++i)
	{
		int ln(lhs[len_of_lhs - i -1] - '0');
		int rn(rhs[len_of_rhs - i -1] - '0');
		cstr[newlen - i -1] = ((ln + rn + (carry ? 1 : 0)) % 10) + '0';
		carry = (ln + rn + (carry ? 1 : 0)) > 9 ? true : false;
	}
	for(int i = newlen - base - 1; i >= 0; --i)
	{
		int n(longstr[i] - '0');
		cstr[i] = (char)((n + (carry ? 1 : 0)) % 10) + '0';
		carry = (n + (carry ? 1 : 0)) > 9 ? true : false;
	}
	std::string result(cstr);
	if(carry)
		result.insert(result.begin(), '1');
	lhs = result;
}

int main()
{
	std::string ans = "0";
	std::string input;
	while(std::cin >> input, input != "0")
	{
		plus(ans, input);
	}
	std::cout << ans << std::endl;
	return 0;
}