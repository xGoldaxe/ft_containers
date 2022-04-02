/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:45:46 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/01 16:02:55 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#	define ITERATOR_TRAITS_HPP

#include <iostream>
#include <string>

template < class Iter >
class iterator_traits
{

    private:

    public:
        /* coplien */
        iterator_traits( void );
        iterator_traits( iterator_traits const &src );
        ~iterator_traits( void );

        iterator_traits &   operator=( iterator_traits const & rhs );
        /* end coplien */
};


#endif