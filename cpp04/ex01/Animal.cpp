#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called\n";
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound\n";
}