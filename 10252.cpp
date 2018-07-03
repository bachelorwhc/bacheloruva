#include <iostream>
#include <string>
#include <map>
#include <algorithm>

void CreateMap( std::map<char, int>& map )
{
    for ( char c = 'a'; c <= 'z'; ++c )
        map[ c ] = 0;
}

int main()
{
    std::string first, second;
    while ( std::getline(std::cin, first) && std::getline( std::cin, second ) )
    {
        std::map<char, int> m1;
        std::map<char, int> m2;
        std::map<char, int> table;
        CreateMap( m1 );
        CreateMap( m2 );
        std::for_each( first.begin(), first.end(), [ &m1 ]( char c ) { ++m1[ c ]; } );
        std::for_each( second.begin(), second.end(), [ &m2 ]( char c ) { ++m2[ c ]; } );
        for ( char c = 'a'; c <= 'z'; ++c )
            table[ c ] = std::min( m1[ c ], m2[ c ] );
        for ( char c = 'a'; c <= 'z'; ++c )
            for ( int i = 0; i < table[ c ]; ++i )
                std::cout << c;
        std::cout << std::endl;
    }
    return 0;
}