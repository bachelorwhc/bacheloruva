#include <iostream>
#include <string>
#include <cstring>

int main() {
	std::string str;
	auto count = [](const std::string& c, const std::string& t) {
		int ret = 0;
		for (int i = 0; i < c.size(); ++i) {
			if (c[i] != t[i])
				++ret;
		}
		return ret;
	};
	while (std::cin >> str) {
		if(str.size() > 3) {
			std::cout << "3\n";
			continue;
		}
		int b1 = count(str, "one");
		int b2 = count(str, "two");
		if (b1 <= 1 && b1 >= 0) {
			std::cout << "1\n";
		}
		else if (b2 <= 1 && b2 >= 0) {
			std::cout << "2\n";
		}
	}
	return 0;
}