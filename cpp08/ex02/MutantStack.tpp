#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

template< typename T, typename Container >
MutantStack<T,Container>::MutantStack( void ) //
	: std::stack<T,Container>()
{
	// std::cout << CONST_MSG << std::endl;
}

template< typename T, typename Container >
MutantStack<T,Container>::MutantStack(const MutantStack& other) //
	: std::stack<T,Container>(other)
{
	// std::cout << CONST_N_MSG << std::endl;
}

template< typename T, typename Container >
MutantStack<T,Container>::~MutantStack( void ) // 
{
	// std::cout << DEST_MSG << " for MutantStack" << std::endl;
}

// template< typename T, typename Container >
// MutantStack<T,Container>::MutantStack( MutantStack const &src )
// {
// 	(void)src;
// 	std::cout << CPY_CONST_MSG << std::endl;
// }

template< typename T, typename Container >
MutantStack<T,Container>& MutantStack<T,Container>::operator= (MutantStack const & rhs)
{
	// std::cout << CPY_ASSIG_OP_MSG << std::endl;
	std::stack<T,Container>::operator=(rhs);
    return *this;
}

template< typename T, typename Container >
typename MutantStack<T,Container>::iterator MutantStack<T,Container>::begin()
{
	return this->c.begin();
}

template< typename T, typename Container >
typename MutantStack<T,Container>::iterator MutantStack<T,Container>::end()
{
	return this->c.end();
}

template< typename T, typename Container >
typename MutantStack<T,Container>::const_iterator MutantStack<T,Container>::begin() const
{
	return this->c.begin();
}

template< typename T, typename Container >
typename MutantStack<T,Container>::const_iterator MutantStack<T,Container>::end() const
{
	return this->c.end();
}

template< typename T, typename Container >
typename MutantStack<T,Container>::reverse_iterator MutantStack<T,Container>::rbegin()
{
	return this->c.rbegin();
}

template< typename T, typename Container >
typename MutantStack<T,Container>::reverse_iterator MutantStack<T,Container>::rend()
{
	return this->c.rend();
}

template< typename T, typename Container >
typename MutantStack<T,Container>::const_reverse_iterator MutantStack<T,Container>::rbegin() const
{
	return this->c.rbegin();
}

template< typename T, typename Container >
typename MutantStack<T,Container>::const_reverse_iterator MutantStack<T,Container>::rend() const
{
	return this->c.rend();
}

#endif
