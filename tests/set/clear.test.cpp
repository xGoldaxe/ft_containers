#include <iostream>
#include <vector>
#include <set>

int main( void ) {

	std::cout << std::boolalpha; 

    std::set<std::string> bst;

	std::cout << bst.size() << std::endl;

	bst.insert("aa");
	bst.insert("bb");
	bst.insert("cc");

	bst.insert("qewqe");
	bst.insert("pair");

	std::cout << bst.size() << std::endl;
	bst.clear();
	std::cout << bst.size() << std::endl;
	std::cout << "lets iterate" << std::endl;
	for (std::set<std::string>::iterator it = bst.begin(); it != bst.end(); ++it) {

		std::cout << *it << std::endl;
	}
	bst.insert("dsd");
	bst.insert("qewqe");
	bst.insert("dsada");
	for (std::set<std::string>::iterator it = bst.begin(); it != bst.end(); ++it) {

		std::cout << *it << std::endl;
	}
	
    return (0);
}