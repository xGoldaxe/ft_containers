FTMAINPATH=$1

/usr/bin/sed -i -- 's/std::enable_if/ft::enable_if/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::is_integral/ft::is_integral/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::iterator_traits/ft::iterator_traits/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::pair/ft::pair/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::make_pair/ft::make_pair/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::lexicographical_compare/ft::lexicographical_compare/g' $FTMAINPATH