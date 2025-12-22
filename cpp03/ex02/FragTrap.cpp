#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap parameterized constructor called for " << this->name << "\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for " << name << "\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap requests high fives!\n";
}
