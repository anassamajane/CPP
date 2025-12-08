#include "Zombie.hpp"

Zombie::Zombie(std::string n) {
	name = n;
}

void Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::~Zombie() {
	std::cout << name << " is destroyed\n";
}
