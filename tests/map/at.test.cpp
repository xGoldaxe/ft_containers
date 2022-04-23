#include <iostream>
#include "../ft.hpp"
#include <vector>
#include <map>

int main( void ) {

    typedef std::pair<int, int> pair_type;

    std::map<int, int> bst;

    pair_type pair = std::make_pair(9, 6);
	bst.insert(pair);
	pair = std::make_pair(2, 6);
	bst.insert(pair);
	pair = std::make_pair(4, 6);
	bst.insert(pair);
	pair = std::make_pair(12, 6);
	bst.insert(pair);
	pair = std::make_pair(14, 6);
	bst.insert(pair);
	pair = std::make_pair(7, 6);
	bst.insert(pair);

	bst.at(2) = 6;
    std::cout << bst.at(2) << std::endl;
    std::cout << bst.at(9) << std::endl;
    std::cout << bst.at(12) << std::endl;

	try
	{
		std::cout << bst.at(19) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
    return (0);
}