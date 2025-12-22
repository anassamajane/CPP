#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ScavTrap a("Batman");
    a.attack("Joker");
    a.takeDamage(50);
    a.beRepaired(10);
    a.guardGate();
    std::cout << "------------------------------------------------\n";
    FragTrap b("Russia");
    b.attack("USA");
    b.takeDamage(10);
    b.beRepaired(5);
    b.highFivesGuys();
    std::cout << "------------------------------------------------\n";
}