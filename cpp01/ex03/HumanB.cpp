#include "HumanB.hpp"

HumanB::HumanB(std::string n) : name(n), weapon(NULL) {}

void HumanB::setWeapon(Weapon &wp) {
    weapon = &wp;
}

void HumanB::attack() {
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << "\n";
    else
        std::cout << name << " has no weapon to attack" << "\n";
}