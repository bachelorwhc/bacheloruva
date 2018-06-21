#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

int main()
{
    std::string name1, name2;
    auto calculate_socre = [ = ]( const std::string& name )
    {
        int ret{ 0 };
        for ( auto c : name )
        {
            if ( isalpha( c ) )
            {
                if ( isupper( c ) )
                    ret += c - 'A' + 1;
                else
                    ret += c - 'a' + 1;
            }
        }
        return ret;
    };
    auto to_one_digit = [ = ]( const int number )
    {
        auto number_str = std::to_string( number );
        int ret{ 0 };
        for ( auto c : number_str )
        {
            ret += ( c - '0' );
        }
        return ret;
    };
    while ( std::getline( std::cin, name1 ) && std::getline( std::cin, name2 ) )
    {
        int a{ calculate_socre( name1 ) };
        int b{ calculate_socre( name2 ) };
        while ( a / 10 > 0 )
            a = to_one_digit( a );
        while ( b / 10 > 0 )
            b = to_one_digit( b );
        float ans{ 0.0f };
        if ( a < b )
            ans = a / ( float )b;
        else
            ans = b / ( float )a;
        std::cout << std::setprecision( 2 ) << std::fixed << ans * 100 << " %" << std::endl;
    }
    return 0;
}