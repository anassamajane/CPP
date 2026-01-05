#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "===== Basic creation & deletion =====\n" << std::endl;
    {
        const Animal* i = new Cat();
        const Animal* j = new Dog();

        i->makeSound();
        j->makeSound();

        delete i;
        delete j;
    }
    std::cout << "\n===== COPY CONSTRUCTOR TEST =====\n" << std::endl;
    {
        Dog dog1;
        Dog dog2(dog1);
    }
    std::cout << "\n===== COPY ASSIGNMENT TEST =====\n" << std::endl;
    {
        Cat cat1;
        Cat cat2;

        cat2 = cat1;
    }
    std::cout << "\n===== POLYMORPHISM =====\n" << std::endl;
    {
        Animal* animals[6];

        for (int i = 0; i < 3; i++)
        {
            animals[i] = new Cat();
        }
        for (int i = 3; i < 6; i++)
        {
            animals[i] = new Dog();
        }
        for (int i = 0; i < 6; i++)
        {
            animals[i]->makeSound();
        }
        for (int i = 0; i < 6; i++)
        {
            delete animals[i];
        }
    }
    std::cout << "\n===== DEEP COPY =====\n" << std::endl;
    {
        Dog dog69;
        dog69.getBrain()->setIdea(0,"I love cats");
        std::cout << dog69.getBrain()->getIdea(0) << std::endl;
        std::cout << "dog69 Brain address: " << dog69.getBrain() << std::endl;



        Dog dog1337(dog69);
        std::cout << "dog1337 Brain address: " << dog1337.getBrain() << std::endl;
        dog1337.getBrain()->setIdea(0,"I hate cats"); //-> because ptr is pointer (Brain *ptr)


        std::cout << "Dog1 idea: " << dog69.getBrain()->getIdea(0) << std::endl;
        std::cout << "Dog2 idea: " << dog1337.getBrain()->getIdea(0) << std::endl;
    }
}
