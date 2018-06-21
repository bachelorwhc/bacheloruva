#include <iostream>
#include <string>

int main()
{
    std::string hello;
    unsigned int count = 0;
    while ( std::cin >> hello )
    {
        if ( hello == "#" )
            return 0;
        ++count;
        std::cout << "Case " << count << ": ";
        if ( hello == "HELLO" )
        {
            std::cout << "ENGLISH";
        }
        else if( hello == "HOLA" )
        {
            std::cout << "SPANISH";
        }
        else if ( hello == "HALLO" )
        {
            std::cout << "GERMAN";
        }
        else if ( hello == "BONJOUR" )
        {
            std::cout << "FRENCH";
        }
        else if ( hello == "CIAO" )
        {
            std::cout << "ITALIAN";
        }
        else if ( hello == "ZDRAVSTVUJTE" )
        {
            std::cout << "RUSSIAN";
        }
        else
        {
            std::cout << "UNKNOWN";
        }
        std::cout << std::endl;
    }
    return 0;
}