#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
    int n;
    while ( std::cin >> n )
    {
        for ( int in = 0; in < n; ++in )
        {
            std::vector<long long> tri( 3 );
            for ( int i = 0; i < 3; ++i )
                std::cin >> tri[ i ];
            std::sort( tri.begin(), tri.end() );

            std::cout << "Case " << in + 1 << ": ";

            auto twoside = tri[ 0 ] + tri[ 1 ];
            if ( twoside <= tri[ 2 ] || tri[ 0 ] <= 0 || tri[ 1 ] <= 0 || tri[ 2 ] <= 0 )
            {
                std::cout << "Invalid";
            }
            else if ( twoside == tri[ 2 ] * 2 )
            {
                std::cout << "Equilateral";
            }
            else if ( tri[ 0 ] != tri[ 1 ] && tri[ 1 ] != tri[ 2 ] )
            {
                std::cout << "Scalene";
            }
            else
            {
                std::cout << "Isosceles";
            }

            std::cout << std::endl;
        }
    }
    return 0;
}