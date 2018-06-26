#include <iostream>
#include <vector>
#include <cstring>
const int max = 501;
int table[ max ];
unsigned long map[ max ][ max ];

void build_table()
{
    int i = sizeof( table );
    for ( int i = 0; i < max; ++i )
        table[ i ] = 1;
    for ( int i = 2; i < 501; ++i )
    {
        if ( table[ i ] == 0 )
            continue;
        for ( int j = 2; i * j < max; ++j )
            table[ i * j ] = 0;
    }
}

int find_gcd( int lhs, int rhs )
{
    if ( table[ lhs ] && table[ rhs ] )
        return 1;
    else if ( table[ lhs ] && rhs % lhs == 0 )
        return lhs;
    else if ( table[ lhs ] )
        return 1;
    else if ( table[ rhs ] )
        return 1;
    else
    {
        int gcd = lhs;
        int d = rhs;
        while ( d % gcd > 0 )
        {
            auto temp = gcd;
            gcd = d % gcd;
            d = temp;
        }
        return gcd;
    }
    return 0;
}

int main()
{
    memset( map, 0, sizeof( map ) );
    build_table();
    int n;
    while ( std::cin >> n )
    {
        if ( n == 0 )
            break;

        int sum{ 0 };
        for ( int i = 1; i < n; ++i )
        {
            for ( int j = i + 1; j <= n; ++j )
            {
                if ( map[ i ][ j ] == 0 )
                    map[ i ][ j ] = find_gcd( i, j );
                sum += map[ i ][ j ];
            }
        }
        std::cout << sum << std::endl;
    }
    return 0;
}