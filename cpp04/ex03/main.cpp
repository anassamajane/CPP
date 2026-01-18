#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main()
{
    {
        std::cout << "----- The Main TEST -----\n" << std::endl;
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }

    {
        std::cout << "\n----- Memory TEST -----\n" << std::endl;

        IMateriaSource* s = new MateriaSource();
        s->learnMateria(new Ice());
        s->learnMateria(new Cure());
        s->learnMateria(new Ice());
        s->learnMateria(new Cure());
        s->learnMateria(new Ice());
        s->learnMateria(new Cure());

        std::cout << "This test is only to check that the memory is freed and everything is okay." << std::endl;
        delete s;        
    }

    {
        std::cout << "\n----- Equip && Unequip TEST -----\n" << std::endl;
        IMateriaSource *src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());

        ICharacter* me = new Character("me");
        AMateria* m1;
        m1 = src->createMateria("ice");
        me->equip(m1);
        AMateria* m2;
        m2 = src->createMateria("cure");
        me->equip(m2);
        ICharacter* attacker = new Character("attacker");
        me->use(0, *attacker);
        me->use(1, *me);

        AMateria* backup[2];
        backup[0] = m1;
        backup[1] = m2;
        me->unequip(0);
        me->unequip(1);

        delete backup[0];
        delete backup[1];

        delete attacker;
        delete me;
        delete src;
    }
}