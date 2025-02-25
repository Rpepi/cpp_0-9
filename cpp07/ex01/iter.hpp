#ifndef ITER_HPP
# define TEMPLATE_HPP

#include <string>
#include <iostream>

template <typename T> void iter(T *adress, int len, void (*f)(T const &))
{
	for(int i = 0; i < len; i++)
	{
		f(adress[i]);
	}
}


#endif