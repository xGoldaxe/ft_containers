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


	std::cout << "<-----------{range constructor}----------->" << std::endl;
	ft::map<std::string, int> itb(b.begin(), b.end());
	for (ft::map<std::string, int>::const_iterator it = itb.begin(); it != itb.end(); it++)
	{
		std::cout << it->first << std::endl;
	}
	
	std::cout << "<-----------{comp constructor}----------->" << std::endl;
	std::greater<std::string> comp;
	std::allocator<ft::pair<std::string, int> > alloc;
	ft::map<std::string, int, std::greater<std::string> > rb( comp, alloc );
	rb.insert( ft::make_pair("-a", 1) );
	rb.insert( ft::make_pair("-b", 2) );
	rb.insert( ft::make_pair("-c", 3) );
	rb.insert( ft::make_pair("-d", 4) );
	rb.insert( ft::make_pair("-e", 3) );
	for (ft::map<std::string, int, std::greater<std::string> >::const_iterator it = rb.begin(); it != rb.end(); it++)
	{
		std::cout << it->first << std::endl;
	}

	std::cout << "<-----------{copy constructor}----------->" << std::endl;
	ft::map<std::string, int> cb( itb );
	for (ft::map<std::string, int>::const_iterator it = cb.begin(); it != cb.end(); it++)
	{
		std::cout << it->first << ":"<< it->second << std::endl;
	}

	std::cout << "<-----------{copy assignement}----------->" << std::endl;
	cb.insert( ft::make_pair("-x", 666) );
	cb.insert( ft::make_pair("-z", 666) );
	b = cb;
	for (ft::map<std::string, int>::const_iterator it = b.begin(); it != b.end(); it++)
	{
		std::cout << it->first << ":"<< it->second << std::endl;
	}

    return (0);
}