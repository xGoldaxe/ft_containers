/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:06:07 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/23 18:33:08 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#	define ENABLE_IF_HPP

#include <iostream>
#include <string>

namespace ft {

	template< bool B, class T = void >
	struct ft::enable_if {};

	template<class T>
	struct ft::enable_if<true, T> { 
		typedef T type;
	};

}

#endif