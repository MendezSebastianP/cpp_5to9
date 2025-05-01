#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>
# include <cctype>
# include <stdint.h>

struct Data
{
	int value;
    Data(int v) : value(v) {}
};


class Serializer {
	private:
	// canonic
	Serializer( void );
	virtual ~Serializer( void ) = 0;
	Serializer( Serializer const &src);
	Serializer & operator =( Serializer const & rhs);
	
    public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};



#endif