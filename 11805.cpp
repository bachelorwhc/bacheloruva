#include <iostream>

int main()
{
    int set;
    std::cin >> set;
    for ( int i = 0; i < set; ++i )
    {
        int n, k, p;
        std::cin >> n >> k >> p;
        auto ans = ( k + p ) % n;
        std::cout << "Case " << i + 1 << ": " << ( ans == 0 ? n : ans ) << std::endl;
    }
    return 0;
}