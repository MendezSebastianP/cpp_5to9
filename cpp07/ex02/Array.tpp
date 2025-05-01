# include <iostream>
# include <cctype>
# include "Array.hpp"
# define CONST_MSG "\033[1;32mDefault constructor ClapTrap called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor ClapTrap called, name: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor ClapTrap called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor ClapTrap called\033[0m"

template<typename T>
Array<T>::Array( void )
	: array_(NULL), len_(0)
{
	std::cout << CONST_MSG << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int n)
  : array_(n ? new T[n] : 0) , len_(n)
{
    std::cout << CONST_N_MSG << std::endl;
}

template<typename T>
Array<T>::~Array( void )
{
	delete [] array_;
	std::cout << DEST_MSG << " for Array" << std::endl;
}

template<typename T>
Array<T>::Array(Array const& src)
  : array_(src.len_ ? new T[src.len_] : 0), len_(src.len_)
{
    for (int i = 0; i < len_; ++i)
        array_[i] = src.array_[i];
    std::cout << CPY_CONST_MSG << std::endl;
}


template<typename T>
Array<T>& Array<T>::operator=(Array const& rhs)
{
    if (this != &rhs) {
        delete[] array_;
        len_    = rhs.len_;
        array_  = len_ ? new T[len_] : 0;
        for (int i = 0; i < len_; ++i)
            array_[i] = rhs.array_[i];
    }
    std::cout << CPY_ASSIG_OP_MSG << std::endl;
    return *this;
}

template<typename T>
T& Array<T>::operator [](int i) const
{
	if ( i < 0 ||i >= this->len_) 
	{
		throw std::out_of_range("Array index out of range");
	}
	return array_[i];
}

template<typename T>
T &Array<T>::operator [](int i)
{
	if (i < 0 || i >= this->len_) 
	{
		throw std::out_of_range("Array index out of range");
	}
	return array_[i];
}

template<typename T>
int Array<T>::size( void ) const
{
	return len_;
}

