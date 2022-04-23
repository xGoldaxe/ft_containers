#include <iostream>
#include <vector>
#include <set>

int main( void ) {

	//since its implmentation dependant, size are not the same
	std::cout << std::boolalpha;

    std::set<int> bst2;
    std::set<int> bst;
	std::cout << (bst.max_size() == bst2.max_size()) << std::endl;
	

	std::set<std::string> bst3;
	std::cout << (bst3.max_size() != bst2.max_size())<< std::endl;

	std::set<long long int> bst4;
	std::cout << (bst4.max_size() != bst2.max_size())<< std::endl;


    return (0);
}