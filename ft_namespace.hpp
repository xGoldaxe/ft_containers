/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_namespace.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:09:42 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/22 17:25:06 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NAMESPACE_HPP
#	define FT_NAMESPACE_HPP

#include <sstream>
#include <string>
#include <iostream>

namespace ft {

    /* vector */
    template <class T, class Allocator>
    class vector;
    /* vector */

    /* map */
    template <
        class Key,
        class T,
        class Compare,
        class Allocator
    >
    class map;
    /* map */

    /* stack */
    template < class T, class Container >
    class stack;


    template <typename T, typename Allocator>
    class random_iterator;

    template <class T, class Tree >
    class map_iterator;

    template <class T, class Tree >
    class const_map_iterator;

    template <typename Iter>
    class reverse_iterator;

    /*************************
    * @enable if
    * ***********************/
    template< bool B, class T >
    struct enable_if;

    template<class T>
    struct ft::enable_if<true, T>;

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