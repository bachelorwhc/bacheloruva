#include <iostream>
#include <cmath>

int main()
{
    int input;
    int count{ 0 };
    while ( std::cin >> input )
    {
        if ( input < 0 )
            return 0;
        ++count;
        std::cout << "Case " << count << ": " << ceil( log2( input ) ) << std::endl;
    }
    return 0;
}