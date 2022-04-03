/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:55:49 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/03 18:58:26 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ft.hpp"
#include <vector>

// int main()
// {
//     int sz = 100;
//     std::vector<int> v;
 
//     v.reserve(10);

//     std::vector<int>::size_type cap = v.capacity();
//     std::cout << "Initial size: " << v.size() << ", capacity: " << cap << '\n';
 
//     std::cout << "\nDemonstrate the capacity's growth policy."
//                  "\nSize:  Capacity:  Ratio:\n" << std::left;
//     while (sz-- > 0) {
//         v.push_back(sz);
//             std::cout << ":" << v.size()
//                       << ":" << v.capacity()
//                       << ":" << v.capacity() / static_cast<float>(cap) << '\n';
//             cap = v.capacity();
//     }
//     sz = 100;
//     while (sz-- > 0) {
//         v.pop_back();
//         std::cout << ":" << v.size()
//                     << ":" << v.capacity()
//                     << ":" << v.capacity() / static_cast<float>(cap) << '\n';
//         cap = v.capacity();
//     }
 
//     std::cout << "\nFinal size: " << v.size() << ", capacity: " << v.capacity() << '\n';
// }

int main( void ) {

    // ft::vector<int> test00;

    // const std::allocator<int> allocator;
    // std::string str = "salut";
    // std::vector<std::string> test03( 5, str, allocator );
    // std::cout << test03[8] << std::endl;


    // std::allocator<std::string> str_alloc;
    // // ft::vector<int> test01( allocator );
    // std::string test02str = "COUNT";
    // ft::vector<std::string> test02( static_cast<std::size_t>(5), test02str, str_alloc );
    // std::vector<int> vec(5, 9);
    // ft::vector<int> test03( vec.begin(), vec.end(), allocator );
    // ft::vector<int> test04( test03 );

    // std::cout << "<-----------{Accessor tests}----------->" << std::endl;
    // const std::string str = "salut";
    // std::allocator<std::string> str_alloc;
    // ft::vector<std::string> test( static_cast<std::size_t>(5), str, str_alloc );
    // std::cout << *test.data() << std::endl;
    
    // std::allocator<int> int_alloc;
    // ft::vector<int> t( static_cast<std::size_t>(1), 666 );
    // std::cout << *t.data() << std::endl;

    std::cout << "<-----------{Iterators}----------->" << std::endl;
    // std::vector<std::string> t;
    // t.push_back("salut");
    // t.push_back("les");
    // t.push_back("amis");
    // // std::vector<int>::iterator it;
    // std::vector<std::string>::iterator it = t.end();
    // it--;
    // for (; it != t.end(); it-- ) {

    //     std::cout << "hey" << std::endl;
    // }

    // std::cout << &(*it) << std::endl;
    ft::vector<std::string> t( static_cast<std::size_t>(5), "salut les amis" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";

    t.push_back("vous");

    ft::reverse_iterator< ft::vector<std::string>::iterator > rit;

    std::cout << t.size() << "::" << t.capacity() << std::endl;
    std::cout << t.size() << "::" << t.capacity() << std::endl;
    for (ft::vector<std::string>::iterator it = t.begin(); it != t.end(); ++it) {
        std::cout << *it << std::endl;
    }
    // ft::vector<std::string>::iterator it;
    // ft::reverse_iterator<int> rit;
    
    return (0);
}