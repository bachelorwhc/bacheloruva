#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

int main()
{
    long long n;
    while ( std::cin >> n && n >= 0 )
    {
        std::vector<short> ans;
        while ( n > 0 )
        {
            ans.push_back( n % 3 );
            n /= 3;
        }
        if ( ans.empty() )
            ans.push_back( 0 );
        std::for_each( ans.rbegin(), ans.rend(), []( short n ) { std::cout << n; } );
        std::cout << std::endl;
    }
    return 0;
}