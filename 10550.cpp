#include <iostream>
#include <cmath>

const int max = 40;

int clockwise( int start, int end )
{
    if ( start > end )
        return  max - start + end;
    else
        return end - start;
}

int counter_clockwise( int start, int end )
{
    return clockwise( end, start );
}

int main()
{
    const int least = 1080;
    const int unit = 9;
    int start, code[ 3 ];
    while ( std::cin >> start >> code[ 0 ] >> code[ 1 ] >> code[ 2 ] )
    {
        if ( start == 0 && code[ 0 ] == 0 && code[ 1 ] == 0 && code[ 2 ] == 0 )
        {
            return 0;
        }
        int ans{ 0 };
        int current{ start };

        ans += counter_clockwise( current, code[ 0 ] ) * unit;
        current = code[ 0 ];

        ans += clockwise( current, code[ 1 ] ) * unit;
        current = code[ 1 ];

        ans += counter_clockwise( current, code[ 2 ] ) * unit;
        current = code[ 2 ];

        std::cout << ans + least << std::endl;
    }
    return 0;
}