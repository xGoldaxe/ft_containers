/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:55:49 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/15 20:01:59 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ft.hpp"
#include <vector>
#include <map>

int main( void ) {

    typedef std::pair<int, std::string> pair_type;

    ft::map<int, std::string> bst;

    pair_type pair = std::make_pair(9, "salut");
	bst.insert(pair);
	pair = std::make_pair(2, "les");
	bst.insert(pair);
	pair = std::make_pair(4, "amis");
	bst.insert(pair);
	pair = std::make_pair(12, "comment");
	bst.insert(pair);
	pair = std::make_pair(14, "allez");
	bst.insert(pair);
	pair = std::make_pair(7, "vous");
	bst.insert(pair);

    bst.inOrder();
    std::cout << bst.at(19) << std::endl;

    return (0);
}