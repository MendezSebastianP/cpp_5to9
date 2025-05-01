#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template< typename T, typename F>
void iter(T *ptr, size_t len, F f)
{
	if (len < 0)
		return;
	for (size_t i = 0; i < len; i++)
		f(ptr[i]);
}

template<typename T, typename U, typename MFP>
void iter(T* array, std::size_t length, U* obj, MFP mfp)
{
    for (std::size_t i = 0; i < length; ++i)
        (obj->*mfp)(array[i]);
}

#endif