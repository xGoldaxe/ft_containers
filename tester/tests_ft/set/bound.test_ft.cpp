#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <set>


int main( void ) {

	std::cout << std::boolalpha; 
	typedef ft::set<int>::iterator iterator;
	typedef ft::set<int>::const_iterator const_iterator;

	ft::set<int> b;
	b.insert( 1 );
	b.insert( 2 );
	b.insert( 3 );
	b.insert( 5 );
	b.insert( 4 );

	std::cout << "<-----------{lower bound}----------->" << std::endl;
	iterator it = b.lower_bound(2);
	std::cout << *it << std::endl;
	it = b.lower_bound(150);
	std::cout << (it == b.end()) << std::endl;

	std::cout << ( b.end() == b.lower_bound(150) ) << std::endl;

	std::cout << "<-----------{upper bound}----------->" << std::endl;
	it = b.upper_bound(-10);
	std::cout << *it << std::endl;
	it = b.upper_bound(150);
	std::cout << (it == b.end()) << std::endl;

	std::cout << "<-----------{equal range}----------->" << std::endl;
	std::cout << "inside" << std::endl;
	ft::pair<iterator, iterator> p = b.equal_range(2);
	std::cout << *p.first << std::endl;
	std::cout << *p.second << std::endl;

	std::cout << "outside" << std::endl;
	p = b.equal_range(150);
	std::cout << (p.first == b.end()) << std::endl;
	std::cout << (p.second == b.end()) << std::endl;

	std::cout << "<-----------{const}----------->" << std::endl;
	ft::pair<const_iterator, const_iterator> pad = b.equal_range(2);
	std::cout << *pad.first << std::endl;
	std::cout << *pad.second << std::endl;

    return (0);
}