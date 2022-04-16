#include "../ft.hpp"
#include "../ft.hpp"
#include <vector>
#include <iostream>

int main( void ) {

    ft::vector<std::string> t( static_cast<std::size_t>(5), "" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";

    t.assign( 5, "salut" );

    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;

    for ( ft::vector<std::string>::iterator it = t.begin(); it != t.end(); ++it ) {

        std::cout << *it << std::endl;
    }

    return (0);
}