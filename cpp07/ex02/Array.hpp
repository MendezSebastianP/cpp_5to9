#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>

template<typename T>
class Array {
    public:
	// canonic
	Array( void );
	Array( unsigned int n );
	~Array( void );
	Array( Array const &src);
	Array & operator =( Array const & rhs);
	T &operator[](int i);
    T &operator[](int i) const;

	int size( void ) const;

	private:
	T *array_;
	int len_;
};

#include "Array.tpp"
#endif