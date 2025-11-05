#include "Zombie.hpp"

Zombie::Zombie() {};

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed" << std::endl;
}

void Zombie::setName(std::string n) {
	name = n;
}
