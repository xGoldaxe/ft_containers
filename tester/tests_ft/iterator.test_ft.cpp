#include "../ft.hpp"
#include <vector>
#include <iostream>

int main( void ) {

    ft::vector<std::string> t( static_cast<std::size_t>(5), "yo" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";

	ft::vector<std::string>::iterator it = t.begin();
	for (; it != t.end(); it++ ) {
		
		std::cout << *it << std::endl;
	}
	std::cout << (it + 5 == t.end() + 5) << std::endl;

    return (0);
}