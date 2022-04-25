#include "../ft.hpp"
#include "../ft.hpp"
#include <vector>
#include <iostream>

template < class vector >
void    print_mem( const vector& v ) {

    std::cout << "MEM_USAGE: " << v.size() << "/" << v.capacity() << std::endl;
}

int main( void ) {

	std::cout << std::endl << "COPY && SWAP TESTS" << std::endl;
	ft::vector<int> test;
	for (size_t i = 0; i < 50; i++) { 
		print_mem(test);
		test.push_back(i);
	}
	print_mem(test);
	ft::vector<int> test_copy(test);
	// for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
	print_mem(test_copy);
	ft::vector<int> tast;
	tast = test;
	print_mem(test);
	print_mem(tast);



    return (0);
}