#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <set>

int main( void ) {

	std::cout << std::boolalpha; 

    ft::set<std::string> bst;

	std::cout << bst.size() << std::endl;

	bst.insert("aa");
	bst.insert("bb");
	bst.insert("cc");
	bst.insert("qewqe");

	ft::set<std::string> b;
	bst.insert( "-a" );
	bst.insert( "-b" );
	bst.insert( "-c" );
	bst.insert( "-d" );
	bst.insert( "bb" );
	
	std::cout << "<-----------{already exist case}----------->" << std::endl;
	bst.insert(b.begin(), b.end());
	ft::set<std::string, int>::iterator it = bst.begin();
	std::cout << "size: " << bst.size() << std::endl;
	for (; it != bst.end(); ++it) {
		std::cout << *it << std::endl;
	}

    return (0);
}