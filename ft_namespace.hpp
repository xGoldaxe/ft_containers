/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_namespace.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:09:42 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/01 15:47:00 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NAMESPACE_HPP
#	define FT_NAMESPACE_HPP

#include <sstream>
#include <string>
#include <iostream>

namespace ft {

    /* vector */
    template <typename T, typename Allocator>
    class vector;
    /* vector */

    template < class Iter >
    class iterator_traits;

    /* ************************************************************************** */
    /*                                                                            */
    /*            @UTILS                                                          */
    /*                                                                            */
    /* ************************************************************************** */
    std::string toString( size_t number ) {

        std::string result;

        std::ostringstream convert;
		convert << number;  
		result = convert.str();
        return ( result );
    }
}

#endif