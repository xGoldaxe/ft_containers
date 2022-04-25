#include "../ft.hpp"
#include <vector>
#include <iostream>

// template < class vector >
// void    print_vector( const vector& v ) {

//     for (typename vector::iterator it = v.begin(); it != v.end(); ++it ) {

//         std::cout << "<>" <<*it << std::endl;
//     }
// }

template < class vector >
void    print_mem( const vector& v ) {

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
	std::vector<std::string>::iterator it = t.begin();

	std::vector<std::string> ts;

    ts.reserve(4);
	t.swap( ts );
	std::cout << "MEM_USAGE: " << t.size() << "/" << t.capacity() << std::endl;
	// print_vector(t);
	std::cout << "MEM_USAGE: " << ts.size() << "/" << ts.capacity() << std::endl;
	// print_vector(ts);
    return 0;

	std::cout << "<-----------{it remain valid}----------->" << std::endl;
	for (; it != ts.end(); ++it ) {

        std::cout << "<><>" << *it << std::endl;
    }

    return (0);
}