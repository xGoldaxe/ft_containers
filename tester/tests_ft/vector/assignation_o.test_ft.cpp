#include "../ft.hpp"
#include "../ft.hpp"
#include <vector>
#include <iostream>

template < class vector >
void    print_vector( vector v ) {

    for (typename vector::iterator it = v.begin(); it != v.end(); ++it ) {

        std::cout << "<>" <<*it << std::endl;
    }
}

int main( void ) {

    ft::vector<std::string> t( static_cast<std::size_t>(5), "yo" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";

	t.push_back(" yoo ");

	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;

	ft::vector<std::string> to;
	std::cout << "MEM_USAGE: " << to.size() << "/" << to.capacity() << std::endl;
	to = t;
	std::cout << "MEM_USAGE: " << to.size() << "/" << to.capacity() << std::endl;
	print_vector( to );

	// std::cout << "<-----------{self assignation}----------->" << std::endl;
    // t = t;
    // std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;
	// print_vector( t );

    return (0);
}