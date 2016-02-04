#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
const int PRIME_NUMBER = 25;
const int MAX_NUMBER = 100;
const unsigned long prime[PRIME_NUMBER] = {
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
};

bool is_prime[MAX_NUMBER];

int main() {
	for (int i = 0; i < MAX_NUMBER; ++i)
		is_prime[i] = false;
	for (int i = 0; i < PRIME_NUMBER; ++i)
		is_prime[prime[i]] = true;

	int number;
	while (std::cin >> number && number != 0) {
		std::map<int, int> pf;
		printf("%3d! =", number);
		int n_of_pf = 0;
		for (int i = 0; number - i > 1; ++i) {
			int numbercopy(number - i);
			for (int pi = 0; pi < PRIME_NUMBER; ++pi) {
				while (numbercopy % prime[pi] == 0) {
					if (pf.count(prime[pi]) == 0) {
						pf[prime[pi]] = 1;
						++n_of_pf;
					}
					else
						++pf[prime[pi]];
					numbercopy /= prime[pi];
				}
			}
		}
		int line = n_of_pf / 15 + (n_of_pf % 15 == 0 ? 0 : 1) ; // boring constraint.
		int current_line = 1;
		int print = 0;
		for (int pi = 0; pi < PRIME_NUMBER; ++pi) {
			if (print > 14 && print % 15 == 0 && current_line++ < line)
				std::cout << "\n      ";
			if (pf.count(prime[pi]) > 0) {
				printf("%3d", pf[prime[pi]]);
				++print;
			}
		}
		std::cout << std::endl;
	}
	return 0;
}