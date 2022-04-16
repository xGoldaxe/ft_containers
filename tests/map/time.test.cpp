#include <iostream>
#include "../ft.hpp"
#include <vector>
#include <map>

int main( void ) {

    typedef std::pair<int, std::string> pair_type;

    std::map<int, std::string> bst;

    pair_type pair = std::make_pair(1, "salut");
	bst.insert(pair);
	for (size_t i = 2; i < 100000; i++)
	{
		pair = std::make_pair(i, "les");
		bst.insert(pair);
	}
	
    std::cout << bst.at(2) << std::endl;
    std::cout << bst.at(900) << std::endl;
    std::cout << bst.at(4864) << std::endl;
    std::cout << bst.at(9998) << std::endl;


    return (0);
}