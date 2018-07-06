#include <iostream>
#include <vector>
#include <map>
#include <string>

int main()
{
    int n;
    bool first = true;
    while ( std::cin >> n )
    {
        if ( !first )
            std::cout << std::endl;
        first = false;
        std::vector<std::string> persons( n );
        std::vector<int> budgets( n );
        std::vector<int> receive( n );
        std::map<std::string, int> person_indice;
        for ( int i = 0; i < n; ++i )
        {
            std::cin >> persons[ i ];
            person_indice[ persons[ i ] ] = i;
        }
        for ( int i =0; i < n; ++i )
        {
            std::string name;
            std::cin >> name;
            int index = person_indice[ name ];
            int budget, deploy;
            std::cin >> budget >> deploy;
            if ( !deploy )
                continue;
            budgets[ index ] += budget % deploy;
            budgets[ index ] -= budget;
            int price = budget / deploy;
            for ( int d = 0; d < deploy; ++d )
            {
                std::string name;
                std::cin >> name;
                int index = person_indice[ name ];
                budgets[ index ] += price;
            }
        }
        for ( const auto& name : persons )
        {
            int index = person_indice[ name ];
            std::cout << name << ' ' << budgets[ index ] << std::endl;
        }
    }
    return 0;
}