#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>

int main() {
	int n_of_i;
	std::cin >> n_of_i;
	char bufferd[16];
	char bufferh[16];
	for (int i = 0; i < n_of_i; ++i) {
		std::string nstr;
		std::cin >> nstr;
		std::string d{ std::bitset<16>(std::stoi(nstr, nullptr, 10)).to_string() };
		std::string h{ std::bitset<16>(std::stoi(nstr, nullptr, 16)).to_string() };
		int a = 0;
		int b = 0;
		for (auto c : d)
			if (c == '1')
				++a;
		for (auto c : h)
			if (c == '1')
				++b;
		std::cout << a << " " << b << std::endl;
	}
	return 0;
}

