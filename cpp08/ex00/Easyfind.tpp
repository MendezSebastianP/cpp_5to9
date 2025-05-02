template< typename T>
typename T::iterator easyfind(T &a, int const numb)
{
	for (typename T::iterator i = a.begin(); i != a.end(); i++) 
	{
		if (*i == numb)
			return i;
	}
	return a.end();
}

