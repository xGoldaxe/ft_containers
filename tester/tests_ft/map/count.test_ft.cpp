#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>

int main( void ) {

	std::cout << std::boolalpha; 

	ft::map<std::string, int> b;
	b.insert( ft::make_pair("-a", 1) );
	b.insert( ft::make_pair("-b", 2) );
	b.insert( ft::make_pair("-c", 3) );
	b.insert( ft::make_pair("-d", 4) );
	b.insert( ft::make_pair("-e", 3) );

	std::cout << b.count("-a") << std::endl;
	std::cout << b.count("-z") << std::endl;

    return (0);
}