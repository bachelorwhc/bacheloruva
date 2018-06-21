#include <iostream>
#include <bitset>

int main()
{
    int n;
    while ( std::cin >> n && n > 0)
    {
        std::string bs = std::bitset< 64 >( n ).to_string();
        int sum{ 0 };
        int first{ -1 };
        int count{ 0 };
        for ( auto c : bs ) 
        {
            if( c == '1' ) 
            {
                sum += 1;
                if ( first < 0 )
                    first = count;
            }
            ++count;
        }
        std::string output( bs.c_str() + first );
        std::cout << "The parity of " << output << " is " << sum << " (mod 2)." << std::endl;
    }
    return 0;
}