#include "../ft.hpp"
#include <iostream>
#include <vector>
#include <map>

int main( void ) {

	//since its implmentation dependant, size are not the same
	std::cout << std::boolalpha;

    ft::map<int, int> bst2;
    ft::map<int, int> bst;
	std::cout << (bst.max_size() == bst2.max_size()) << std::endl;
	

	ft::map<long int, long long int> bst3;
	std::cout << (bst3.max_size() != bst2.max_size())<< std::endl;

    return (0);
}