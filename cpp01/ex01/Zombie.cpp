#include "Zombie.hpp"

Zombie::Zombie() {};

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed\n";
}

void Zombie::setName(std::string n) {
	name = n;
}
