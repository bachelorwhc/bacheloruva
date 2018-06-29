#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <cstdint>

int main()
{
    int digit;
    while ( std::cin >> digit )
    {
        int d = digit / 2;
        int64_t range = pow( 10, d );
        for ( int64_t i = 0; i < range; ++i )
        {
            int64_t square = i * i;
            auto str = std::to_string( square );
            std::string pad( digit - str.size(), '0' );
            str = pad + str;
            std::string lr( str.begin(), str.begin() + d );
            std::string rr( str.begin() + d, str.end() );
            auto lhs = strtol( lr.c_str(), nullptr, 10 );
            auto rhs = strtol( rr.c_str(), nullptr, 10 );
            int64_t n = lhs + rhs;
            if ( n * n == square )
                std::cout << lr << rr << std::endl;
        }
    }
    return 0;
}