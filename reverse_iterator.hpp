/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:30:41 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/04 18:04:57 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"

template <typename Iter>

class ft::reverse_iterator : public std::iterator
		<
			typename std::iterator_traits<Iter>::iterator_category,			//category
			typename std::iterator_traits<Iter>::value_type,				//type
			typename std::iterator_traits<Iter>::difference_type,			//difference 
			typename std::iterator_traits<Iter>::pointer,					//pointer
			typename std::iterator_traits<Iter>::reference					// reference
		> 
{
	private:
		Iter	_iterator;

	public:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @MEMBER TYPES                                                   */
		/*                                                                            */
		/* ************************************************************************** */
		typedef reverse_iterator											iterator;
		typedef Iter														iterator_type;
		typedef reverse_iterator<Iter>										reverse_type;
		typedef typename std::iterator_traits<Iter>::iterator_category		iterator_category;
		typedef typename std::iterator_traits<Iter>::value_type				value_type;
		typedef typename std::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename std::iterator_traits<Iter>::pointer				pointer;
		typedef typename std::iterator_traits<Iter>::reference				reference;
		
		/* ************************************************************************** */
		/*                                                                            */
		/*            @CONSTRUCTORS                                                   */
		/*                                                                            */
		/* ************************************************************************** */
		/*************************
		* @will just create an 
		* empty iterator that won't
		* be usable without assignation
		* ***********************/

		reverse_iterator(void) : _iterator() {};

		explicit reverse_iterator( Iter x ) : _iterator( x ) {};

		reverse_iterator( const reverse_iterator& other ) : _iterator( other.base() ) {};

		reverse_iterator operator=( const reverse_iterator& other ) {

			this->_iterator = other.base();
			return (*this);
		}

		virtual ~reverse_iterator(void) {}

		/*************************
		* @getter for _iterator
		* ***********************/
		iterator_type base(void) const {

			return (this->_iterator);
		}

};