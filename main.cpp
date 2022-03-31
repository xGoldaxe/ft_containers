/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:55:49 by pleveque          #+#    #+#             */
/*   Updated: 2022/03/31 20:28:10 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ft.hpp"
#include <vector>


int main( void ) {

    // ft::vector<int> test00;

    const std::allocator<int> allocator;
    // ft::vector<int> test01( allocator );
    // ft::vector<int> test02( static_cast<std::size_t>(5), 666, allocator );
    std::vector<int> vec(5, 9);
    ft::vector<int> test03( vec.begin(), vec.end(), allocator );
    ft::vector<int> test04( test03 );

    // std::string str = "salut";
    // std::vector<std::string> test03( 5, str, allocator );
    // std::cout << test03.at(1) << std::endl;

    return (0);
}