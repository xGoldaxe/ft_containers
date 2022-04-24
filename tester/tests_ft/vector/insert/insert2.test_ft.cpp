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

    std::cout << t.size() << ":" << t.capacity() << std::endl;

    std::cout << "<-----------{prot 3}----------->" << std::endl;

    ft::vector<std::string> i( static_cast<std::size_t>(9), "*hehe" );
    i[0] = "*je";
    i[1] = "*vais";
    i[2] = "*m'inserer";
    i[3] = "*comment";
    

    t.insert( t.begin() + 3, i.begin(), i.end() );

    for ( ft::vector<std::string>::iterator it = t.begin(); it != t.end(); ++it )
        std::cout << *it << std::endl;
    std::cout << t.size() << ":" << t.capacity() << std::endl;

    return (0);
}