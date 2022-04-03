/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:30:41 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/03 19:05:11 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"

template <typename Iter>

class ft::reverse_iterator {

    public:
        /* ************************************************************************** */
        /*                                                                            */
        /*            @MEMBER TYPES                                                   */
        /*                                                                            */
        /* ************************************************************************** */
        typedef Iter    iterator_type;
        // typedef typename std::iterator_traits<Iter>::iterator_category   iterator_category;
        
        /* ************************************************************************** */
        /*                                                                            */
        /*            @CONSTRUCTORS                                                   */
        /*                                                                            */
        /* ************************************************************************** */
        reverse_iterator(void) {
            std::cout << "reverse iterator default" << std::endl;
        };

        // explicit reverse_iterator( iterator_type x);

        // template< class U >
        // reverse_iterator( const reverse_iterator<U>& other );

};