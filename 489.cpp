#include <iostream>
#include <string>
#include <set>

int main()
{
    int round;
    while ( std::cin >> round && round != -1 )
    {
        std::string ans;
        std::string guess;
        std::set<char> cs;
        std::set<char> guessed;
        std::cin >> ans >> guess;
        for ( auto c : ans )
            cs.insert( c );

        int stroke{ 0 };
        for ( auto c : guess )
        {
            if ( cs.count( c ) > 0 )
                cs.erase( c );
            else if ( guessed.count( c ) == 0 )
                ++stroke;
            guessed.insert( c );
            if ( stroke == 7 )
                break;
            if ( cs.empty() )
                break;
        }
        std::cout << "Round " << round << std::endl;
        if ( cs.empty() )
            std::cout << "You win.\n";
        else if( stroke == 7 )
            std::cout << "You lose.\n";
        else
            std::cout << "You chickened out.\n";
    }
    return 0;
}