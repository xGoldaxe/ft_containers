FTMAINPATH=$1

/usr/bin/sed -i -- 's/std::vector/ft::vector/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::vector/ft::vector/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::reverse_iterator/ft::reverse_iterator/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::map/ft::map/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::set/ft::set/g' $FTMAINPATH

#pair
/usr/bin/sed -i -- 's/std::pair/ft::pair/g' $FTMAINPATH
/usr/bin/sed -i -- 's/std::make_pair/ft::make_pair/g' $FTMAINPATH