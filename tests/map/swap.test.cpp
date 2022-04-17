#include <iostream>
#include <vector>
#include <map>

int main( void ) {

	std::cout << std::boolalpha; 

	std::map<std::string, int> b;
	b.insert( std::make_pair("-a", 1) );
	b.insert( std::make_pair("-b", 2) );
	b.insert( std::make_pair("-c", 3) );
	b.insert( std::make_pair("-d", 4) );
	b.insert( std::make_pair("-e", 3) );

	std::map<std::string, int>::iterator bit = b.begin();

	std::cout << "<-----------{swapping}----------->" << std::endl;
	std::map<std::string, int> b2;
	b2.insert( std::make_pair("*a", 1) );
	b2.insert( std::make_pair("*d", 666) );
	b2.insert( std::make_pair("*e", 333) );

	std::cout << "b size:" << b.size() << std::endl;
	std::cout << "b2 size:" << b2.size() << std::endl;
	b.swap(b2);
	std::cout << "b size:" << b.size() << std::endl;
	std::cout << "b2 size:" << b2.size() << std::endl;
	for (std::map<std::string, int>::iterator it = b.begin(); it != b.end(); ++it) {

		std::cout << it->first << ":" << it->second << std::endl;
	}

	std::cout << "<-----------{pointer still valide}----------->" << std::endl;
	std::cout << ( bit == b2.begin() ) << std::endl;
	for (; bit != b2.end(); ++bit) {

		std::cout << bit->first << ":" << bit->second << std::endl;
	}

    return (0);
}