#include <set>
#include <list>
#include <iostream>



int		main(void)
{

	std::list<int> lst;
	unsigned int lst_size = 5;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(2.5 + i);

	std::set<int> st(lst.begin(), lst.end());
	std::set<int>::iterator it(st.begin());
	std::set<int>::const_iterator ite(st.begin());
	(void)it;
	(void)ite;
	return (0);
}