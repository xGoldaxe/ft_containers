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

    std::vector<std::string> t( static_cast<std::size_t>(8), "" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";
    t[5] = "je";
    t[6] = "suis";
    t[7] = "pleveque";

    std::cout << "<-----------{erase first element}----------->" << std::endl;
    std::cout << *t.erase( t.begin() ) << std::endl;
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    print_vector<std::vector<std::string> >(t);

    //
    std::cout << "<-----------{erase in the middle}----------->" << std::endl;
    std::cout << *t.erase( t.begin() + 2 ) << std::endl;
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    print_vector<std::vector<std::string> >(t);

    //
    std::cout << "<-----------{erase last element}----------->" << std::endl;
    std::cout << *t.erase( t.end() - 1) <<  std::endl;
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    print_vector<std::vector<std::string> >(t);

    std::cout << "<-----------{erase end}----------->" << std::endl;
    std::cout << *t.erase( t.end() ) <<  std::endl;
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    print_vector<std::vector<std::string> >(t);

    std::cout << "<-----------{some errors}----------->" << std::endl;
    std::vector<std::string> to( static_cast<std::size_t>(2), "*/**/*" );
    std::cout << *t.erase( to.begin() ) << std::endl;

    // try
    // {
    //     std::cout << *t.erase( t.end() + 20 ) <<  std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // try
    // {
    //     std::cout << *t.erase( t.end() -1 ) <<  std::endl;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    
    std::cout << "Size: " << t.size() << " // Capacity: " << t.capacity() << std::endl;
    print_vector<std::vector<std::string> >(t);

    return (0);
}