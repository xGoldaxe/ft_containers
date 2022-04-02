/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:55:49 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/02 20:18:17 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ft.hpp"
#include <vector>


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

    ft::vector<std::string>::iterator it = t.begin();
    ft::vector<std::string>::iterator it2 = t.begin();
    ++it2;
    std::cout << (it[1] == *++it) << std::endl;
    // --it;
    // for (; it != t.begin(); it-- ) {

    //     std::cout << "{" << *it << std::endl;
    // }
    // std::cout << "<-----------{out}----------->" << std::endl;
    // std::cout << *it << std::endl;
    // std::cout << *(++it) << std::endl;
    // std::cout << *it << std::endl;
    // std::cout << *it << std::endl;


    return (0);
}