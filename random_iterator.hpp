/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_iterator.hpp                                       :+:      :+:    :+:   */
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
	typename Allocator = std::allocator<T>
>

class ft::random_iterator : public std::iterator
        <
            std::random_access_iterator_tag, //category
            T, //type
            std::ptrdiff_t, //distance 
            T*, //pointer
            T& // ref
        > 
    {
    private:
		typedef T value_T;
		typedef T& ref;
        typedef random_iterator iterator;
        typedef typename std::iterator_traits<random_iterator>::difference_type difference_type;
        T* _from;
        T* _to;
        difference_type _position;
    
    protected:
        /*************************
        * @some gettters
        * ***********************/
        T*	getFrom( void ) const	{
        
            return ( this->_from );
        }
        T*	getTo( void ) const	{
        
            return ( this->_to );
        }
        difference_type getPosition( void ) const	{
        
            return ( this->_position );
        }
        /* ************************************************************************** */
        /*                                                                            */
        /*            @utils                                                          */
        /*                                                                            */
        /* ************************************************************************** */
        void	_incr( difference_type n ) {
            
            this->_position += n;
            if ( this->_position < 0)
                this->_position = static_cast<difference_type>(0);
            //comparing the pointer adress
            if ( (this->_from + this->_position) > this->_to )
                this->_position = static_cast<difference_type>(0);
        }
        void	_incrNoLimit( difference_type n ) {
            
            this->_position += n;
        }

    public:
        /* ************************************************************************** */
        /*                                                                            */
        /*            @LEGACY CONSTRUCTOR                                             */
        /*                                                                            */
        /* ************************************************************************** */
        
        /*************************
        * @default constructor
        * ***********************/
        random_iterator(void) : _from( NULL ), _to( NULL ), _position( 0 ) {};

        /*************************
        * @parameter constructor
        * ( should be hided from final user )
        * ***********************/
        random_iterator( T* from, T* to, difference_type position ) :
            _from( from ), _to( to ), _position( position )
        {};
        
        /*************************
        * @copy constructor
        * ***********************/
        random_iterator( const random_iterator & ref ) :
            _from( ref.getFrom() ),
            _to( ref.getTo() ),
            _position( ref.getPosition() )
        {};

        /*************************
        * @copy assignement
        * ***********************/
        random_iterator &operator=( random_iterator & rhs ) {

            this->_from = rhs.getFrom();
            this->_to = rhs.getTo();
            this->_position = rhs.getPosition();
        };

        /*************************
        * @destructor
        * ***********************/
        ~random_iterator(void) {};

        /* ************************************************************************** */
        /*                                                                            */
        /*            @legacyOutputrandom_iterator                                    */
        /*                                                                            */
        /* ************************************************************************** */
        
        /* ************************************************************************** */
        /*                                                                            */
        /*            @legacyInputOperator                                            */
        /*                                                                            */
        /* ************************************************************************** */
        
        /*************************
        * @equally combarable
        * since we need all value
        * to have the wanted behavior
        * we need to check every values
        * ***********************/
        bool	operator==( const random_iterator &b ) const {

            if ( this->_from == b.getFrom()
                && this->_to == b.getTo()
                && this->_position == b.getPosition()
            )
                return true;
            return false;
        };
        bool	operator!=( const random_iterator &b ) const {
            return ( !( this->operator==(b) ) );
        };

        /*************************
        * @casting the value to
        * control as much as possible
        * the end value, but still
        * remain a undefined behavior
        * ***********************/
        ref& operator*(void) {

            return ( *static_cast<value_T *>(this->_from + this->_position) );
        };
        /*************************
        * @i->m equivalent (*i).m
        * ***********************/
        value_T *operator->() {

            return ( this->_from + this->_position );
        };
        random_iterator& operator++(void) {

            this->_incr( static_cast<difference_type>(1) );
            return ( *this );
        };
        /* ************************************************************************** */
        /*                                                                            */
        /*            @legacyForwardIterator                                          */
        /*                                                                            */
        /* ************************************************************************** */
        random_iterator operator++(int) {

            random_iterator tmp = *this;
            this->_incr( static_cast<difference_type>(1) );
            return tmp;
        };
        //*i++;

        /* ************************************************************************** */
        /*                                                                            */
        /*            @legacyBidirectionalIterator                                    */
        /*                                                                            */
        /* ************************************************************************** */
        /* past end random_iterator = undefined */
        random_iterator& operator--(void) {

            this->_incr( static_cast<difference_type>(-1) );
            return ( *this );
        };
        random_iterator operator--(int) {

            random_iterator tmp = *this;
            this->_incr( static_cast<difference_type>(-1) );
            return tmp;
        };
        //*it-- ??

        /* ************************************************************************** */
        /*                                                                            */
        /*            @legacyRandomAccessrandom_iterator                                     */
        /*                                                                            */
        /* ************************************************************************** */
        
        /*************************
        * @random modifier
        * ***********************/
        random_iterator& operator+=( const difference_type n ) {

            this->_incrNoLimit( n );
            return ( *this );
        };
        random_iterator& operator-=( const difference_type n ) {

            return ( this->operator+=( -n ) );
        };
        /*************************
        * @addition and substratction
        * of iterators
        * ***********************/
    
        /* friend allow the function to be non-member and also overloaded operator 
        *  In our case we wanted asymetric operator,
        */
        /*addition*/
        friend random_iterator operator+( const difference_type n,  const random_iterator &a ) {

            random_iterator temp = a;
            return temp += n;
        };
        random_iterator operator+( const difference_type n ) const {

            random_iterator temp = *this;
            return temp += n;
        };
        /*substratction*/
        random_iterator operator-( const difference_type n ) const {

            random_iterator temp = *this;
            return temp -= n;
        };

        /*************************
        * @difference between random_iterators
        * ***********************/
        difference_type operator-( const random_iterator &b ) const {
            
            difference_type diff = this->_position - b.getPosition();
            if ( *this == b + (diff) )
                return diff;
            return static_cast<difference_type>(0);
        };

        ref& operator[]( const difference_type n ) {

            return ( *static_cast<value_T *>(this->_from + this->_position + n) );
        };

        /*************************
        * @comparaison
        * ***********************/
        bool	operator<( const random_iterator &b ) const {

            return ( (b - *this) > 0 );
        };
        bool	operator>( const random_iterator &b ) const {

            return ( (b - *this) < 0 );
        };
        bool	operator>=( const random_iterator &b ) const {

            return ( !( this->operator<(b) ) );
        };
        bool	operator<=( const random_iterator &b ) const {

            return ( !( this->operator>(b) ) );
        };
};