# include <iostream>
# include <cctype>
# include <assert.h>
# include "Serializer.h"

void sep( size_t n, std::string msg)
{
	std::cout << std::endl;
	for (size_t i = 0; i < n; i++)
		std::cout << "#########################################################################" << std::endl;
	std::cout << "                            " << msg << std::endl;
	for (size_t i = 0; i < n; i++)
		std::cout << "#########################################################################" << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	Data *original = new Data(42);
	Data *original2 = new Data(-42);
	Data *original3 = new Data(0);

	// Serializer test;

	uintptr_t serialized = Serializer::serialize(original);
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << std::boolalpha << (original == deserialized) << std::endl;

	serialized = Serializer::serialize(original2);
	deserialized = Serializer::deserialize(serialized);
	std::cout << std::boolalpha << (original2 == deserialized) << std::endl;

	serialized = Serializer::serialize(original3);
	deserialized = Serializer::deserialize(serialized);
	std::cout << std::boolalpha << (original3 == deserialized) << std::endl;
}