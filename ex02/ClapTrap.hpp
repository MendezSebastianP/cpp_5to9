#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# include <cctype>
# define MAX_HP_C 10

class ClapTrap {
    public:
	// canonic
	ClapTrap( void );
	ClapTrap( std::string Name );
	~ClapTrap( void );
	ClapTrap( ClapTrap const &src);
	ClapTrap & operator =( ClapTrap const & rhs);

	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

    protected:
        std::string Name_;
		int Hit_points_;
		int Energy_points_;
		int Attac_damage_;
};


#endif