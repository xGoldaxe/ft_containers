#include "../ft.hpp"
#include <vector>
#include <iostream>

int main( void ) {

    std::vector<int> r( 3, 2 );
    (void)r;

    std::vector<std::vector<int> > t( static_cast<std::size_t>(5), r );

    std::cout << t.size() << ":" << t.capacity() << std::endl;

    std::cout << "<-----------{prot 3}----------->" << std::endl;

    std::vector<std::vector<int> > i( static_cast<std::size_t>(9), r );

    t.insert( t.begin() + 2, i.begin(), i.end() );

    std::cout << t.size() << ":" << t.capacity() << std::endl;

    return (0);
}