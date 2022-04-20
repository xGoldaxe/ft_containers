#include "../ft.hpp"
#include <map>
#include <iostream>

int main( void ) {

	std::cout << std::boolalpha; 

	ft::map<std::string, int> b;
	b.insert( std::make_pair("-a", 1) );
	b.insert( std::make_pair("-b", 2) );
	b.insert( std::make_pair("-c", 3) );
	b.insert( std::make_pair("-d", 4) );
	b.insert( std::make_pair("-e", 3) );

	ft::map<std::string, int> bcopy(b);


	ft::map<std::string, int> b2;
	b2.insert( std::make_pair("*a", 1) );
	b2.insert( std::make_pair("*d", 666) );
	b2.insert( std::make_pair("*e", 333) );

    std::cout << "<-----------{self}----------->" << std::endl;
	std::cout << (b == b) << std::endl;
    std::cout << "<-----------{same shape}----------->" << std::endl;
	std::cout << (b == bcopy) << std::endl;
    std::cout << "<-----------{different shape}----------->" << std::endl;
	std::cout << (b == b2) << std::endl;
	std::cout << (b2 == b) << std::endl;


    std::cout << "<-----------{NOT EQUAL}----------->" << std::endl;

    std::cout << "<-----------{self}----------->" << std::endl;
	std::cout << (b != b) << std::endl;
    std::cout << "<-----------{same shape}----------->" << std::endl;
	std::cout << (b != bcopy) << std::endl;
    std::cout << "<-----------{different shape}----------->" << std::endl;
	std::cout << (b != b2) << std::endl;
	std::cout << (b2 != b) << std::endl;

    return (0);
}