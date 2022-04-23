/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:09:42 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/23 18:34:08 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TO_STRING_HPP
#	define TO_STRING_HPP

#include <sstream>
#include <string>
#include <iostream>

namespace ft {

    std::string toString( size_t number ) {

        std::string result;

        std::ostringstream convert;
		convert << number;  
		result = convert.str();
        return ( result );
    }
}

#endif