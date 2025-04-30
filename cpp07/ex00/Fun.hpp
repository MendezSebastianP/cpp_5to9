#ifndef FUN_HPP
# define FUN_HPP
# include <iostream>
# include <cctype>

template< typename T>
void swap(T &a, T &b);
template< typename T>
T const & min(T const &a, T const &b) ;
template< typename T>
T const & max(T const &a, T const &b) ;


# include "Fun.tpp"

#endif