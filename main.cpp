/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:55:49 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/06 14:43:49 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ft.hpp"
#include <vector>

int main( void ) {

    ft::vector<std::string> t( static_cast<std::size_t>(5), "" );
    t[0] = "salut";
    t[1] = "les";
    t[2] = "amis";
    t[3] = "comment";
    t[4] = "allez";
    
    t.insert( t.begin() + 3, 300000, "=========" );

    std::cout << t.size() << ":" << t.capacity() << std::endl;
    for (ft::vector<std::string>::iterator it = t.begin();
            it != t.end(); ++it)
        std::cout << *it << std::endl;

    return (0);
}