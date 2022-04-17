#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>

int main( void ) {

	std::cout << std::boolalpha; 

	ft::map<std::string, int> b;
	b.insert( std::make_pair("-a", 1) );
	b.insert( std::make_pair("-b", 2) );
	b.insert( std::make_pair("-c", 3) );
	b.insert( std::make_pair("-d", 4) );
	b.insert( std::make_pair("-e", 3) );
	
	std::cout << "<-----------{erase exist}----------->" << std::endl;
	std::cout << "erase?: " << b.erase( "-d" ) << std::endl;
	ft::map<std::string, int>::iterator it = b.begin();
	std::cout << "size: " << b.size() << std::endl;
	for (; it != b.end(); ++it) {
		std::cout << it->first << ":" << it->second << std::endl;
	}
	std::cout << "<-----------{erase all}----------->" << std::endl;
	std::cout << "erase?: " << b.erase( "--no" ) << std::endl;
	std::cout << "size: " << b.size() << std::endl;


    return (0);
}