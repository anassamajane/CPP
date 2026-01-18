#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "\n============================\n" << std::endl;
    {
        Animal* animals[6];

        for (int i = 0; i < 3; i++)
            animals[i] = new Cat();
        for (int i = 3; i < 6; i++)
            animals[i] = new Dog();

        for (int i = 0; i < 6; i++)
            animals[i]->makeSound();

        for (int i = 0; i < 6; i++)
            delete animals[i];
    }

    std::cout << "\n============================\n" << std::endl;
    {
        Dog dog1;
        dog1.getBrain()->setIdea(0, "I love cats");

        Dog dog2(dog1);
        dog2.getBrain()->setIdea(0, "I hate cats");

        std::cout << "Dog1 idea: " << dog1.getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog2 idea: " << dog2.getBrain()->getIdea(0) << std::endl;

        std::cout << "Dog1 brain: " << dog1.getBrain() << std::endl;
        std::cout << "Dog2 brain: " << dog2.getBrain() << std::endl;
    }
    return 0;
}
