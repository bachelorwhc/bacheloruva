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

        int table_length = ( total + 1 ) / 2;
        std::vector<int> table( table_length + 1 );
        table[ 0 ] = 1;
        for ( const auto coin : coins )
            for ( int i = table_length; i >= coin; --i )
                table[ i ] = table[ i - coin ] || table[ i ];

        int mid = total / 2;
        while ( table[mid] == 0 )
        {
            --mid;
        }
        int ans = std::abs( total - 2 * mid );
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