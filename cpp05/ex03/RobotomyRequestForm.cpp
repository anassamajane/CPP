#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::executeAction() const
{
    const std::string RESET = "\033[0m";
    const std::string RED   = "\033[31m";
    const std::string GREEN = "\033[32m";

    std::cout << "* DRILLING NOISES *\n";
    static bool seeded = false;
    if (!seeded)
    {
        std::srand(std::time(NULL));
        seeded = true;
    }
    if (std::rand() % 2)
        std::cout << GREEN << target << " has been robotomized successfully!\n" << RESET;
    else
        std::cout << RED << "Robotomy failed on " << target << "...\n" << RESET;
}