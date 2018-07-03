#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cctype>
#include <algorithm>

int main()
{
    std::string word;
    std::set<std::string> dict;
    while ( std::cin >> word )
    {
        std::vector<std::string> stack;
        std::string temp;
        std::for_each( word.begin(), word.end(), [ &temp, &stack ]( char& c )
        {
            if ( isalpha( c ) )
            {
                temp += tolower( c );
            }
            else
            {
                stack.push_back( temp );
                temp.clear();
            }
        } );
        stack.push_back( temp );
        for ( const auto& pword : stack )
            if ( !pword.empty() )
                dict.insert( pword );
    }
    std::vector<std::string> words( dict.begin(), dict.end() );
    std::sort( words.begin(), words.end() );
    for ( const auto& w : words )
        std::cout << w << std::endl;
    return 0;
}