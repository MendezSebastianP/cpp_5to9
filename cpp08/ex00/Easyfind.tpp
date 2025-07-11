template< typename T>
typename T::iterator easyfind(T &a, int const numb)
{
	typename T::iterator result = std::find(a.begin(), a.end(), numb);
	if (result == a.end())
	{
		throw std::invalid_argument("\n Value not found.\n");
	}
	return (result);
}

