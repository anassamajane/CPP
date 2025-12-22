#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Russia");
    a.attack("China");
    a.takeDamage(30);
    a.beRepaired(5);
    a.guardGate();
}