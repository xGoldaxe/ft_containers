#include "../ft.hpp"
// E_ARGS --COMPILFLAG=-std=c++20
#include <vector>
#include <iostream>
#include <type_traits>

// first translation unit
 
struct X {
    enum { value1 = true, value2 = true };
};
 
template<class T, ft::enable_if<T::value1, int> = 0>
void func() {} // #1
 
template void func<X>(); // #2
 
