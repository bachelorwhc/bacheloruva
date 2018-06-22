#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main()
{
    int n;
    while ( std::cin >> n )
    {
        if ( n == 0 )
            break;

        std::cin.ignore();
        std::vector<int> lines;

        for ( int i = 0; i < n; ++i )
        {
            std::string line;
            std::getline( std::cin, line );
            int count{0};
            auto counter = [ &count ]( char c ) { if ( c == 'X' ) ++count; };
            std::for_each( line.begin(), line.end(), counter );
            lines.push_back( count );
        }

        std::sort( lines.begin(), lines.end() );
        std::reverse( lines.begin(), lines.end() );

        int count = 0;
        auto length = lines[ 0 ];
        const auto size = lines.size();
        for ( int i = 1; i < size; ++i )
        {
            count += length - lines[i];
        }
        std::cout << count << std::endl;
    }
    return 0;
} 