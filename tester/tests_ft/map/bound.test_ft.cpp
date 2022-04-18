#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>



int main( void ) {

	std::cout << std::boolalpha; 
	typedef ft::map<int, std::string>::iterator iterator;
	typedef ft::map<int, std::string>::const_iterator const_iterator;

	ft::map<int, std::string> b;
	b.insert( std::make_pair(1,"-a") );
	b.insert( std::make_pair(2,"-b") );
	b.insert( std::make_pair(3,"-c") );
	b.insert( std::make_pair(5,"-d") );
	b.insert( std::make_pair(4,"-e") );

	std::cout << "<-----------{lower bound}----------->" << std::endl;
	iterator it = b.lower_bound(2);
	std::cout << it->first << ":" << it->second << std::endl;
	it = b.lower_bound(150);
	std::cout << (it == b.end()) << std::endl;

	std::cout << ( b.end() == b.lower_bound(150) ) << std::endl;

	std::cout << "<-----------{upper bound}----------->" << std::endl;
	it = b.upper_bound(-10);
	std::cout << it->first << ":" << it->second << std::endl;
	it = b.upper_bound(150);
	std::cout << (it == b.end()) << std::endl;

	std::cout << "<-----------{equal range}----------->" << std::endl;
	std::cout << "inside" << std::endl;
	std::pair<iterator, iterator> p = b.equal_range(2);
	std::cout << p.first->first << ":" << p.first->second << std::endl;
	std::cout << p.second->first << ":" << p.second->second << std::endl;

	std::cout << "outside" << std::endl;
	p = b.equal_range(150);
	std::cout << (p.first == b.end()) << std::endl;
	std::cout << (p.second == b.end()) << std::endl;

	std::cout << "<-----------{const}----------->" << std::endl;
	std::pair<const_iterator, const_iterator> pad = b.equal_range(2);
	std::cout << pad.first->first << ":" << pad.first->second << std::endl;
	std::cout << pad.second->first << ":" << pad.second->second << std::endl;

    return (0);
}