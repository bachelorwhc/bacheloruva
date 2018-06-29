#include <iostream>
#include <vector>
#include <string>

int main()
{
    int set;
    std::cin >> set;
    for ( int i = 0; i < set; ++i )
    {
        int n;
        std::cin >> n;
        std::vector<int> m( 10 );
        for ( int j = 1; j <= n; ++j )
        {
            const auto&& str = std::to_string( j );
            for ( auto c : str )
            {
                ++m[ c - '0' ];
            }
        }
        for ( int j = 0; j < 10; ++j )
        {
            std::cout << m[ j ];
            if( j < 9)
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}