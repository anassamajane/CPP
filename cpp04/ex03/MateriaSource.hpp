#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *materias[4];
    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);
        ~MateriaSource();

        void learnMateria(AMateria *m);
        AMateria *createMateria(std::string const &type);
};

#endif