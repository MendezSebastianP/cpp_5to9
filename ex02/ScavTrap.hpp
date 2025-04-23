#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include <cctype>
# include "ClapTrap.hpp"
# define MAX_HP_S 100

class ScavTrap : public ClapTrap
{
    public:
	// canonic
	ScavTrap( void );
	ScavTrap( std::string Name );
	~ScavTrap( void );
	ScavTrap( ScavTrap const &src);
	ScavTrap & operator =( ScavTrap const & rhs);

	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );
	void guardGate();

	private:
	bool guardgatemode;
};


#endif