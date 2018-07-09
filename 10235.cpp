#include<iostream>
#include<string>
#include<algorithm>

const int max = 1000001;
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
        for( int j = 2; i * j < max; ++j )
            table[ i * j ] = 0;
    }
}

int main()
{
    build_table();
    std::string input;
    while ( std::cin >> input )
    {
        int n = std::stoi( input );
        if ( table[ n ] > 0 )
        {
            auto rev = input;
            std::reverse( rev.begin(), rev.end() );
            n = std::stoi( rev );
            if( rev != input && table[ n ] > 0 )
                std::cout << input << " is emirp." << std::endl;
            else 
                std::cout << input << " is prime." << std::endl;
        }
        else
        {
            std::cout << input << " is not prime." << std::endl;
        }
    }
    return 0;
}