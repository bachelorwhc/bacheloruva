#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#ifdef _DEBUG
#include <fstream>
#endif
const int COIN_TYPE_COUNT = 11;
const int BASE_UNIT = 5;
const int MAX_AMOUNT = 30000;
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

int main()
{
    int before, after;
    char dot;

#ifdef _DEBUG
    std::ofstream file( "ans.txt" );
#endif

    std::vector<unsigned long long> table;
    table.reserve( MAX_AMOUNT / BASE_UNIT + 1 );

    auto GetCombination = [ &table ]( int amount )
    {
        table.clear();
        amount /= BASE_UNIT;
        table.resize( amount + 1 );
        for ( auto& t : table )
            t = 1;
        table[ 0 ] = 0;
        for ( int i = 1; i < COIN_TYPE_COUNT; ++i )
        {
            const int coin = MAP[ i ] / BASE_UNIT;
            if ( coin > amount )
                break;
            ++table[ coin ];
            for ( int j = coin; j <= amount; ++j )
            {
                table[ j ] = table[ j - coin ] + table[ j ];
            }
        }
        return table[ amount ];
    };

    GetCombination( MAX_AMOUNT );

    while ( std::cin >> before >> dot >> after )
    {
        int amount = before * 100 + after;
        if ( amount == 0 )
            break;
        float print = amount / 100.f;
        std::cout << std::setw( 6 ) << std::fixed << std::setprecision( 2 ) << print << std::setw( 17 ) << table[ amount / BASE_UNIT ] << std::endl;
#ifdef _DEBUG
        file << std::setw( 6 ) << std::fixed << std::setprecision( 2 ) << print << std::setw( 17 ) << table[ amount / BASE_UNIT ] << std::endl;
#endif
    }
#ifdef _DEBUG
    file.close();
#endif
    return 0;
}