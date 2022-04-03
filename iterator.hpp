/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:15:07 by pleveque          #+#    #+#             */
/*   Updated: 2022/04/03 15:16:07 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*            @ITERATORS                                                      */
/*                                                                            */
/* ************************************************************************** */
class iterator: public std::iterator<
    std::random_access_iterator_tag, //category
    T, //type
    difference_type, //distance 
    T*, //pointer
    T& // reference
> {
    private:
        typedef typename std::iterator_traits<iterator>::difference_type difference_type;
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
        iterator(void) : _from( NULL ), _to( NULL ), _position( 0 ) {};

        /*************************
        * @parameter constructor
        * ( should be hided from final user )
        * ***********************/
        iterator( T* from, T* to, difference_type position ) :
            _from( from ), _to( to ), _position( position )
        {};
        
        /*************************
        * @copy constructor
        * ***********************/
        iterator( const iterator & ref ) :
            _from( ref.getFrom() ),
            _to( ref.getTo() ),
            _position( ref.getPosition() )
        {};

        /*************************
        * @copy assignement
        * ***********************/
        iterator &operator=( iterator & rhs ) {

            this->_from = rhs.getFrom();
            this->_to = rhs.getTo();
            this->_position = rhs.getPosition();
        };

        /*************************
        * @destructor
        * ***********************/
        ~iterator(void) {};

        /* ************************************************************************** */
        /*                                                                            */
        /*            @legacyOutputIterator                                           */
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
        bool	operator==( const iterator &b ) const {

            if ( this->_from == b.getFrom()
                && this->_to == b.getTo()
                && this->_position == b.getPosition()
            )
                return true;
            return false;
        };
        bool	operator!=( const iterator &b ) const {
            return ( !( this->operator==(b) ) );
        };

        /*************************
        * @casting the value to
        * control as much as possible
        * the end value, but still
        * remain a undefined behavior
        * ***********************/
        reference& operator*(void) {

            return ( *static_cast<value_type *>(this->_from + this->_position) );
        };
        /*************************
        * @i->m equivalent (*i).m
        * ***********************/
        value_type *operator->() {

            return ( this->_from + this->_position );
        };
        iterator& operator++(void) {

            this->_incr( static_cast<difference_type>(1) );
            return ( *this );
        };
        /* ************************************************************************** */
        /*                                                                            */
        /*            @legacyForwardIterator                                          */
        /*                                                                            */
        /* ************************************************************************** */
        iterator operator++(int) {

            iterator tmp = *this;
            this->_incr( static_cast<difference_type>(1) );
            return tmp;
        };
        //*i++;

        /* ************************************************************************** */
        /*                                                                            */
        /*            @legacyBidirectionalIterator                                    */
        /*                                                                            */
        /* ************************************************************************** */
        /* past end iterator = undefined */
        iterator& operator--(void) {

            this->_incr( static_cast<difference_type>(-1) );
            return ( *this );
        };
        iterator operator--(int) {

            iterator tmp = *this;
            this->_incr( static_cast<difference_type>(-1) );
            return tmp;
        };
        //*it-- ??

        /* ************************************************************************** */
        /*                                                                            */
        /*            @legacyRandomAccessIterator                                     */
        /*                                                                            */
        /* ************************************************************************** */
        
        /*************************
        * @random modifier
        * ***********************/
        iterator& operator+=( const difference_type n ) {

            this->_incrNoLimit( n );
            return ( *this );
        };
        iterator& operator-=( const difference_type n ) {

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
        friend iterator operator+( const difference_type n,  const iterator &a ) {

            iterator temp = a;
            return temp += n;
        };
        iterator operator+( const difference_type n ) const {

            iterator temp = *this;
            return temp += n;
        };
        /*substratction*/
        iterator operator-( const difference_type n ) const {

            iterator temp = *this;
            return temp -= n;
        };

        /*************************
        * @difference between iterators
        * ***********************/
        difference_type operator-( const iterator &b ) const {
            
            difference_type diff = this->_position - b.getPosition();
            if ( *this == b + (diff) )
                return diff;
            return static_cast<difference_type>(0);
        };

        reference& operator[]( const difference_type n ) {

            return ( *static_cast<value_type *>(this->_from + this->_position + n) );
        };

        /*************************
        * @comparaison
        * ***********************/
        bool	operator<( const iterator &b ) const {

            return ( (b - *this) > 0 );
        };
        bool	operator>( const iterator &b ) const {

            return ( (b - *this) < 0 );
        };
        bool	operator>=( const iterator &b ) const {

            return ( !( this->operator<(b) ) );
        };
        bool	operator<=( const iterator &b ) const {

            return ( !( this->operator>(b) ) );
        };
};