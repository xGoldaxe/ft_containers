#include <iostream>
#include <vector>
#include <set>

int main( void ) {

	std::cout << std::boolalpha; 

	std::set<std::string> b;
	b.insert( "-a" );
	b.insert( "-b" );
	b.insert( "-c" );
	b.insert( "-d" );
	b.insert( "-e" );

	std::cout << "<-----------{key exist}----------->" << std::endl;
	std::set<std::string>::iterator it = b.find("-a");
	std::cout << *it << std::endl;
	it = b.find("-e");
	std::cout << *it << std::endl;

	std::cout << "<-----------{key doesnt exist}----------->" << std::endl;
	it = b.find("-w");
	std::cout << ( it == b.end() ) << std::endl;

	std::cout << "<-----------{trigger const}----------->" << std::endl;

	std::set<std::string>::const_iterator bit = b.find("-a");
	std::cout << *bit << std::endl;
    return (0);
}