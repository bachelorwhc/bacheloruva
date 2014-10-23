#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int main()
{
	std::string s;
	while (std::cin >> s, s != "#")
		std::cout << (std::next_permutation(s.begin(), s.end()) ? s: "No Successor") << std::endl;
	return 0;
}