/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 12:23:57 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/23 18:34:25 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#	define IS_INTEGRAL_HPP

#include <string>

namespace ft
{
	/* default case, typename T will catch every non-specialized cases */
	template<typename T>
	struct is_integral{ static const bool value = false; };

	template<>
	struct is_integral<bool>{ static const bool value = true; };

	template<>
	struct is_integral<char>{ static const bool value = true; };

	// template<>
	// struct is_integral<char16_t>{ static const bool value = true; };

	// template<>
	// struct is_integral<char32_t>{ static const bool value = true; };

	template<>
	struct is_integral<wchar_t>{ static const bool value = true; };

	template<>
	struct is_integral<signed char>{ static const bool value = true; };

	template<>
	struct is_integral<short int>{ static const bool value = true; };

	template<>
	struct is_integral<int>{ static const bool value = true; };

	template<>
	struct is_integral<long int>{ static const bool value = true; };

	template<>
	struct is_integral<long long>{ static const bool value = true; };
	
	template<>
	struct is_integral<unsigned char>{ static const bool value = true; };

	template<>
	struct is_integral<unsigned short int>{ static const bool value = true; };

	template<>
	struct is_integral<unsigned int>{ static const bool value = true; };

	template<>
	struct is_integral<unsigned long int>{ static const bool value = true; };

	template<>
	struct is_integral<unsigned long long int>{ static const bool value = true; };

	/* now in const case */
	template<>
	struct is_integral<const bool>{ static const bool value = true; };

	template<>
	struct is_integral<const char>{ static const bool value = true; };

	// template<>
	// struct is_integral<const char16_t>{ static const bool value = true; };

	// template<>
	// struct is_integral<const char32_t>{ static const bool value = true; };

	template<>
	struct is_integral<const wchar_t>{ static const bool value = true; };

	template<>
	struct is_integral<const signed char>{ static const bool value = true; };

	template<>
	struct is_integral<const short int>{ static const bool value = true; };

	template<>
	struct is_integral<const int>{ static const bool value = true; };

	template<>
	struct is_integral<const long int>{ static const bool value = true; };

	template<>
	struct is_integral<const long long>{ static const bool value = true; };
	
	template<>
	struct is_integral<const unsigned char>{ static const bool value = true; };

	template<>
	struct is_integral<const unsigned short int>{ static const bool value = true; };

	template<>
	struct is_integral<const unsigned int>{ static const bool value = true; };

	template<>
	struct is_integral<const unsigned long int>{ static const bool value = true; };

	template<>
	struct is_integral<const unsigned long long int>{ static const bool value = true; };
}

#endif