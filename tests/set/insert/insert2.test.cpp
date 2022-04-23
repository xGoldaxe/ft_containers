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
	
	std::cout << "<-----------{already exist case}----------->" << std::endl;
	std::set<std::string>::iterator it = bst.begin();
	++it;
	++it;
	++it;
	std::set<std::string>::iterator iter = bst.insert(it, "bb");
	std::cout << "size: " << bst.size() << std::endl;
	for (; iter != bst.end(); ++iter) {
		std::cout << *iter << std::endl;
	}

	std::cout << "<-----------{normal case}----------->" << std::endl;
	iter = bst.insert(it, "salut");
	std::cout << "size: " << bst.size() << std::endl;
	for (; iter != bst.end(); ++iter) {
		std::cout << *iter << std::endl;
	}

	std::cout << "<-----------{out iterator case}----------->" << std::endl;
	it = bst.end();
	iter = bst.insert(it, "...");
	std::cout << "size: " << bst.size() << std::endl;
	for (; iter != bst.end(); ++iter) {
		std::cout << *iter << std::endl;
	}

    return (0);
}