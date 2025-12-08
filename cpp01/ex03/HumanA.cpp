#include "HumanA.hpp"

HumanA::HumanA(std::string n, Weapon &wp) : name(n), weapon(wp) {}

void HumanA::attack() {
    std::cout << name << " attacks with their " << weapon.getType() << "\n";
}
