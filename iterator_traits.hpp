/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:45:46 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/22 16:41:29 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#	define ITERATOR_TRAITS_HPP

#include <iostream>
#include <string>

namespace ft
{
	/* iterator template */
	template < class Iter >
	struct iterator_traits
	{
		typedef typename Iter::difference_type			difference_type;
		typedef typename Iter::value_type				value_type;
		typedef typename Iter::pointer					pointer;
		typedef typename Iter::reference				reference;
		typedef typename Iter::iterator_category		iterator_category;
	};

	/* pointer specialization */
	template < class T >
	struct iterator_traits<T*>
	{
		typedef std::ptrdiff_t							difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};
};

#endif