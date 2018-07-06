#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdint>
#ifdef _DEBUG
#include<fstream>
#endif

const int32_t MAX = 65536;
bool raw_table[ MAX + 1 ];
std::vector<int32_t> table;

void build_table()
{
    for ( int i = 0; i <= MAX; ++i ) {
        raw_table[ i ] = true;
    }
    for ( uint32_t i = 2; i <= MAX; ++i )
    {
        if ( false == raw_table[ i ] )
            continue;
        for ( uint32_t j = 2; i * j < MAX; ++j )
        {
            raw_table[ i * j ] = false;
        }
    }
    for ( uint32_t i = 2; i <= MAX; ++i )
    {
        if ( raw_table[ i ] )
            table.push_back( i );
    }
}

int main()
{
    build_table();
    int n;
#ifdef _DEBUG
    std::ofstream file( "ans.txt" );
#endif
    
    while ( std::cin >> n && n != 0 )
    {
        std::vector<int> prime_factors;
#ifdef _DEBUG
        file << n << " = ";
#endif
        std::cout << n << " = ";
        bool one_exist = false;
        if ( n < 0 )
        {
            prime_factors.push_back( -1 );
            n = -n;
            one_exist = true;
        }
        if ( n <= MAX && raw_table[ n ] )
        {
            prime_factors.push_back( n );
        }
        else
        {
            bool is_prime = true;
            for ( auto p : table )
            {
                if ( p > n )
                    break;
                int r = n % p;
                while ( 0 == r && n != 1 )
                {
                    is_prime = false;
                    prime_factors.push_back( p );
                    n /= p;
                    r = n % p;
                }
            }
            if( is_prime ) {
                prime_factors.push_back( n );
            }
        }
#ifdef _DEBUG
        file << prime_factors[ 0 ];
#endif
        std::cout << prime_factors[0];
        for ( int i = 1; i < prime_factors.size(); ++i )
        {
#ifdef _DEBUG
            file << " x " << prime_factors[ i ];
#endif
            std::cout << " x " << prime_factors[ i ];
        }
#ifdef _DEBUG
        file << std::endl;
#endif
        std::cout << std::endl;
    }
#ifdef _DEBUG
    file.close();
#endif
    return 0;
}