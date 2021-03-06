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
	
	std::cout << "<-----------{erase all - 2}----------->" << std::endl;
	b.erase( b.begin(), ----b.end() );
	std::map<std::string, int>::iterator it = b.begin();
	std::cout << "size: " << b.size() << std::endl;
	for (; it != b.end(); ++it) {
		std::cout << it->first << ":" << it->second << std::endl;
	}
	std::cout << "<-----------{erase all}----------->" << std::endl;
	b.erase( b.begin(), b.end() );
	std::cout << "size: " << b.size() << std::endl;


    return (0);
}