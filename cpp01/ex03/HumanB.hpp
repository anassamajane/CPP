#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
private:
        std::string name;
        Weapon *weapon;
public:
        HumanB(std::string n);
        void setWeapon(Weapon &wp);
        void attack();
};

#endif