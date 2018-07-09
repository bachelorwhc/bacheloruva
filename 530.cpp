#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#ifdef _DEBUG
#include <fstream>
#endif

const int max = 10000;
int table[ max ];

void build_table()
{
    int i = sizeof( table );
    for ( int i = 0; i < max; ++i )
        table[ i ] = 1;
    for ( int i = 2; i < max; ++i )
    {
        if ( table[ i ] == 0 )
            continue;
        for ( int j = 2; i * j < max; ++j )
            table[ i * j ] = 0;
    }
}

int main()
{
    build_table();
    int m, n;
    while ( std::cin >> m >> n && !( m == 0 && n == 0 ) )
    {
        std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>> dqueue;
        std::priority_queue<uint64_t> aqueue;
        uint64_t pm{ 1 };
        for ( uint64_t i = n + 1; i <= m; ++i )
        {
            if ( table[ i ] )
                pm *= i;
            else
                dqueue.push( i );
        }
        uint64_t npm{ 1 };
        for ( uint64_t i = 2; i <= n; ++i )
        {
            if ( table[ i ] )
                npm *= i;
            else
                aqueue.push( i );
        };
        //ans /= _n;
        std::cout << pm << ' ' << npm << std::endl;
    }
    return 0;
}