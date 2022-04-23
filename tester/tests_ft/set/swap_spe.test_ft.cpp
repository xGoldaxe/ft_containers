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

	ft::set<std::string>::iterator bit = b.begin();

	std::cout << "<-----------{swapping}----------->" << std::endl;
	ft::set<std::string> b2;
	b2.insert( "*a" );
	b2.insert( "*d" );
	b2.insert( "*e" );

	std::cout << "b size:" << b.size() << std::endl;
	std::cout << "b2 size:" << b2.size() << std::endl;
	std::swap(b ,b2);
	std::cout << "b size:" << b.size() << std::endl;
	std::cout << "b2 size:" << b2.size() << std::endl;
	for (ft::set<std::string>::iterator it = b.begin(); it != b.end(); ++it) {

		std::cout << *it << std::endl;
	}

	std::cout << "<-----------{pointer still valide}----------->" << std::endl;
	std::cout << ( bit == b2.begin() ) << std::endl;
	for (; bit != b2.end(); ++bit) {

		std::cout << *bit << std::endl;
	}

    return (0);
}