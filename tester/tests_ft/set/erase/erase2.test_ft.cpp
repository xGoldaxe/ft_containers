#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <set>

int main( void ) {

	std::cout << std::boolalpha; 

	ft::set<std::string> b;
	b.insert( "-a" );
	b.insert( "-b" );
	b.insert( "-c" );
	b.insert( "-d" );
	b.insert( "-e" );
	
	std::cout << "<-----------{erase all - 2}----------->" << std::endl;
	b.erase( b.begin(), ----b.end() );
	ft::set<std::string>::iterator it = b.begin();
	std::cout << "size: " << b.size() << std::endl;
	for (; it != b.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "<-----------{erase all}----------->" << std::endl;
	b.erase( b.begin(), b.end() );
	std::cout << "size: " << b.size() << std::endl;


    return (0);
}