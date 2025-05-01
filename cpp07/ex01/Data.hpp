#ifndef DATA_HPP
#define DATA_HPP

#include <cstddef>

class Data
{
	public:
	Data( void );
	~Data( void );
	Data( Data const &src);
	Data & operator =( Data const & rhs);

	template< typename T>
	void    printdata(const T &x);
	void	times2( int &num );
	int sizen;
	int data[10];
};

#endif // DATA_HPP