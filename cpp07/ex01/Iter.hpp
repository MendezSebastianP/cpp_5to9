#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template< typename T, typename F>
void iter(T *ptr, size_t len, F f)
{
	if (len == 0 || !ptr)
		return;
	for (size_t i = 0; i < len; i++)
		f(ptr[i]);
}

/* template< typename T, typename F>
void iter(T const *ptr, size_t const len, F f)
{
	if (len < 0 || !ptr)
		return;
	for (size_t i = 0; i < len; i++)
		f(ptr[i]);
} */

#endif