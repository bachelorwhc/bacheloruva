#include <iostream>

int main()
{
    unsigned long long map[ 51 ];
    map[ 1 ] = 1;
    map[ 2 ] = 2;
    map[ 3 ] = 3;
    for ( int i = 4; i <= 50; ++i )
    {
        map[ i ] = map[ i - 1 ] + map[ i - 2 ];
    }
    int n;
    while ( std::cin >> n )
    {
        if ( n == 0 )
            break;
        std::cout << map[ n ] << std::endl;
    }
    return 0;
}