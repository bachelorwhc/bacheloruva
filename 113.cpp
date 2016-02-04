#include <iostream>
#include <cmath>

struct BigInterger {

};

int main()
{
	int n, base;
	while(std::cin >> base >> n)
        std::cout << log10(n)/log10(base) << std::endl;
	return 0;
}
