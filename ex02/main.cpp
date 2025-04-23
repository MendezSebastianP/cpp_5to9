#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	ClapTrap a( "Seb ");
	ScavTrap b( "ScavSeb");
	ScavTrap c( b );
	FragTrap d( "FragSeb" );

	a.attack( "The corrector");
	b.attack( "The person next to you");
	b.takeDamage(9);
	b.beRepaired(3);
	b.takeDamage(7);
	c.beRepaired( 50 );
	c.guardGate();
	c.guardGate();
	d.highFivesGuys();
	for (size_t i = 0; i < 10; i++)
		b.takeDamage(10);
	for (size_t i = 0; i < 101; i++)
		d.attack( "The Norminette" );
	b.attack( "The person next to you");
	return 0;
}