#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
const int COIN_TYPE_COUNT = 11;

int MAP[ COIN_TYPE_COUNT ] =
{
    5,
    10,
    20,
    50,
    100,
    200,
    500,
    1000,
    2000,
    5000,
    10000
};

const std::map<int, int> R_MAP =
{
    {5, 0}, { 10, 1 }, { 20, 2 }, { 50, 3 }, { 100, 4 }, { 200, 5 }, { 500, 6 }, { 1000, 7 }, { 2000, 8 }, { 5000, 9 }, { 10000, 10 },
};

int GetCombination( int n )
{
    //
    //( n, 1 );
    for ( int i = 0; i < n; ++i )
    {
        
    }
    return 0;
}

int main()
{
    int before, after;
    char dot;

    std::vector<int> table;
    table.reserve( 30001 );

    auto GetCombination = [ &table ]( int amount )
    {
        table.clear();
        table.resize( amount + 1 );
        for ( int i = 0; i < COIN_TYPE_COUNT; ++i )
        {
            const int coin = MAP[ i ];
            for ( int j = amount; j >= coin; --j )
            {
                table[ j ] = ( j / coin ) * table[ coin ] + table[ j % coin ] + 1;
            }
        }
        return table[ amount ];
    };

    while ( std::cin >> before >> dot >> after )
    {
        int amount = before * 100 + after;
        if ( amount == 0 )
            break;
        GetCombination( amount );
    }
    return 0;
}