/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 14:32:34 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/22 15:15:10 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#	define LEXICOGRAPHICAL_COMPARE_HPP

template< class Type1, class Type2 >
bool _cmp(const Type1 &a, const Type2 &b) {
	return (a < b);
}

namespace ft
{

	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2 )
	{
		while (first1 != last1 && first2 != last2) {

			if ( _cmp( *first1, *first2 ) )
				return true;
			else if ( _cmp( *first2, *first1 ) )
				return false;
			++first1;
			++first2;
		}
		if (first1 == last1 && first2 != last2)
			return true;
		return false;
	}

	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
								  InputIt2 first2, InputIt2 last2,
								  Compare comp )
	{
		while (first1 != last1 && first2 != last2) {

			if ( comp( *first1, *first2 ) )
				return true;
			else if ( comp( *first2, *first1 ) )
				return false;
			++first1;
			++first2;
		}
		if (first1 == last1 && first2 != last2)
			return true;
		return false;
	}
}

#endif