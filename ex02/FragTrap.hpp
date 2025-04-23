#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include <cctype>
# include "ClapTrap.hpp"
# define MAX_HP_F 100

class FragTrap : public ClapTrap
{
    public:
	// canonic
	FragTrap( void );
	FragTrap( std::string Name );
	~FragTrap( void );
	FragTrap( FragTrap const &src);
	FragTrap & operator =( FragTrap const & rhs);

	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );
	void highFivesGuys();
};


#endif