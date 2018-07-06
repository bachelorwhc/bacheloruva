#include <iostream>
#include <map>
#include <string>
#ifdef _DEBUG
#include <fstream>
#endif
const std::map<char, int> table{
    { 'B', 1}, { 'F', 1 },{ 'P', 1 },{ 'V', 1 },
    { 'C', 2 },{ 'G', 2 },{ 'J', 2 },{ 'K', 2 },{ 'Q', 2 },{ 'S', 2 },{ 'X', 2 },{ 'Z', 2 },
    { 'D', 3 },{ 'T', 3 },
    { 'L', 4 },
    { 'M', 5 },{ 'N', 5 },
    { 'R', 6 }
};

int main()
{
#ifdef _DEBUG
    std::ofstream file( "ans.txt" );
#endif
    std::string word;
    while ( std::cin >> word )
    {
        int pre = 0;
        for ( auto c : word )
            if ( table.count( c ) )
            {
                auto s = table.at( c );
                if ( pre != s )
                {
#ifdef _DEBUG
                    file << s;
#endif
                    std::cout << s;
                }
                pre = s;
            }
            else
                pre = 0;
#ifdef _DEBUG
        file << std::endl;
#endif
        std::cout << std::endl;
    }
#ifdef _DEBUG
    file.close();
#endif
    return 0;
}