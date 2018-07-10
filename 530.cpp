#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#ifdef _DEBUG
#include <fstream>
#endif

const uint64_t max = 33554432;
bool table[ max ];

void build_table()
{
    int i = sizeof( table );
    for ( int i = 0; i < max; ++i )
        table[ i ] = true;
    for ( int i = 2; i < max; ++i )
    {
        if ( table[ i ] == 0 )
            continue;
        for ( int j = 2; i * j < max; ++j )
            table[ i * j ] = false;
    }
}

using g_priority_queue = std::priority_queue<uint64_t, std::vector<uint64_t>, std::greater<uint64_t>>;
int main()
{
    build_table();
    uint64_t m, n;
#ifdef _DEBUG
    std::ofstream file( "ans.txt" );
#endif
    while ( std::cin >> m >> n && !( m == 0 && n == 0 ) )
    {
        n = std::min( m - n, n );
        g_priority_queue m_nonprime_queue;
        g_priority_queue m_big_queue;
        std::priority_queue<uint64_t> d_prime_queue;
        std::priority_queue<uint64_t> d_nonprime_queue;
        uint64_t pm{ 1 };
        for ( uint64_t i = m - n + 1; i <= m; ++i )
        {
            if ( i >= max )
                if ( i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0 || i % 11 == 0 ||
                     i % 13 == 0 || i % 17 == 0 || i % 19 == 0 || i % 23 == 0 )
                    m_nonprime_queue.push( i );
                else
                    m_big_queue.push( i );
            else if ( table[ i ] )
                pm *= i;
            else
                m_nonprime_queue.push( i );
        }
        uint64_t npm{ 1 };
        for ( uint64_t i = 2; i <= n; ++i )
        {
            if ( table[ i ] )
                d_prime_queue.push( i );
            else
                d_nonprime_queue.push( i );
        };
        auto try_to_pop_all =[]( g_priority_queue& nonprime_queue, std::priority_queue<uint64_t>& d_queue )
        {
            while ( nonprime_queue.size() > 1 && d_queue.size() > 0 )
            {
                auto top = nonprime_queue.top();
                nonprime_queue.pop();
                auto dp = d_queue.top();
                if ( top % dp == 0 )
                {
                    top /= dp;
                    d_queue.pop();
                }
                else
                {
                    top *= nonprime_queue.top();
                    nonprime_queue.pop();
                }
                nonprime_queue.push( top );
            }
        };

        try_to_pop_all( m_nonprime_queue, d_nonprime_queue );
        try_to_pop_all( m_nonprime_queue, d_prime_queue );
        try_to_pop_all( m_big_queue, d_nonprime_queue );
        try_to_pop_all( m_big_queue, d_prime_queue );

        uint64_t ans{ pm };
        while ( m_nonprime_queue.size() )
        {
            ans *= m_nonprime_queue.top();
            m_nonprime_queue.pop();
        }
        while ( m_big_queue.size() )
        {
            ans *= m_big_queue.top();
            m_big_queue.pop();
        }
        while ( d_nonprime_queue.size() )
        {
            ans /= d_nonprime_queue.top();
            d_nonprime_queue.pop();
        }
        while ( d_prime_queue.size() )
        {
            ans /= d_prime_queue.top();
            d_prime_queue.pop();
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