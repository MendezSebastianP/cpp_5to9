# include <iostream>
# include <cctype>
# include "FragTrap.hpp"
# include "ClapTrap.hpp"
# define CONST_MSG "\033[1;32mDefault constructor FragTrap called\033[0m"
# define CONST_N_MSG "\033[1;32mParametizered constructor FragTrap called, name: \033[0m"
# define CPY_CONST_MSG "\033[1;32mCopy constructor FragTrap called\033[0m"
# define CPY_ASSIG_OP_MSG "Copy assignment operator called"
# define DEST_MSG "\033[1;31mDestructor FragTrap called\033[0m"


FragTrap::FragTrap( void )
	: ClapTrap("Empty")
{
	this->Hit_points_ = MAX_HP_F;
	this->Energy_points_ = 100;
	this->Attac_damage_ = 30;
	std::cout << CONST_MSG << std::endl;
}

FragTrap::FragTrap( std::string Name )
	: ClapTrap(Name)
{
	this->Hit_points_ = MAX_HP_F;
	this->Energy_points_ = 100;
	this->Attac_damage_ = 30;
	this->Name_ = Name;
	std::cout << CONST_N_MSG << Name << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << DEST_MSG << " for Name: " << Name_ << std::endl;
}

FragTrap::FragTrap( FragTrap const &src )
	: ClapTrap( src )
{
	std::cout << CPY_CONST_MSG << std::endl;
	this->Name_ = src.Name_;
	this->Attac_damage_ = src.Attac_damage_;
	this->Energy_points_ = src.Energy_points_;
	this->Hit_points_ = src.Hit_points_;
}

FragTrap & FragTrap::operator= (FragTrap const & rhs)
{
	std::cout << CPY_ASSIG_OP_MSG << std::endl;
	this->Name_ = rhs.Name_;
	this->Attac_damage_ = rhs.Attac_damage_;
	this->Energy_points_ = rhs.Energy_points_;
	this->Hit_points_ = rhs.Hit_points_;
	return *this;
}

void	FragTrap::attack( const std::string& target )
{
	if (this->Hit_points_ == 0)
	{
		std::cout << "FragTrap " << this->Name_ << " is already dead so it can't attack" 
			<< std::endl;
		return ;
	}
	else if (this->Energy_points_ == 0)
	{
		std::cout << "FragTrap " << this->Name_ << " has no energy enough to attack" 
			<< std::endl;
		return ;
	}
	this->Energy_points_--;
	std::cout << "FragTrap " << this->Name_ << "\033[0;31m attacks \033[0m" << target << ", causing "
		<< this->Attac_damage_ << " points of damage! Energy left: " << this->Energy_points_ << std::endl;
}

void	FragTrap::takeDamage( unsigned int amount )
{
	if (this->Hit_points_ == 0)
	{
		std::cout << "FragTrap " << this->Name_ << " is already dead so it can't take damamage" 
			<< std::endl;
		return ;
	}
	else if (static_cast<unsigned int>(this->Hit_points_) < amount)
		this->Hit_points_ = 0;
	else
		this->Hit_points_ -= amount;
	std::cout << "FragTrap " << this->Name_ << " took  " << amount 
		<< " points of damage. Current HP " << this->Hit_points_ << std::endl;
}

void FragTrap::beRepaired( unsigned int amount )
{
	if (this->Energy_points_ == 0)
	{
		std::cout << "FragTrap " << this->Name_ << " has no energy enough to be repaired" 
			<< std::endl;
		return ;
	}
	else
	{
		if (this->Hit_points_ + amount > MAX_HP_F )
			this->Hit_points_ = MAX_HP_F;
		else
			this->Hit_points_ += amount;
		this->Energy_points_--;
		std::cout << "FragTrap " << this->Name_ << "\033[0;32m Has been repaired \033[0m" << ", in "
			<< amount << " points of damage! HP left: " << this->Hit_points_ << ". Energy left: " << this->Energy_points_ << std::endl;
	}
}

void FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->Name_ << " want to hight five with you" 
			<< std::endl;
}

