#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog copy constructor called\n";
    brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Woof!\n";
}

Brain *Dog::getBrain() const
{
    return brain;
}