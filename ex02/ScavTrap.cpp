# include <iostream>
# include <cctype>
# include "ScavTrap.hpp"
# include "ClapTrap.hpp"
# define CONST_MSG "\033[1;32mDefault constructor ScavTrap called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor ScavTrap called, name: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor ScavTrap called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor ScavTrap called\033[0m"


ScavTrap::ScavTrap( void )
	: ClapTrap("Empty")
{
	this->Hit_points_ = MAX_HP_S;
	this->Energy_points_ = 50;
	this->Attac_damage_ = 20;
	std::cout << CONST_MSG << std::endl;
}

ScavTrap::ScavTrap( std::string Name )
	: ClapTrap(Name)
{
	this->Hit_points_ = MAX_HP_S;
	this->Energy_points_ = 50;
	this->Attac_damage_ = 20;
	this->Name_ = Name;
	std::cout << CONST_N_MSG << Name << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << DEST_MSG << " for Name: " << Name_ << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const &src )
	: ClapTrap( src )
{
	std::cout << CPY_CONST_MSG << std::endl;
	this->Name_ = src.Name_;
	this->Attac_damage_ = src.Attac_damage_;
	this->Energy_points_ = src.Energy_points_;
	this->Hit_points_ = src.Hit_points_;
}

ScavTrap & ScavTrap::operator= (ScavTrap const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
	this->Name_ = rhs.Name_;
	this->Attac_damage_ = rhs.Attac_damage_;
	this->Energy_points_ = rhs.Energy_points_;
	this->Hit_points_ = rhs.Hit_points_;
	return *this;
}

void	ScavTrap::attack( const std::string& target )
{
	if (this->Hit_points_ == 0)
	{
		std::cout << "ScavTrap " << this->Name_ << " is already dead so it can't attack" 
			<< std::endl;
		return ;
	}
	else if (this->Energy_points_ == 0)
	{
		std::cout << "ScavTrap " << this->Name_ << " has no energy enough to attack" 
			<< std::endl;
		return ;
	}
	this->Energy_points_--;
	std::cout << "ScavTrap " << this->Name_ << "\033[0;31m attacks \033[0m" << target << ", causing "
		<< this->Attac_damage_ << " points of damage! Energy left: " << this->Energy_points_ << std::endl;
}

void	ScavTrap::takeDamage( unsigned int amount )
{
	if (this->Hit_points_ == 0)
	{
		std::cout << "ScavTrap " << this->Name_ << " is already dead so it can't take damamage" 
			<< std::endl;
		return ;
	}
	else if (static_cast<unsigned int>(this->Hit_points_) < amount)
		this->Hit_points_ = 0;
	else
		this->Hit_points_ -= amount;
	std::cout << "ScavTrap " << this->Name_ << " took  " << amount 
		<< " points of damage. Current HP " << this->Hit_points_ << std::endl;
}

void ScavTrap::beRepaired( unsigned int amount )
{
	if (this->Energy_points_ == 0)
	{
		std::cout << "ScavTrap " << this->Name_ << " has no energy enough to be repaired" 
			<< std::endl;
		return ;
	}
	else
	{
		if (this->Hit_points_ + amount > MAX_HP_S )
			this->Hit_points_ = MAX_HP_S;
		else
			this->Hit_points_ += amount;
		this->Energy_points_--;
		std::cout << "ScavTrap " << this->Name_ << "\033[0;32m Has been repaired \033[0m" << ", in "
			<< amount << " points of damage! HP left: " << this->Hit_points_ << ". Energy left: " << this->Energy_points_ << std::endl;
	}
}

void ScavTrap::guardGate( void )
{
	if (this->guardgatemode)
		std::cout << "ScavTrap " << this->Name_ << " is already in Gate Keeper Mode" << std::endl;
	else
	{
		this->guardgatemode = true;
		std::cout << "ScavTrap " << this->Name_ << " just entered in Gate Keeper Mode" 
			<< std::endl;
	}
}

