#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        std::cout << "\033[32m" << "\n========== BUREAUCRATS ==========\n\n" << "\033[0m";
        Bureaucrat boss("The Big Boss", 1);
        Bureaucrat intern("Sad Intern", 150);
        Bureaucrat middleMan("Middle Manager", 40);

        std::cout << boss << "\n";
        std::cout << intern << "\n";
        std::cout << middleMan << "\n\n\n";

        std::cout << "\033[32m" << "\n========== FORMS ==========\n\n" << "\033[0m";
        ShrubberyCreationForm shrub("Garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("Enemy");

        std::cout << shrub << "\n";
        std::cout << robot << "\n";
        std::cout << pardon << "\n\n\n";

        std::cout << "\033[32m" << "\n========== TESTING SHRUBBERY ==========\n\n" << "\033[0m";
        intern.executeForm(shrub);
        boss.signForm(shrub);
        intern.executeForm(shrub);
        middleMan.executeForm(shrub);
        std::cout << "\n\n";

        std::cout << "\033[32m" << "\n========== TESTING ROBOTOMY ==========\n\n" << "\033[0m";
        middleMan.signForm(robot);
        middleMan.executeForm(robot); 
        boss.executeForm(robot);
        std::cout << "\n\n";


        std::cout << "\033[32m" << "\n========== TESTING PARDON  ==========\n\n" << "\033[0m";
        middleMan.signForm(pardon);
        boss.signForm(pardon);
        middleMan.executeForm(pardon);
        boss.executeForm(pardon);
        std::cout << "\n\n";
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    return 0;
}
