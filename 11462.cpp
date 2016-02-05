#include <iostream>
#include <cstdio>
#include <map>

int main() {
	unsigned long n_of_i;
	bool first = true;
	while (std::cin >> n_of_i) {
		if (n_of_i == 0) {
			break;
		}
		std::map<unsigned short, unsigned int> age;
		unsigned short input;
		unsigned int n_of_a = 0;
		for (int i = 0; i < n_of_i; ++i) {
			std::cin >> input;
			++n_of_a;
			if (age.count(input) > 0)
				++age[input];
			else
				age[input] = 1;
		}

		for (int i = 1; i <= 100; ++i) {
			if (age.count(i) > 0) {
				for (int j = 0; j < age[i]; ++j) {
					--n_of_a;
					printf("%d", i);
					if(n_of_a > 0)
						printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}