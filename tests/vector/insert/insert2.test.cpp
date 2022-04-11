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

    std::cout << t.size() << ":" << t.capacity() << std::endl;

    std::cout << "<-----------{prot 3}----------->" << std::endl;

    // std::vector<std::string> i( static_cast<std::size_t>(9), "*hehe" );
    // i[0] = "*je";
    // i[1] = "*vais";
    // i[2] = "*m'inserer";
    // i[3] = "*comment";

    // try
    // {
    //     t.insert( t.begin() + 30, i.begin(), i.end() );
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << "EXCEPTION: " << e.what() << '\n';
    // }
    
    // t.insert( t.begin() + 3, i.begin(), i.end() );
    // for ( std::vector<std::string>::iterator it = t.begin(); it != t.end(); ++it )
    //     std::cout << *it << std::endl;
    // std::cout << t.size() << ":" << t.capacity() << std::endl;

    return (0);
}