#include "../ft.hpp"
#include <list>
#include <iostream>
#include <map>
#include <set>

#define T1 int
#define T2 int

int		main(void)
{
	ft::map<T1, T2> const mp;
	ft::map<T1, T2>::iterator it = mp.begin(); // <-- error expected

	(void)it;
	return (0);
}
