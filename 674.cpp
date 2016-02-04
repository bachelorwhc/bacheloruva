#include <iostream>

const unsigned short coin[5] = { 1, 5, 10, 25, 50 };


int main() {
	unsigned long p[7490];
	for (int i = 0; i < 7490; ++i)
		p[i] = 0;
	p[0] = 1;

	for (int i = 0; i < 5; ++i)
		for (int j = coin[i]; j <= 7489; ++j)
			p[j] += p[j - coin[i]];

	int cent;
	while (std::cin >> cent) {
		std::cout << p[cent] << std::endl;
	}
	return 0;
}