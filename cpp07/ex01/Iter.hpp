#ifndef Iter_HPP
# define Iter_HPP
# include <iostream>
# include <cctype>

template< typename T, typename F>
void iter(T *ptr, size_t len, F f);


# include "Iter.tpp"

#endif