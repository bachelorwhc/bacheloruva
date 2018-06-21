#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

const int max = 100000;
int raw_table[ max ];
std::vector<int> table;

void build_table()
{
    int i = sizeof( raw_table );
    for ( int i = 0; i < max; ++i )
        raw_table[ i ] = 1;
    for ( int i = 2; i < max; ++i )
    {
        if ( raw_table[ i ] == 0 )
            continue;
        for ( int j = 2; i * j < max; ++j )
            raw_table[ i * j ] = 0;
    }
    for ( int i = 2; i < max; ++i )
    {
        if ( raw_table[ i ] == 0 )
            continue;
        table.push_back( raw_table[ i ] );
    }
}

void find_maximum_divisors( int min, int max, int& ans, int& divisor_count )
{
    divisor_count = 0;
    ans = 0;
    for ( int i = min; i <= max; ++i )
    {
        int c_divisor_count{ 0 };

        for ( auto p : table )
        {
            if(  )
        }

        if ( i > ans && c_divisor_count >= divisor_count )
        {
            divisor_count = c_divisor_count;
            ans = i;
        }
    }
}

int main()
{
    build_table();
    int n;
    std::cin >> n;
    for ( int i = 0; i < n; ++i )
    {
        int min, max;
        std::cin >> min >> max;
        int ans, divisor_count;
        find_maximum_divisors( min, max, ans, divisor_count );
        std::cout << ans << " " <<  divisor_count << std::endl;
    }
    return 0;
}