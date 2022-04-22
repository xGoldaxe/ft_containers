// E_ARGS --COMPILFLAG=-std=c++20
#include <vector>
#include <iostream>
#include <type_traits>

template <class T>
typename std::enable_if<(sizeof(T) <= sizeof(int))>::type f(T) {
    std::cout << "f() version petite taille" << std::endl;
}

template <class T>
typename std::enable_if<(sizeof(T) > sizeof(int))>::type f(T) {
    std::cout << "f() version grande taille" << std::endl;
}


int main() {
    long long int a = 10;
   f(a); // version « grande taille »s
   f(3);   // version « petite taille »
}