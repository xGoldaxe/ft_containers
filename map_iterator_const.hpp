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

#ifndef CONST_MAP_ITERATOR_HPP
#	define CONST_MAP_ITERATOR_HPP

#include "map_iterator.hpp"

namespace ft
{

	template <
		typename T,
		typename Tree
	>

	class const_map_iterator : public ft::map_iterator<T, Tree>
		{
		private:
			typedef ft::map_iterator<T, Tree>				iterator_noconst;

		public:
			typedef const T&								reference;
			typedef const T*								pointer;
			typedef const T									value_type;
			
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
			reference operator*() const {

				return ( iterator_noconst::operator*() );
			};
			/*************************
			* @i->m equivalent (*i).m
			* ***********************/
			value_type *operator->() const {

				return ( iterator_noconst::operator->() );
			};
	};

};

#endif