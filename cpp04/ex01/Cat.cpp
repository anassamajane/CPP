#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat copy constructor called\n";
    brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow!\n";
}

Brain *Cat::getBrain() const
{
    return brain;
}