#include <iostream>
#include <cstdint>

int main()
{
    uint64_t n;
    while ( std::cin >> n )
    {
        uint64_t row = n / 2 + 1;
        std::cout << (( n + 1 ) * row - 1) * 3 - 6 << std::endl;
    }
    return 0;
}