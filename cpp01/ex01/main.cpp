#include "Zombie.hpp"

int main()
{
	int nbr = 5;
	Zombie *zombie = zombieHorde(nbr, "anass");
	for (int i = 0; i < nbr; i++) {
		zombie[i].announce();
	}
	delete[] zombie;
	return (0);
}
