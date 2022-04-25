#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <set>

int main( void ) {

	std::cout << std::boolalpha; 

    ft::set<std::string> bst;

	std::cout << bst.empty() << std::endl;

	bst.insert("aa");

	std::cout << bst.empty() << std::endl;

	bst.insert("bb");
	bst.insert("cc");
	bst.insert("dsd");
	bst.insert("qewqe");
	bst.insert("dsada");

	std::cout << bst.empty() << std::endl;
	
    return (0);
}