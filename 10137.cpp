#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <cmath>

int main()
{
    int n;
    while ( std::cin >> n )
    {
        if ( n == 0 )
            break;
        int sum{ 0 };
        std::vector<int> pays( n );
        for ( int i = 0; i < n; ++i )
        {
            float _pay;
            std::cin >> _pay;
            int pay = _pay * 100;
            sum += pay;
            pays[ i ] = pay;
        }
        int avg = sum / n;
        int remain = sum % n;
        int total{ 0 };
        int fill{ 0 };
        for ( auto p : pays )
        {
            if ( p < avg ) 
            {
                total += avg - p;
                ++fill;
            }
        }
        total += ( remain / fill ) * fill;
        std::cout << std::fixed << std::setprecision( 2 ) << total / 100.0f << std::endl;
    }
    return 0;
}