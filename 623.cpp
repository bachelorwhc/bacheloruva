#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#ifdef _DEBUG
#include <fstream>
#endif
const int DIGI_MAX = 4;
const int BASE_UNIT = 10000;

struct BigNumber
{
    BigNumber() : _ns( 1 ) {};
    BigNumber( const std::string& str ) {
        auto length = str.size();
        for ( int i = 0; i < length; i+=DIGI_MAX )
        {
            auto end = ( i + DIGI_MAX ) >= length ? str.rend() : ( str.rbegin() + i + DIGI_MAX );
            std::string s( str.rbegin() + i, end );
            std::reverse( s.begin(), s.end() );
            auto p = s.c_str();
            _ns.push_back( strtol( p, nullptr, 10 ) );
        }
    };

    std::string to_string()
    {
        std::string ret;
        for ( auto it = _ns.rbegin(); it != _ns.rend(); ++it )
        {
            if ( it == _ns.rbegin() )
                ret += std::to_string( *it );
            else
            {
                auto nstr = std::to_string( *it );
                std::string pad( DIGI_MAX - nstr.size(), '0' );
                ret += pad + nstr;
            }   
        }
        return ret;
    }

    BigNumber& operator*=( const BigNumber& rhs )
    {
        *this = *this * rhs;
        return *this;
    }

    BigNumber operator*( const BigNumber& rhs ) const
    {
        BigNumber ret;
        auto l_length = _ns.size();
        auto r_length = rhs._ns.size();
        for ( int i = 0; i < l_length; ++i )
        {
            auto n = _ns[ i ];
            for ( int j = 0; j < r_length; ++j )
            {
                auto rn = rhs._ns[ j ];
                auto mn = n * rn;
                int curr{ i + j };
                while ( mn > 0 )
                {
                    if ( ret._ns.size() < ( curr + 1 ) )
                    {
                        int times = ( curr + 1 ) - ret._ns.size();
                        for ( int i = 0; i < times; ++i )
                            ret._ns.push_back( 0 );
                    }
                    ret._ns[ curr ] += mn % BASE_UNIT;
                    mn /= BASE_UNIT;
                    ++curr;
                }
                auto r{ 0 };
                for ( int k = i; k < ret._ns.size(); ++k )
                {
                    ret._ns[ k ] += r;
                    r = ret._ns[ k ] / BASE_UNIT;
                    ret._ns[ k ] = ret._ns[ k ] % BASE_UNIT;
                    if ( r > 0 && k + 1 == ret._ns.size() )
                    {
                        ret._ns.push_back( 0 );
                    }
                }
            }
        }
        return ret;
    }

    std::vector<int> _ns;
};

decltype( std::cout )& operator<<( decltype( std::cout )& _cout, BigNumber& big_n )
{
    for ( auto it = big_n._ns.rbegin(); it != big_n._ns.rend(); ++it )
    {
        if( it == big_n._ns.rbegin() )
            _cout << std::setw( 0 ) << *it;
        else
            _cout << std::setfill( '0' ) << std::setw( 4 ) << *it;
    }
    return _cout;
}

int main()
{
#ifdef _DEBUG
    std::ofstream file( "ans.txt" );
#endif
    std::map<int, std::string> factorials;
    int n;
    while ( std::cin >> n )
    {
        std::string ans( "1" );
        for ( int i = 2; i <= n; ++i )
        {
            if ( factorials.count( i ) > 0 )
            {
                ans = factorials.at(i);
            }
            else
            {
                BigNumber bn( std::to_string( i ) );
                bn *= BigNumber( ans );
                ans = bn.to_string();
                factorials[ i ] = ans;
            }
        }
#ifdef _DEBUG
        file << n << '!' << std::endl;
        file << ans << std::endl;
#endif
        std::cout << n << '!' << std::endl;
        std::cout << ans << std::endl;
    }
    return 0;
}