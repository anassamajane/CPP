#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap parameterized constructor called for " << this->name << "\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called\n";
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for " << name << "\n";
}

void ClapTrap::attack(const std::string &target)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points to attack!\n";
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points to attack!\n";
        return;
    }
    energyPoints--;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if (hitPoints < 0)
        hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no hit points to repair!\n";
        return;
    }
    if (energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " has no energy points to repair!\n";
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired by " << amount << " hit points!\n";
}