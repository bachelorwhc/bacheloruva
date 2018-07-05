#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdint>
#ifdef _DEBUG
#include<fstream>
#endif

const uint32_t MAX_HALF = 214748364 / 2;
bool raw_table_l[ MAX_HALF + 1 ];
bool raw_table_r[ MAX_HALF + 1 ];
std::vector<int32_t> table;

void build_table()
{
    for ( int i = 0; i <= MAX_HALF; ++i ) {
        raw_table_l[ i ] = true;
        raw_table_r[ i ] = true;
    }
    for ( uint32_t i = 2; i <= MAX_HALF * 2; ++i )
    {
        auto p_raw_table = i > MAX_HALF ? raw_table_r : raw_table_l;
        auto base = i > MAX_HALF ? MAX_HALF : 0;
        if ( false == p_raw_table[ i - base ] )
            continue;
        for ( uint32_t j = 2; i * j < MAX_HALF * 2; ++j ) 
        {
            auto base = ( i * j ) > MAX_HALF ? MAX_HALF : 0;
            auto p_raw_table = ( i * j ) > MAX_HALF ? raw_table_r : raw_table_l;
            p_raw_table[ i * j - base ] = false;
        }
    }
    for ( uint32_t i = 2; i <= MAX_HALF; ++i )
    {
        if ( raw_table_l[ i ] )
            table.push_back( i );
    }
    for ( uint32_t i = 2; i <= MAX_HALF; ++i )
    {
        if ( raw_table_r[ i ] )
            table.push_back( i + MAX_HALF );
    }
}

int main()
{
    build_table();
    int n;
    while ( std::cin >> n && n != 0 )
    {
        std::cout << n << " = ";
        if ( n < 0 )
        {
            std::cout << "-";
            n = -n;
        }
        std::cout << "1";
        if ( n <= MAX_HALF && raw_table_l[ n ] )
        {
            std::cout << " x " << n;
        }
        else if ( n > MAX_HALF && raw_table_r[ n - MAX_HALF ] )
        {
            std::cout << " x " << n;
        }
        else
        {
            for ( auto p : table )
            {
                if ( p > n )
                    break;
                int r = n % p;
                if ( 0 == r )
                {
                    std::cout << " x " << p;
                    n /= p;
                    r = n % p;
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}