# include <iostream>
# include <cctype>
# include "Iter.hpp"

template< typename T, typename F>
void iter(T *ptr, size_t len, F f)
{
	if (len < 0)
		return;
	for (size_t i = 0; i < len; i++)
	{
		f(ptr[i]);
	}
}

