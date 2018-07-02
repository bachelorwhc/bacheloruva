#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <map>
#include <vector>
#include <algorithm>

int main()
{
    std::map<std::string, std::vector<std::string>> word_map;
    std::string word;
    while ( std::cin >> word && word != "#" )
    {
        std::vector<char> alphabet_asc;
        for ( auto c : word )
            alphabet_asc.push_back( std::tolower(c) );
        std::sort( alphabet_asc.begin(), alphabet_asc.end() );
        alphabet_asc.push_back( '\0' );
        std::string index( alphabet_asc.begin(), alphabet_asc.end() );
        word_map[ index ].push_back( word );
    }
    std::vector<std::string> answers;
    for ( const auto& kv : word_map )
    {
        const auto& key = kv.first;
        const auto& words = kv.second;
        if ( words.size() == 1 )
            answers.push_back(words[ 0 ]);
    }
    std::sort( answers.begin(), answers.end() );
    for ( auto ans : answers )
        std::cout << ans << std::endl;
    return 0;
}