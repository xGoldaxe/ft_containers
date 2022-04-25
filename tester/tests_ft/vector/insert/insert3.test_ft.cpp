#include "../ft.hpp"
#include "../ft.hpp"
#include <vector>
#include <iostream>

int main( void ) {

    ft::vector<int> r( 3, 2 );
    (void)r;

    ft::vector<ft::vector<int> > t( static_cast<std::size_t>(5), r );

    std::cout << t.size() << ":" << t.capacity() << std::endl;

    std::cout << "<-----------{prot 3}----------->" << std::endl;

    ft::vector<ft::vector<int> > i( static_cast<std::size_t>(9), r );

    t.insert( t.begin() + 2, i.begin(), i.end() );

    std::cout << t.size() << ":" << t.capacity() << std::endl;

    return (0);
}