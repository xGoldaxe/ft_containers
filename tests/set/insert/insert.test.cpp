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
	
	std::pair<std::set<std::string>::iterator, bool> iteros = bst.insert("LAST INSERTED");
	std::cout << "Is inserted: " << iteros.second << std::endl; 
	std::set<std::string>::iterator iter = iteros.first;
	for (; iter != bst.end(); ++iter) {
		std::cout << *iter << std::endl;
	}

	std::cout << bst.size() << std::endl;
	for (std::set<std::string>::iterator it = bst.begin(); it != bst.end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << "<-----------{error case}----------->" << std::endl;
	iteros = bst.insert("LAST INSERTED");
	std::cout << "Is inserted: " << iteros.second << std::endl; 
	std::cout << "size: " << bst.size() << std::endl;

	iter = iteros.first;
	for (; iter != bst.end(); ++iter) {
		std::cout << *iter << std::endl;
	}
    return (0);
}