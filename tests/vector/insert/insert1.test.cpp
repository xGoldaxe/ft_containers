#include "../ft.hpp"
#include <vector>
#include <iostream>

int main( void ) {

    std::vector<std::string> t( static_cast<std::size_t>(5), "" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";

    std::cout << *(t.insert( t.begin() + 5, "heyyyyy2")) << std::endl;
    std::cout << *(t.insert( t.begin() + 2, "heyyyyy3")) << std::endl;
    std::cout << *(t.insert( t.begin() + 0, "heyyyyy4")) << std::endl;

    std::cout << t.size() << ":" << t.capacity() << std::endl;

    for ( std::vector<std::string>::iterator it = t.begin(); it != t.end(); ++it ) {

        std::cout << *it << std::endl;
    }

    std::cout << "<-----------{prot 2}----------->" << std::endl;

    t.insert( t.begin() + 2, 2, "------");
    std::cout << t.size() << ":" << t.capacity() << std::endl;

    for ( std::vector<std::string>::iterator it = t.begin(); it != t.end(); ++it ) {

        std::cout << *it << std::endl;
    }

    t.insert( t.begin() + 2, 20, "??????");
    std::cout << t.size() << ":" << t.capacity() << std::endl;

    for ( std::vector<std::string>::iterator it = t.begin(); it != t.end(); ++it ) {

        std::cout << *it << std::endl;
    }

    return (0);
}