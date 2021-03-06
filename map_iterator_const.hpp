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
			{};

			const_map_iterator( typename iterator_noconst::tree_ptr tree,
				typename iterator_noconst::node_t* actual ) :
				iterator_noconst( ft::map_iterator<T, Tree>(tree, actual) )
			{};

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
			pointer operator->() const {

				return ( iterator_noconst::operator->() );
			};

			const_map_iterator& operator++(void) {

				iterator_noconst::operator++();
				return ( *this );
			};
			/* ************************************************************************** */
			/*                                                                            */
			/*            @legacyForwardIterator                                          */
			/*                                                                            */
			/* ************************************************************************** */
			const_map_iterator operator++(int) {

				const_map_iterator tmp = *this;
				iterator_noconst::operator++();
				return tmp;
			};

			/* ************************************************************************** */
			/*                                                                            */
			/*            @legacyBidirectionalIterator                                    */
			/*                                                                            */
			/* ************************************************************************** */
			/* past end map_iterator = undefined */
			const_map_iterator& operator--(void) {

				iterator_noconst::operator--();
				return ( *this );
			};
			const_map_iterator operator--(int) {

				const_map_iterator tmp = *this;
				iterator_noconst::operator--();
				return tmp;
			};	

	};

};

#endif