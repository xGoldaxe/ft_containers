/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_map_iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:15:07 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/03 16:55:11 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.hpp"

template <
	typename T,
	typename Tree
>

class ft::const_map_iterator : public ft::map_iterator<T, Tree>
	{
	public:
	
	private:		
		typedef ft::map_iterator<T, Tree>				iterator_noconst;
		typedef const T&								const_reference;
		typedef const T									const_value_type;
		
	public:
		/* ************************************************************************** */
		/*                                                                            */
		/*            @CONSTRUCTOR                                                    */
		/*                                                                            */
		/* ************************************************************************** */
		
		const_map_iterator(void)
		{};

		const_map_iterator( iterator_noconst ite ) : iterator_noconst( ite )
		{
		};

		/*************************
		* @destructor
		* ***********************/
		virtual ~const_map_iterator(void) {};

		/* ************************************************************************** */
		/*                                                                            */
		/*            @overrided func                                                 */
		/*                                                                            */
		/* ************************************************************************** */
		const_reference operator*() const {

			return ( iterator_noconst::operator*() );
		};
		/*************************
		* @i->m equivalent (*i).m
		* ***********************/
		const_value_type *operator->() const {

			return ( iterator_noconst::operator->() );
		};
};
