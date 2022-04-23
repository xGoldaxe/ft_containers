#include <iostream>
#include <vector>
#include <set>

int main( void ) {

    std::set<std::string> bst;

	std::cout << bst.size() << std::endl;

	bst.insert("aa");

	std::cout << bst.size() << std::endl;

	bst.insert("bb");
	bst.insert("cc");
	bst.insert("dsd");
	bst.insert("qrwqe");
	bst.insert("dsada");

	std::cout << bst.size() << std::endl;
	
    return (0);
}