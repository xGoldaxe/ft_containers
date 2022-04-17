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

	std::cout << "<-----------{key exist}----------->" << std::endl;
	std::map<std::string, int>::iterator it = b.find("-a");
	std::cout << it->first << ":" << it->second << std::endl;
	it = b.find("-e");
	std::cout << it->first << ":" << it->second << std::endl;

	std::cout << "<-----------{key doesnt exist}----------->" << std::endl;
	it = b.find("-w");
	std::cout << ( it == b.end() ) << std::endl;

	std::cout << "<-----------{trigger const}----------->" << std::endl;

	std::map<std::string, int>::const_iterator bit = b.find("-a");
	std::cout << bit->first << ":" << bit->second << std::endl;
    return (0);
}