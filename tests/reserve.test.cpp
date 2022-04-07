#include "../ft.hpp"
#include <vector>
#include <iostream>

template < class vector >
void    print_vector( vector v ) {

    for (typename vector::iterator it = v.begin(); it != v.end(); ++it ) {

        std::cout << "<>" <<*it << std::endl;
    }
}

template < class vector >
void    print_mem( vector v ) {

    std::cout << "MEM_USAGE: " << v.size() << "/" << v.capacity() << std::endl;
}

int main( void ) {

    std::vector<std::string> t( static_cast<std::size_t>(5), "yo" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";

	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;

	t.reserve(6);
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;
	t.reserve(12);
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;
	print_vector(t);

	t.reserve(2);
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;
	print_vector(t);

    return (0);
}