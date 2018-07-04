#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <set>
#include <numeric>
#ifdef _DEBUG
#include <fstream>
#endif

int main()
{
#ifdef _DEBUG
    std::ofstream file( "ans.txt" );
#endif

    int set;
    std::cin >> set;
    for ( int _s = 0; _s < set; ++_s )
    {
        int n;
        std::cin >> n;
        std::list<int> coins;
        for ( int i = 0; i < n; ++i )
        {
            int input;
            std::cin >> input;
            coins.push_front( input );
        }
        coins.sort();
        const int total = std::accumulate( coins.begin(), coins.end(), 0 );

        std::vector<int> table( n + 1, total );
        std::vector<int> rhs( n + 1 );

        int ans{ std::numeric_limits<int>::max() };
        for ( int i = 1; i < n; ++i )
        {
            int min{ std::numeric_limits<int>::max() };
            int curr = rhs[ i - 1 ];
            decltype( coins.begin() ) take = coins.end();
            int diff = -1;
            for ( auto it = coins.begin(); it != coins.end(); ++it )
            {
                int add = table[ i - 1 ] - *it;
                diff = std::abs( total - add - add );
                if( diff < min ) {
                    min = diff;
                    take = it;
                }
            }
            if ( min < ans )
                ans = min;
            rhs[ i ] = *take + curr;
            table[ i ] = table[ i - 1 ] - *take;
            auto prev_diff = std::abs( rhs[ i - 1 ] - table[ i - 1 ] );
            if ( min == 0 || min > prev_diff ) break;
            if( take != coins.end() )
                coins.erase( take );
        }

        std::cout << ans << std::endl;
#ifdef _DEBUG
        file << ans << std::endl;
#endif
    }
#ifdef _DEBUG
    file.close();
#endif
    return 0;
}