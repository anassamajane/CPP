#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "\n========== INTERN CREATES FORMS ==========\n\n";
    Intern      intern;
    Bureaucrat  boss("Boss", 1);

    AForm *f1 = intern.makeForm("shrubbery creation", "Home");
    AForm *f2 = intern.makeForm("robotomy request", "Bender");
    AForm *f3 = intern.makeForm("presidential pardon", "Arthur");

    std::cout << "\n========== USING CREATED FORMS ==========\n\n";
    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
    }
    std::cout << "\n\n";
    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
    }
    std::cout << "\n\n";
    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
    }

    std::cout << "\n========== INVALID FORM ==========\n\n";
    AForm *bad = intern.makeForm("unknown form", "Nowhere");

    if (bad)
        boss.signForm(*bad);

    delete f1;
    delete f2;
    delete f3;
    return 0;
}
