#include <iostream>
#include <vector>
#include <set>

int main( void ) {

    std::set<std::string> bst;

	bst.insert("aa");
	bst.insert("bb");
	bst.insert("cc");
	bst.insert("dsd");
	bst.insert("qewqe");
	bst.insert("dsada");

	std::reverse_iterator<std::set<std::string>::iterator> it = bst.rbegin();
	std::cout << "<-----------{normal case}----------->" << std::endl;
    for (; it != bst.rend(); ++it) {

		std::cout << it->size() << std::endl;
	}

	std::cout << "<-----------{empty case}----------->" << std::endl;
    std::set<std::string> be;
	std::reverse_iterator<std::set<std::string>::iterator> rite = be.rbegin();
    for (; rite != be.rend(); ++rite) {

		std::cout << *rite << std::endl;
	}

	std::cout << "<-----------{const ite}----------->" << std::endl;
	std::set<std::string>::const_iterator r = bst.end();
	std::reverse_iterator<std::set<std::string>::const_iterator> rr(r);
	std::cout << *rr << std::endl;
	
    return (0);
}