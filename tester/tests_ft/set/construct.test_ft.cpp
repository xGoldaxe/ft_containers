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


	std::cout << "<-----------{range constructor}----------->" << std::endl;
	ft::set<std::string> itb(b.begin(), b.end());
	for (ft::set<std::string>::const_iterator it = itb.begin(); it != itb.end(); it++)
	{
		std::cout << *it << std::endl;
	}
	
	std::cout << "<-----------{comp constructor}----------->" << std::endl;
	std::greater<std::string> comp;
	std::allocator<std::string> alloc;
	ft::set<std::string, std::greater<std::string> > rb( comp, alloc );
	rb.insert( "-a" );
	rb.insert( "-b" );
	rb.insert( "-c" );
	rb.insert( "-d" );
	rb.insert( "-e" );
	for (ft::set<std::string, std::greater<std::string> >::const_iterator it = rb.begin(); it != rb.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "<-----------{copy constructor}----------->" << std::endl;
	ft::set<std::string> cb( itb );
	for (ft::set<std::string>::const_iterator it = cb.begin(); it != cb.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cout << "<-----------{copy assignement}----------->" << std::endl;
	cb.insert( "-x" );
	cb.insert( "-z" );
	b = cb;
	for (ft::set<std::string>::const_iterator it = b.begin(); it != b.end(); it++)
	{
		std::cout << *it << std::endl;
	}

    return (0);
}