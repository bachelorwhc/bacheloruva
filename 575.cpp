#include <iostream>
#include <string>
#include <cmath>

int main()
{
	std::string s;
	while (std::cin >> s, s!="0")
	{
		unsigned int len = s.length();
		unsigned long ans = 0;
		for (int i = len - 1; i >= 0; --i)
		{
			unsigned int b(pow(2, len - i));
			ans += (s[i] - '0') * (b - 1);
		}
		std::cout << ans << std::endl;
	}
	return 0;
}